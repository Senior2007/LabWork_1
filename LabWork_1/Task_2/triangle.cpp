#include "triangle.h"

Triangle::Triangle(const QPoint& start, const QPoint& end, const QPoint& middle)
    : m_start(start), m_end(end), m_middle(middle) {}

void Triangle::draw(QPainter& painter) const {
    painter.setPen(Qt::black);
    painter.setBrush(Qt::yellow);

    QPolygon triangle;
    triangle << m_start << m_end << m_middle;
    painter.drawPolygon(triangle);
}

