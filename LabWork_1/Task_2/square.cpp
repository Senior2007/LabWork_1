#include "square.h"
#include <QPainter>
#include <algorithm>

Square::Square(const QPoint& start, const QPoint& end) : m_start(start), m_end(end) {
    vertices = {m_start, QPoint(m_end.x(), m_start.y()), m_end, QPoint(m_start.x(), m_end.y())};
}

void Square::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;

    if (selectedShape == this) {
        painter.setPen(Qt::red);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }
    painter.setBrush(Qt::green);

    int lx = m_start.x(), ly = m_start.y(), rx = m_end.x(), ry = m_end.y();
    int size = std::max(abs(rx - lx), abs(ry - ly));
    painter.drawRect(m_start.x(), m_start.y(), size, size);

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(QPoint(m_start.x() + size / 2, m_start.y() + size / 2), 3, 3);
    }
}

void Square::updatePos(QPoint diff) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] += diff;
    }
    m_start += diff;
    m_end += diff;
}
