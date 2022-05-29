#include "rectanglecreator.h"

RectangleCreator::RectangleCreator()
{
    Figure *tmp = new Rectangle();
    figureType = tmp->type;
    delete tmp;
}

Figure *RectangleCreator::create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width)
{
    Figure* result = new Rectangle();
    result->points = points;
    result->penColor = penColor;
    result->fillColor = fillColor;
    result->width = width;
    return result;
}
