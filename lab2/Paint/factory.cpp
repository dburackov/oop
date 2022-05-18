#include "factory.h"

#include <QDebug>

Factory::Factory()
{

}


Figure *Factory::createFigure(FigureType type, std::vector<QPointF> points, QColor penColor, QColor fillColor, int width)
{
    Figure* result = nullptr;

    switch (type) {
    case line: {
        result = new Line();
        break;
    }
    case rectangle: {
        result = new Rectangle();
        break;
    }
    case ellipsis: {
        result = new Ellipsis();
        break;
    }
    case polygon: {
        result = new Polygon();
        break;
    }
    case polyline: {
        result = new Polyline();
        break;
    }
    default:
        break;
    }

    result->points = points;
    result->penColor = penColor;
    result->fillColor = fillColor;
    result->width = width;
    result->type = type;

    return result;
}
