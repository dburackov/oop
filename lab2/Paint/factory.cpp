#include "factory.h"


#include <QDebug>


Factory::Factory()
{

}


Figure *Factory::createFigure(QString figureType, std::vector<QPointF> points, QColor penColor, QColor fillColor, int width)
{
    Figure *result = nullptr;
    for (int i = 0; i < creators.size(); ++i) {
        if (figureType == creators[i]->figureType) {
            result = creators[i]->create(points, penColor, fillColor, width);
            break;
        }
    }
    return result;
}


void Factory::addCreator(Creator *creator)
{
    creators.push_back(creator);
}
