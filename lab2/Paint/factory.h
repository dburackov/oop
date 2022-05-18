#ifndef FACTORY_H
#define FACTORY_H

#include "figures/ellipsis.h"
#include "figures/line.h"
#include "figures/polygon.h"
#include "figures/rectangle.h"
#include "figures/Polyline.h"

class Factory
{
public:
    Factory();
    Figure *createFigure(FigureType type, std::vector<QPointF> points, QColor penColor, QColor fillColor, int width);

};

#endif // FACTORY_H
