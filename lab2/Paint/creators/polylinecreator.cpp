#include "polylinecreator.h"

PolylineCreator::PolylineCreator()
{
    Figure *tmp = new Polyline();
    figureType = tmp->type;
    delete tmp;
}

Figure *PolylineCreator::create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width)
{
    Figure* result = new Polyline();
    result->points = points;
    result->penColor = penColor;
    result->fillColor = fillColor;
    result->width = width;
    return result;
}
