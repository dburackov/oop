#ifndef LINECREATOR_H
#define LINECREATOR_H

#include "creator.h"
#include "../figures/line.h"

class LineCreator : public Creator
{
public:
    LineCreator();

    Figure *create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width) override;
};

#endif // LINECREATOR_H
