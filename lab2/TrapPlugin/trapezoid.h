#ifndef TRAPEZOID_H
#define TRAPEZOID_H


#include "../Paint/figures/figure.h"


namespace Figures {
    class Trapezoid;
}


class Trapezoid : public Figure
{
public:
    Trapezoid();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};

#endif // TRAPEZOID_H
