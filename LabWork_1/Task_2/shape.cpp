#include "shape.h"

Shape::Shape(QWidget* parent) : QWidget(parent) {}

void Shape::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    paint(painter);
}
