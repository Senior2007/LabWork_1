#include "triangle.h"

Triangle::Triangle(const QPoint& start, const QPoint& end, const QPoint& middle) : m_start(start), m_end(end), m_middle(middle) {
    vertices = {m_start, m_end, m_middle};
    int h = abs(m_start.y() - m_end.y());
    h /= 3;
    if (m_end.y() > m_start.y()) {
        h = -h;
    }

    m_center = QPoint(m_start.x(), m_end.y() + h);
}

void Triangle::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;
    if (selectedShape == this) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::yellow);

    QPolygon triangle;
    triangle << m_start << m_end << m_middle;
    painter.drawPolygon(triangle);

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(m_center, 3, 3);
    }
}

void Triangle::updatePos(QPoint diff) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] += diff;
    }
    m_start += diff;
    m_middle += diff;
    m_end += diff;
    m_center += diff;
}
