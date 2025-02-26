#ifndef HEXAGON_H
#define HEXAGON_H

#include "polygon.h"
#include <QPoint>
#include <QVector>

class Hexagon : public Polygon {
public:
    Hexagon(const QPoint& center, int radius);
    void draw(QPainter& painter, const Shape* selectedShape) const override;
    QVector<QPoint> calculateVertices() const;

private:
    QPoint m_center;
    int m_radius;
};

#endif // HEXAGON_H
