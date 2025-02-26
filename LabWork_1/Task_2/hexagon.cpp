#include "hexagon.h"
#include <QPainter>
#include <cmath>

Hexagon::Hexagon(const QPoint& center, int radius) : m_center(center), m_radius(radius) {
    vertices = calculateVertices();
}

void Hexagon::draw(QPainter& painter, const Shape* selectedShape) const {

    bool pr = false;
    if (selectedShape == this && m_radius != 0) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::white);
    painter.drawPolygon(calculateVertices());

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(m_center, 3, 3);
    }
}

QVector<QPoint> Hexagon::calculateVertices() const {
    QVector<QPoint> vertices;
    const double angleStep = M_PI / 3;

    for (int i = 0; i < 6; ++i) {
        double angle = angleStep * i;
        int x = m_center.x() + m_radius * cos(angle);
        int y = m_center.y() + m_radius * sin(angle);
        vertices.append(QPoint(x, y));
    }

    return vertices;
}
