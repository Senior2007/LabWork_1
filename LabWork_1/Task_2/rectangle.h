#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <QPoint>

class Rectangle : public Shape {
public:
    Rectangle(const QPoint& start, const QPoint& end);
    void draw(QPainter& painter) const override;

private:
    QPoint m_start;
    QPoint m_end;
};

#endif // RECTANGLE_H
