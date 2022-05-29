#include "trapplugin.h"

TrapPlugin::TrapPlugin()
{
    Figure *tmp = new Trapezoid();
    figureType = tmp->type;
    delete tmp;
}

Figure *TrapPlugin::create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width)
{
    Figure* result = new Trapezoid();
    result->points = points;
    result->penColor = penColor;
    result->fillColor = fillColor;
    result->width = width;
    return result;
}
