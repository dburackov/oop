#ifndef DESERIALIZER_H
#define DESERIALIZER_H

#include "figures/figure.h"
#include "factory.h"

class Deserializer
{
public:
    Deserializer() = delete;
    static void deserialize(QString fileName, std::vector<Figure*> &figures, Factory *factory);
};

#endif // DESERIALIZER_H
