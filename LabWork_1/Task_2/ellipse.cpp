#include "ellipse.h"
#include <QPainter>

Ellipse::Ellipse(const QPoint& center, int radiusX, int radiusY)
    : m_center(center), m_radiusX(radiusX), m_radiusY(radiusY) {}

void Ellipse::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;

    if (selectedShape == this) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::lightGray);
    painter.drawEllipse(m_center, m_radiusX, m_radiusY);

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(m_center, 3, 3);
    }
}

bool Ellipse::contains(const QPoint& point) const {
    double dx = point.x() - m_center.x();
    double dy = point.y() - m_center.y();

    return ((dx * dx) / (m_radiusX * m_radiusX) + (dy * dy) / (m_radiusY * m_radiusY)) <= 1.0;
}
