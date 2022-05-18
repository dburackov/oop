#ifndef POLYLINE_H
#define POLYLINE_H

#include "figure.h"

namespace Figures {
    class PolyLine;
}


class Polyline : public Figure
{
public:
    Polyline();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // POLYLINE_H
