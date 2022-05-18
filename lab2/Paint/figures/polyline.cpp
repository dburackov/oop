#include "Polyline.h"

Polyline::Polyline() : Figure()
{

}

QRectF Polyline::boundingRect() const
{

}

#include <QDebug>

void Polyline::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QBrush(penColor), width));
    QPointF p[points.size()];
    for (size_t i =0; i < points.size(); ++i) {
        p[i] = points[i];
    }
    painter->drawPolyline(p, points.size());
}

