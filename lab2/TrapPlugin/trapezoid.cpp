#include "trapezoid.h"

Trapezoid::Trapezoid()
{
    type = "Trapezoid";
}

QRectF Trapezoid::boundingRect() const
{

}

void Trapezoid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QBrush(penColor), width));
    painter->setBrush(QBrush(fillColor));

    //draw
    QPointF upper_point, low_point;
    QPointF right_point, left_point;
    if (points[0].y() > points[1].y()) {
        upper_point = points[0];
        low_point = points[1];
    } else {
        upper_point = points[1];
        low_point = points[0];
    }

    if (points[0].x() > points[1].x()) {
        left_point = points[1];
        right_point = points[0];
    } else {
        left_point = points[0];
        right_point = points[1];
    }



    QPointF point1, point2, point3, point4;

    point1.setX((right_point.x() - left_point.x()) / 4 + left_point.x());
    point2.setX(-(right_point.x() - left_point.x()) / 4 + right_point.x());
    point1.setY(upper_point.y());
    point2.setY(upper_point.y());

    point3.setX(right_point.x());
    point3.setY(low_point.y());
    point4.setX(left_point.x());
    point4.setY(low_point.y());

    //drawend

    QPointF p[4];
    p[0] = point1;
    p[1] = point2;
    p[2] = point3;
    p[3] = point4;

    painter->drawPolygon(p, 4);
}
