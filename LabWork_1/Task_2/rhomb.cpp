#include "rhomb.h"
#include <QPainter>

Rhomb::Rhomb(const QPoint& start, const QPoint& end, const QPoint& P3, const QPoint& P4): m_start(start), m_end(end), m_3(P3), m_4(P4) {
    vertices = {m_start, m_end, m_3, m_4};
    m_center = QPoint(m_start.x(), m_end.y());
}

void Rhomb::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;
    if (selectedShape == this) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::magenta);

    QPolygon rhomb;
    rhomb << m_start << m_end << m_3 << m_4;
    painter.drawPolygon(rhomb);

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(m_center, 3, 3);
    }
}
