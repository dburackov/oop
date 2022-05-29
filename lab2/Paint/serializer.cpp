#include "serializer.h"


#include <QFile>
#include <QDataStream>

void Serializer::serialize(QString fileName, const std::vector<Figure *> &figures)
{
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    out << (qint32)figures.size();
    for (int i = 0; i < figures.size(); ++i) {
        out << (qint32)figures[i]->points.size();
        for (int j = 0; j < figures[i]->points.size(); ++j) {
            out << (double)figures[i]->points[j].x();
            out << (double)figures[i]->points[j].y();
        }
        out << QString(figures[i]->type);
        out << (QColor)figures[i]->penColor;
        out << (QColor)figures[i]->fillColor;
        out << (qint32)figures[i]->width;
    }
}
