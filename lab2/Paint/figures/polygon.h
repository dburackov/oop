#ifndef POLYGON_H
#define POLYGON_H

#include "figure.h"

namespace Figures {
    class Polygon;
}

class Polygon : public Figure
{
public:
    Polygon();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // POLYGON_H
