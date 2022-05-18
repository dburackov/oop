#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

namespace Figures {
    class Rectangle;
}

class Rectangle : public Figure
{
public:
    Rectangle();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RECTANGLE_H
