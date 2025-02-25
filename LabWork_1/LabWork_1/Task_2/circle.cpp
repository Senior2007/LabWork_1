#include "circle.h"
#include <QPainter>

Circle::Circle(const QPoint& center, int radius)
    : m_center(center), m_radius(radius) {}

void Circle::draw(QPainter& painter) const {
    painter.setPen(Qt::black);
    painter.setBrush(Qt::blue);
    painter.drawEllipse(m_center, m_radius, m_radius);
}
