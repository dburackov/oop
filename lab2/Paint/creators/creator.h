#ifndef CREATOR_H
#define CREATOR_H

#include "../figures/figure.h"

#include <QObject>

class Creator : public QObject
{
public:

    virtual Figure *create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width) = 0;

    QString figureType;
};


Q_DECLARE_INTERFACE(Creator, "com.mysoft.Application.creator")


#endif // CREATOR_H
