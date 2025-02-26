#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygon.h"
#include <QPoint>

class Rectangle : public Polygon {
public:
    Rectangle(const QPoint& start, const QPoint& end);
    void draw(QPainter& painter, const Shape* selectedShape) const override;

private:
    QPoint m_start;
    QPoint m_end;
};

#endif // RECTANGLE_H
