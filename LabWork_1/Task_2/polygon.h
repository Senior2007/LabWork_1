#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include <QPoint>
#include <QVector>

class Polygon : public Shape {
public:
    Polygon(QPoint center);
    void draw(QPainter& painter, const Shape* selectedShape) const override;
    bool contains(const QPoint& point) const override;
    void updatePos(QPoint diff) override;
    void scale(double scalefactor) override;
    void showInformation(QPainter& painter, int height) override;

protected:
    QVector<QPoint> vertices;
    QPoint m_center;
};

#endif // POLYGON_H
