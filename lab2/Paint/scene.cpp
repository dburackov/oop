#include "scene.h"

#include <QDebug>

#include <QGraphicsSceneMouseEvent>

#include "creators/linecreator.h"
#include "creators/ellipsiscreator.h"
#include "creators/polygoncreator.h"
#include "creators/polylinecreator.h"
#include "creators/rectanglecreator.h"


Scene::Scene(QObject *parant) : QGraphicsScene(parant)
{
    penSize = 3;
    secondClick = false;

    factory = new Factory();

    tempFigure = nullptr;
    activeFigure = nullptr;

    copy = false;

    figureType = "Line";

    loadFigure(new LineCreator());
    loadFigure(new EllipsisCreator());
    loadFigure(new PolygonCreator());
    loadFigure(new PolylineCreator());
    loadFigure(new RectangleCreator());
}


Scene::~Scene()
{
    delete tempFigure;
    delete activeFigure;
    delete factory;
    for (int i = 0; i < figures.size(); ++i) {
        delete figures[i];
    }
    for (int i = 0; i < deletedFigures.size(); ++i) {
        delete deletedFigures[i];
    }
}


void Scene::setActiveItem(int index)
{
    if (activeFigure != nullptr) {
        activeFigure->setOpacity(1);
    }
    if (index == 0) {
        activeFigure = nullptr;
    } else {
        --index;
        activeFigure = figures[index];
        activeFigure->setOpacity(0.3);
    }
    update();
}


void Scene::copyCommand() {
    copy = !copy;
    if (copy) {
        if (activeFigure == nullptr) {
            copy = false;
        } else {
            secondClick = false;
            removeItem(tempFigure);
            delete tempFigure;
            tempFigure = factory->createFigure(activeFigure->type, activeFigure->points,
                                               activeFigure->penColor, activeFigure->fillColor, activeFigure->width);
            addItem(tempFigure);
        }
    }
}

void Scene::save(QString fileName)
{
    Serializer::serialize(fileName, figures);
}


void Scene::open(QString fileName)
{
    for (int i = 0; i < figures.size(); ++i) {
        removeItem(figures[i]);
        emit removeFigureSignal();
        delete figures[i];
    }
    for (int i = 0; i < deletedFigures.size(); ++i) {
        delete deletedFigures[i];
    }
    figures.clear();
    deletedFigures.clear();

    if (tempFigure != nullptr) {
        removeItem(tempFigure);
        delete tempFigure;
        tempFigure = nullptr;
    }

    activeFigure = nullptr;

    Deserializer::deserialize(fileName, figures, factory);

    for (int i = 0; i < figures.size(); ++i) {
        addItem(figures[i]);
        emit addNewFigureSignal();
    }
    update();
}

void Scene::setFigureType(QString value)
{
    figureType = value;
}

void Scene::loadFigure(Creator *creator)
{
    //QString str = creator->figureType;
    //figcombox->addItem(str);
    factory->addCreator(creator);
}


void Scene::undo()
{
    if (!figures.empty()) {
        removeItem(figures.back());
        deletedFigures.push_back(figures.back());
        figures.pop_back();
        emit removeFigureSignal();
        update();
    }
}


void Scene::redo()
{
    if (!deletedFigures.empty()) {
        addItem(deletedFigures.back());
        figures.push_back(deletedFigures.back());
        deletedFigures.pop_back();
        emit addNewFigureSignal();
        update();
    }
}


void Scene::deleteFigure()
{
    if (activeFigure != nullptr) {
        removeItem(activeFigure);
        activeFigure->setOpacity(1);
        deletedFigures.push_back(activeFigure);
        for (int i = 0; i < figures.size(); ++i) {
            if (figures[i] == activeFigure) {
                figures.erase(figures.begin() + i);
                break;
            }
        }
        activeFigure = nullptr;
        emit removeFigureSignal();
        update();
    }
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (copy) {
        if (event->button() == Qt::LeftButton) {
            copy = false;
            figures.push_back(tempFigure);
            tempFigure = nullptr;

            for (int i = 0; i < deletedFigures.size(); ++i) {
                delete deletedFigures[i];
            }
            deletedFigures.clear();
            emit addNewFigureSignal();
        } else if (event->button() == Qt::RightButton) {
            removeItem(tempFigure);
            delete tempFigure;
            tempFigure = nullptr;
        }
        update();
        return;
    }

    if (figureType == "Polyline" || figureType == "Polygon") {
        if (event->button() == Qt::LeftButton) {
            if (secondClick) {

                tempFigure->points.back() = event->scenePos();
                tempFigure->points.push_back(event->scenePos());

            } else {
                secondClick = true;

                tempFigure = factory->createFigure(figureType, {event->scenePos(), event->scenePos()}, penColor, fillColor, penSize);
                addItem(tempFigure);
            }
        } else if (event->button() == Qt::RightButton) {
            secondClick = false;

            tempFigure->points.pop_back();

            if (tempFigure->points.size() > 1) {
                figures.push_back(tempFigure);
                for (int i = 0; i < deletedFigures.size(); ++i) {
                    delete deletedFigures[i];
                }
                deletedFigures.clear();
                emit addNewFigureSignal();
            } else {
                removeItem(tempFigure);
                delete tempFigure;
            }

            tempFigure = nullptr;
        }
        update();
        return;
    }


    if (event->button() == Qt::LeftButton) {
        if (secondClick) {
            secondClick = false;
            figures.push_back(tempFigure);

            tempFigure = nullptr;

            for (int i = 0; i < deletedFigures.size(); ++i) {
                delete deletedFigures[i];
            }
            deletedFigures.clear();
            emit addNewFigureSignal();
        } else {
            previousPoint = event->scenePos();
            secondClick = true;

            tempFigure = factory->createFigure(figureType, {previousPoint, event->scenePos()}, penColor, fillColor, penSize);
            addItem(tempFigure);
        }

    }

    if (event->button() == Qt::RightButton) {
        if (secondClick) {
            secondClick = false;
            removeItem(tempFigure);
            delete tempFigure;
            tempFigure = nullptr;
        }
    }
    update();
}



void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (copy) {
        QPointF shift = QPointF(activeFigure->points.back().x() - event->scenePos().x(), activeFigure->points.back().y() - event->scenePos().y());
        for (int i = 0; i < tempFigure->points.size(); ++i) {
            tempFigure->points[i] = QPointF(activeFigure->points[i].x() - shift.x(), activeFigure->points[i].y() - shift.y());
        }
        update();
        return;
    }

    if (figureType == "Polyline" || figureType == "Polygon") {
        if (secondClick) {
            tempFigure->points.back() = event->scenePos();
        }
        update();
        return;
    }

    if (secondClick) {
        tempFigure->points[1] = event->scenePos();
        update();
        return;
    }
}

