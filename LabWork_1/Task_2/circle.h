#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
public:
    Circle(const QPoint& center, int radius);
    void draw(QPainter& painter) const override;

private:
    QPoint m_center;
    int m_radius;
};

#endif // CIRCLE_H
