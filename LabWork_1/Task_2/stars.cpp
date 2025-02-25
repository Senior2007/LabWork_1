#include "stars.h"
#include <QPainter>
#include <cmath>

Stars::Stars(const QPoint& center, int outerRadius, int innerRadius, int numPoints)
    : m_center(center), m_outerRadius(outerRadius), m_innerRadius(innerRadius), m_numPoints(numPoints) {}

void Stars::draw(QPainter& painter) const {
    painter.setPen(Qt::black);
    painter.setBrush(Qt::cyan);
    painter.drawPolygon(calculateVertices());
}

QVector<QPoint> Stars::calculateVertices() const {
    QVector<QPoint> vertices;
    const double angleStep = 2 * M_PI / m_numPoints;

    for (int i = 0; i < m_numPoints; ++i) {
        // Внешняя точка (кончик луча)
        double outerAngle = angleStep * i + (-M_PI / 2);
        int outerX = m_center.x() + m_outerRadius * cos(outerAngle);
        int outerY = m_center.y() + m_outerRadius * sin(outerAngle);
        vertices.append(QPoint(outerX, outerY));

        // Внутренняя точка (впадина)
        double innerAngle = outerAngle + angleStep / 2;
        int innerX = m_center.x() + m_innerRadius * cos(innerAngle);
        int innerY = m_center.y() + m_innerRadius * sin(innerAngle);
        vertices.append(QPoint(innerX, innerY));
    }

    return vertices;
}
