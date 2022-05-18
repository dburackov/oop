#include "ellipsis.h"

#include <QPen>



Ellipsis::Ellipsis() : Figure()
{

}

QRectF Ellipsis::boundingRect() const
{
    return QRectF(points[0], points[1]);
}

void Ellipsis::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QBrush(penColor), width));
    painter->setBrush(QBrush(fillColor));
    painter->drawEllipse(boundingRect());
}
