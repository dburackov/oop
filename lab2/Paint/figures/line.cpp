#include "line.h"

#include <QPen>

Line::Line()
{

}


QRectF Line::boundingRect() const
{
    return QRectF(points[0], points[1]);
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QBrush(penColor), width));
    painter->drawLine(points[0], points[1]);
    setBoundingRegionGranularity(1);
}
