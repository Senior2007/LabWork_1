#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <QPoint>

class Triangle : public Shape {
public:
    Triangle(const QPoint& start, const QPoint& end, const QPoint& middle);
    void draw(QPainter& painter) const override;

private:
    QPoint m_start;
    QPoint m_end;
    QPoint m_middle;
};

#endif // TRIANGLE_H
