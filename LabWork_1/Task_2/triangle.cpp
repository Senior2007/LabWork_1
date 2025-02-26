#include "triangle.h"

Triangle::Triangle(const QPoint& start, const QPoint& end, const QPoint& middle) : m_start(start), m_end(end), m_middle(middle) {
    vertices = {m_start, m_end, m_middle};
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
        //Посчитать центр!!!!!!
        //painter.drawEllipse(m_center, 3, 3);
    }
}

