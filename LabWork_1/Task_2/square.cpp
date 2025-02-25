#include "square.h"
#include <QPainter>
#include <algorithm>

Square::Square(const QPoint& start, const QPoint& end)
    : m_start(start), m_end(end) {}

void Square::draw(QPainter& painter) const {
    painter.setPen(Qt::black);
    painter.setBrush(Qt::green);

    int lx = m_start.x(), ly = m_start.y(), rx = m_end.x(), ry = m_end.y();
    int size = std::max(abs(rx - lx), abs(ry - ly));
    painter.drawRect(m_start.x(), m_start.y(), size, size);
}
