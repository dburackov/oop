#include "ellipsiscreator.h"

EllipsisCreator::EllipsisCreator()
{
    Figure *tmp = new Ellipsis();
    figureType = tmp->type;
    delete tmp;
}

Figure *EllipsisCreator::create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width)
{
    Figure* result = new Ellipsis();
    result->points = points;
    result->penColor = penColor;
    result->fillColor = fillColor;
    result->width = width;
    return result;
}
