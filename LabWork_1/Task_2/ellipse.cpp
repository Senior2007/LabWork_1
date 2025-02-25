#include "ellipse.h"
#include <QPainter>

Ellipse::Ellipse(const QPoint& center, int radiusX, int radiusY)
    : m_center(center), m_radiusX(radiusX), m_radiusY(radiusY) {}

void Ellipse::draw(QPainter& painter) const {
    painter.setPen(Qt::black);
    painter.setBrush(Qt::lightGray);
    painter.drawEllipse(m_center, m_radiusX, m_radiusY);
}
