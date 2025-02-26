#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"
#include <QPoint>

class Triangle : public Polygon {
public:
    Triangle(const QPoint& start, const QPoint& end, const QPoint& middle);
    void draw(QPainter& painter, const Shape* selectedShape) const override;

private:
    QPoint m_start;
    QPoint m_end;
    QPoint m_middle;
};

#endif // TRIANGLE_H
