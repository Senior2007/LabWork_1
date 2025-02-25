#include <rectangle.h>
#include <QPainter>

Rectangle::Rectangle(const QPoint& start, const QPoint& end)
    : m_start(start), m_end(end) {}

void Rectangle::draw(QPainter& painter) const {
    painter.setPen(Qt::black);
    painter.setBrush(Qt::red);
    painter.drawRect(m_start.x(), m_start.y(), m_end.x() - m_start.x(), m_end.y() - m_start.y());
}
