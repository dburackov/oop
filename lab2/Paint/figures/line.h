#ifndef LINE_H
#define LINE_H

#include "figure.h"
namespace Figures {
    class Line;
}

class Line : public Figure
{
public:
    Line();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // LINE_H
