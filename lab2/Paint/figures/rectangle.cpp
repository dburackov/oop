#include "rectangle.h"

#include <QPen>

Rectangle::Rectangle()
{

}


QRectF Rectangle::boundingRect() const
{
    return QRectF(points[0], points[1]);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QBrush(penColor), width));
    painter->setBrush(QBrush(fillColor));
    painter->drawRect(boundingRect());
}


