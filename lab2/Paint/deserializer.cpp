#include "deserializer.h"


#include <QFile>
#include <QDataStream>


void Deserializer::deserialize(QString fileName, std::vector<Figure *> &figures, Factory *factory)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    int figuresNumber;
    in >> figuresNumber;

    for (int i = 0; i < figuresNumber; ++i) {
        int pointsNumber;
        in >> pointsNumber;

        std::vector<QPointF> p;
        for (int j = 0; j < pointsNumber; ++j) {
            double x;
            double y;
            in >> x >> y;
            p.push_back(QPointF(x, y));
        }

        QString type;
        in >> type;

        QColor penColor;
        in >> penColor;

        QColor fillColor;
        in >> fillColor;

        int width;
        in >> width;

        Figure *figure = factory->createFigure(type, p, penColor, fillColor, width);

        if (figure != nullptr) {
            figures.push_back(figure);
        }
    }
}
