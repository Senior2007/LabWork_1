#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include <QPoint>

class Polygon : public Shape {
public:
    Polygon();
    void draw(QPainter& painter) const override;
};

#endif // POLYGON_H
