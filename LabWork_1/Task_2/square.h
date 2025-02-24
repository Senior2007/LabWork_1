#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"
#include <QPoint>

class Square : public Shape {
public:
    Square(const QPoint& start, const QPoint& end);
    void draw(QPainter& painter) const override;

private:
    QPoint m_start; // Левый верхний угол
    QPoint m_end;   // Правый нижний угол
};

#endif // SQUARE_H
