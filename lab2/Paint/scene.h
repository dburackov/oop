#ifndef SCENE_H
#define SCENE_H

#include "factory.h"
#include "serializer.h"
#include "deserializer.h"


#include <vector>
#include <QGraphicsScene>
#include <QComboBox>


class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Scene(QObject *parant = nullptr);
    ~Scene();

    void undo();
    void redo();
    void deleteFigure();
    void setActiveItem(int index);
    void copyCommand();
    void save(QString fileName);
    void open(QString fileName);
    void setFigureType(QString value);
    void loadFigure(Creator *creator);

    int penSize;
    QColor penColor;
    QColor fillColor;

signals:
    void addNewFigureSignal();
    void removeFigureSignal();

private:
    bool copy;
    QString figureType;

    QPointF previousPoint;
    bool secondClick;
    Factory *factory;

    std::vector<Figure*> figures;
    std::vector<Figure*> deletedFigures;
    Figure *tempFigure;
    Figure *activeFigure;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
