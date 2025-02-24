#include "square.h"
#include <QPainter>
#include <algorithm>

Square::Square(const QPoint& start, const QPoint& end)
    : m_start(start), m_end(end) {}

void Square::draw(QPainter& painter) const {
    painter.setPen(Qt::black);
    painter.setBrush(Qt::green);
    //изменить реализацию, чтобы взависимости от стартовой и конечной точки рисовалось в разных координатах
    int size = std::max(m_end.x() - m_start.x(), m_end.y() - m_start.y());
    painter.drawRect(m_start.x(), m_start.y(), size, size);
}
