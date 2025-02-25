#ifndef STAR_H
#define STAR_H

#include "polygon.h"
#include <QPoint>
#include <QVector>

class Stars : public Polygon {
public:
    Stars(const QPoint& center, int outerRadius, int innerRadius, int numPoints);
    void draw(QPainter& painter) const override;
    QVector<QPoint> calculateVertices() const;

private:
    QPoint m_center;
    int m_outerRadius;
    int m_innerRadius;
    int m_numPoints;
};

#endif // STAR_H
