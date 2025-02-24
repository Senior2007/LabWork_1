#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QPoint>

class Shape {
public:
    Shape() noexcept = default;       // Явное объявление с noexcept
    virtual ~Shape() = default;

    virtual void draw(QPainter& painter) const = 0;
};

#endif // SHAPE_H
