#include "linecreator.h"

LineCreator::LineCreator()
{
    Figure *tmp = new Line();
    figureType = tmp->type;
    delete tmp;
}

Figure *LineCreator::create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width)
{
    Figure* result = new Line();
    result->points = points;
    result->penColor = penColor;
    result->fillColor = fillColor;
    result->width = width;
    return result;
}
