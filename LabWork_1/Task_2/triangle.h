#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"
#include <QPoint>

class Triangle : public Polygon {
public:
    Triangle(const QPoint& start, const QPoint& end, const QPoint& middle);
    void draw(QPainter& painter, const Shape* selectedShape) const override;
    void updatePos(QPoint diff) override;
    void scale(double scalefactor) override;
    void showInformation(QPainter& painter, int height) override;

private:
    QPoint m_start;
    QPoint m_end;
    QPoint m_middle;
};

#endif // TRIANGLE_H
