#include "circle.h"
#include <QPainter>

Circle::Circle(const QPoint& center, int radius)
    : m_center(center), m_radius(radius) {}

void Circle::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;
    if (selectedShape == this && m_radius != 0) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::blue);
    painter.drawEllipse(m_center, m_radius, m_radius);

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(m_center, 3, 3);
    }
}

bool Circle::contains(const QPoint& point) const {
    int dx = point.x() - m_center.x();
    int dy = point.y() - m_center.y();
    return (dx * dx + dy * dy) <= (m_radius * m_radius);
}

void Circle::updatePos(QPoint diff) {
    m_center += diff;
}
