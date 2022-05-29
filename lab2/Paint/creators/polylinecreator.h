#ifndef POLYLINECREATOR_H
#define POLYLINECREATOR_H

#include "creator.h"
#include "../figures/Polyline.h"

class PolylineCreator : public Creator
{
public:
    PolylineCreator();

    Figure *create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width) override;
};

#endif // POLYLINECREATOR_H
