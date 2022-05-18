#include "scene.h"

#include <QDebug>

Scene::Scene(QObject *parant) : QGraphicsScene(parant)
{
    penSize = 3;
    secondClick = false;

    factory = new Factory();

    tempFigure = nullptr;
    activeFigure = nullptr;

    copy = false;
    selected = false;
}


Scene::~Scene()
{
    delete tempFigure;
    delete activeFigure;
    delete factory;
    for (size_t i = 0; i < figures.size(); ++i) {
        delete figures[i];
    }
    for (size_t i = 0; i < deletedFigures.size(); ++i) {
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
            removeItem(tempFigure);
            delete tempFigure;
            tempFigure = factory->createFigure(activeFigure->type, activeFigure->points,
                                               activeFigure->penColor, activeFigure->fillColor, activeFigure->width);
            addItem(tempFigure);
        }
    }
}


void Scene::undo()
{
    if (!figures.empty()) {
        removeItem(figures.back());
        deletedFigures.push_back(figures.back());
        figures.pop_back();
        emit removeFigureSignel();
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
        activeFigure->setOpacity(1);//?????
        deletedFigures.push_back(activeFigure);
        for (size_t i = 0; i < figures.size(); ++i) {
            if (figures[i] == activeFigure) {
                figures.erase(figures.begin() + i);
                break;
            }
        }
        activeFigure = nullptr;
        emit removeFigureSignel();
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

            for (size_t i = 0; i < deletedFigures.size(); ++i) {
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

    if (figureType == polyline || figureType == polygon) {
        if (event->button() == Qt::LeftButton) {
            if (secondClick) {

                tempFigure->points.back() = event->scenePos();
                tempFigure->points.push_back(event->scenePos());

            } else {
                points.push_back(event->scenePos());
                points.push_back(event->scenePos());
                secondClick = true;

                tempFigure = factory->createFigure(figureType, points, penColor, fillColor, penSize);
                addItem(tempFigure);
            }
        } else if (event->button() == Qt::RightButton) {
            secondClick = false;

            tempFigure->points.pop_back();

            figures.push_back(tempFigure);
            for (size_t i = 0; i < deletedFigures.size(); ++i) {
                delete deletedFigures[i];
            }
            deletedFigures.clear();
            points.clear();
            emit addNewFigureSignal();

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

            for (size_t i = 0; i < deletedFigures.size(); ++i) {
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
        for (size_t i = 0; i < tempFigure->points.size(); ++i) {
            tempFigure->points[i] = QPointF(activeFigure->points[i].x() - shift.x(), activeFigure->points[i].y() - shift.y());
        }
        update();
        return;
    }

    if (figureType == polyline || figureType == polygon) {
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

