#ifndef STAR_H
#define STAR_H

#include "polygon.h"
#include <QPoint>
#include <QVector>

class Stars : public Polygon {
public:
    Stars(const QPoint& center, int outerRadius, int innerRadius, int numPoints);
    void draw(QPainter& painter, const Shape* selectedShape) const override;
    QVector<QPoint> calculateVertices() const;
    void updatePos(QPoint diff) override;
    double rastq(double x1, double x2, double y1, double y2);
    double STriangle(QPoint p1, QPoint p2, QPoint p3);
    void scale(double scalefactor) override;
    void showInformation(QPainter& painter, int height) override;

private:
    int m_outerRadius;
    int m_innerRadius;
    int m_numPoints;
};

#endif // STAR_H
