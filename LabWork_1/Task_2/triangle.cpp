#include "triangle.h"

Triangle::Triangle(const QPoint& start, const QPoint& end, const QPoint& middle)
    : m_start(start), m_end(end), m_middle(middle) {}

void Triangle::draw(QPainter& painter) const {
    painter.setPen(Qt::black);
    painter.setBrush(Qt::yellow);

    //painter.drawLine(m_start.x(), m_start.y(), m_end.x(), m_end.y());
    //painter.drawLine(m_end.x(), m_end.y(), m_middle.x(), m_middle.y());
    //painter.drawLine(m_start.x(), m_start.y(), m_middle.x(), m_middle.y());
    QPolygon triangle;
    triangle << m_start << m_end << m_middle;
    painter.drawPolygon(triangle);
}

