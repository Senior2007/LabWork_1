#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
public:
    Circle(const QPoint& center, int radius);
    void draw(QPainter& painter, const Shape* selectedShape) const override;
    bool contains(const QPoint& point) const override;
    void updatePos(QPoint diff) override;
    void scale(double scalefactor) override;
    void showInformation(QPainter& painter, int height) override;
private:
    QPoint m_center;
    double m_radius;
};

#endif // CIRCLE_H
