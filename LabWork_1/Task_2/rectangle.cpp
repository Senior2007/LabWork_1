#include <rectangle.h>
#include <QPainter>

Rectangle::Rectangle(const QPoint& start, const QPoint& end): m_start(start), m_end(end) {
    vertices = {m_start, QPoint(m_end.x(), m_start.y()), m_end, QPoint(m_start.x(), m_end.y())};
}

void Rectangle::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;
    if (selectedShape == this) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::red);
    painter.drawRect(m_start.x(), m_start.y(), m_end.x() - m_start.x(), m_end.y() - m_start.y());

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(m_start.x() + (m_end.x() - m_start.x()) / 2, m_start.y() + (m_end.y() - m_start.y()) / 2, 4, 4);
    }
}
