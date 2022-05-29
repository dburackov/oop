#ifndef ELLIPSISCREATOR_H
#define ELLIPSISCREATOR_H

#include "creator.h"
#include "../figures/ellipsis.h"

class EllipsisCreator : public Creator
{
public:
    EllipsisCreator();

    Figure *create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width) override;
};

#endif // ELLIPSISCREATOR_H
