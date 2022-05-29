#ifndef FACTORY_H
#define FACTORY_H

#include "creators/creator.h"


class Factory
{
public:
    Factory();

    Figure *createFigure(QString figureType, std::vector<QPointF> points, QColor penColor, QColor fillColor, int width);

    void addCreator(Creator *creator);

private:
    std::vector<Creator *> creators;

};

#endif // FACTORY_H
