#ifndef ELLIPSIS_H
#define ELLIPSIS_H

#include "figure.h"

namespace Figures {
    class Ellipsis;
}

class Ellipsis : public Figure
{
public:
    Ellipsis();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ELLIPSIS_H
