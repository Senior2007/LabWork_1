#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"
#include <QPoint>

class Ellipse : public Shape {
public:
    Ellipse(const QPoint& center, int radiusX, int radiusY);
    void draw(QPainter& painter, const Shape* selectedShape) const override;
    bool contains(const QPoint& point) const override;
    void updatePos(QPoint diff) override;

private:
    QPoint m_center;
    int m_radiusX;
    int m_radiusY;
};

#endif // ELLIPSE_H
