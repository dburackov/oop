#include "id.h"

#include <QFile>
#include <fstream>

Id::Id()
{

}

long long Id::index = 0;

long long Id::getNewId()
{
    long long result = index;
    ++index;
    return result;
}

void Id::setId(long long value) {
    index = std::max(index, value + 1);
}
