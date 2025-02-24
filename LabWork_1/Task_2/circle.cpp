#include "circle.h"
#include <QPainter>
#include <cmath>

Circle::Circle(QWidget* parent) : Shape(parent) {}

void Circle::startDrawing(const QPoint& position) {
    center = position;
    currentPos = position;
    isDrawing = true;
}

void Circle::updateShape(const QPoint& position) {
    if (isDrawing) {
        currentPos = position;
        update();
    }
}

void Circle::paint(QPainter& painter) const {
    if (isDrawing) {
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(Qt::black);
        painter.setBrush(Qt::blue);

        int radius = static_cast<int>(sqrt(pow(currentPos.x() - center.x(), 2) + pow(currentPos.y() - center.y(), 2)));

        painter.drawEllipse(center, radius, radius);
    }
}
