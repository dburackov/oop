#ifndef RECTANGLECREATOR_H
#define RECTANGLECREATOR_H

#include "creator.h"
#include "../figures/rectangle.h"

class RectangleCreator : public Creator
{
public:
    RectangleCreator();

    Figure *create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width) override;
};

#endif // RECTANGLECREATOR_H
