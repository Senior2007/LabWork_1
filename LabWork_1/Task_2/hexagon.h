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
    void updatePos(QPoint diff) override;
    void scale(double scalefactor) override;
    void showInformation(QPainter& painter, int height) override;

private:
    double m_radius;
};

#endif // HEXAGON_H
