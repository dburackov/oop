#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "figures/figure.h"

class Serializer
{
public:
    Serializer() = delete;
    static void serialize(QString fileName, const std::vector<Figure*> &figures);
};

#endif // SERIALIZER_H
