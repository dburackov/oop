#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>
#include <QGraphicsItem>


class Figure : public QGraphicsItem
{
public:
    //Figure();

    std::vector<QPointF> points;
    QString type;
    QColor penColor;
    QColor fillColor;
    int width;

};

#endif // FIGURE_H
