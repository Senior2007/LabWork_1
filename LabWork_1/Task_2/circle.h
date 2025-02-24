#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
    Q_OBJECT

public:
    explicit Circle(QWidget* parent = nullptr);

    void startDrawing(const QPoint& position) override;
    void updateShape(const QPoint& position) override;
    void paint(QPainter& painter) const override;

private:
    QPoint center;
    QPoint currentPos;
    bool isDrawing = false;
};

#endif // CIRCLE_H
