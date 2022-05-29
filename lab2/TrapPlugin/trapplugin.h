#ifndef TRAPPLUGIN_H
#define TRAPPLUGIN_H

#include "TrapPlugin_global.h"
#include "trapezoid.h"
#include "../Paint/creators/creator.h"

class TRAPPLUGIN_EXPORT TrapPlugin : public Creator
{
    Q_OBJECT
    Q_INTERFACES(Creator)
    Q_PLUGIN_METADATA(IID "com.mysoft.Application.creator" FILE "creator.json")

public:
    TrapPlugin();

    Figure *create(std::vector<QPointF> points, QColor penColor, QColor fillColor, int width) override;
};

#endif // TRAPPLUGIN_H
