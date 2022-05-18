#ifndef SCENE_H
#define SCENE_H

#include "factory.h"

#include <vector>
#include <QGraphicsScene>
#include <QComboBox>


class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Scene(QObject *parant = nullptr);
    ~Scene();

    void undo();
    void redo();
    void deleteFigure();
    void setActiveItem(int index);
    void copyCommand();


    FigureType figureType;
    int penSize;
    QColor penColor;
    QColor fillColor;

    bool copy;
    bool selected;

signals:
    void addNewFigureSignal();
    void removeFigureSignel();

private:
    QPointF previousPoint;
    bool secondClick;
    Factory *factory;

    std::vector<QPointF> points;
    std::vector<Figure*> figures;
    std::vector<Figure*> deletedFigures;
    Figure *tempFigure;
    Figure *activeFigure;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
