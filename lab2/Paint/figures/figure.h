#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

enum FigureType {
    line = 0,
    rectangle = 1,
    ellipsis = 2,
    polygon = 3,
    polyline = 4
};

class Figure : public QGraphicsItem
{
public:
    Figure();

    FigureType type;
    std::vector<QPointF> points;
    QColor penColor;
    QColor fillColor;
    int width;

protected:

};

#endif // FIGURE_H
