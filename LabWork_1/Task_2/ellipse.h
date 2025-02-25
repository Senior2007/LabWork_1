#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"
#include <QPoint>

class Ellipse : public Shape {
public:
    Ellipse(const QPoint& center, int radiusX, int radiusY);
    void draw(QPainter& painter) const override;

private:
    QPoint m_center;
    int m_radiusX;
    int m_radiusY;
};

#endif // ELLIPSE_H
