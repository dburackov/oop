#ifndef POLYGONCREATOR_H
#define POLYGONCREATOR_H

#include "creator.h"
#include "../figures/polygon.h"

class PolygonCreator : public Creator
{
public:
    PolygonCreator();

    Figure *create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width) override;
};

#endif // POLYGONCREATOR_H
