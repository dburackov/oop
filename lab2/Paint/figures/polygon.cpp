#include "polygon.h"

#include <QPen>


Polygon::Polygon()
{
    type = "Polygon";
}

QRectF Polygon::boundingRect() const
{

}

void Polygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QBrush(penColor), width));
    painter->setBrush(QBrush(fillColor));
    QPointF p[points.size()];
    for (size_t i =0; i < points.size(); ++i) {
        p[i] = points[i];
    }
    painter->drawPolygon(p, points.size());
}
