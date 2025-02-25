#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include <QPoint>
#include <QVector>

class Polygon : public Shape {
public:
    Polygon();
    void draw(QPainter& painter) const override;

protected:
    QVector<QPoint> vertices;
};

#endif // POLYGON_H
