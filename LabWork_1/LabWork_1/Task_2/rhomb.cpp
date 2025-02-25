#include "rhomb.h"
#include <QPainter>

Rhomb::Rhomb(const QPoint& start, const QPoint& end, const QPoint& P3, const QPoint& P4)
    : m_start(start), m_end(end), m_3(P3), m_4(P4) {}

void Rhomb::draw(QPainter& painter) const {
    painter.setPen(Qt::black);
    painter.setBrush(Qt::magenta);

    QPolygon rhomb;
    rhomb << m_start << m_end << m_3 << m_4;
    painter.drawPolygon(rhomb);
}
