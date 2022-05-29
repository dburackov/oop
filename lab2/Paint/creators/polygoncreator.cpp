#include "polygoncreator.h"

PolygonCreator::PolygonCreator()
{
    Figure *tmp = new Polygon();
    figureType = tmp->type;
    delete tmp;
}

Figure *PolygonCreator::create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width)
{
    Figure* result = new Polygon();
    result->points = points;
    result->penColor = penColor;
    result->fillColor = fillColor;
    result->width = width;
    return result;
}
