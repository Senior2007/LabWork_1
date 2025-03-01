#include "hexagon.h"
#include <QPainter>
#include <cmath>

Hexagon::Hexagon(const QPoint& center, int radius) : Polygon(center), m_radius(radius)  {
    vertices = calculateVertices();
    P = 6 * radius;
    S = (3 * sqrt(3) / 2) * radius * radius;
}

void Hexagon::scale(double factor) {
    if(SF * factor > 10) SF = 10;
    else if(SF * factor < 0.1) SF = 0.1;
    else SF *= factor;

    P = 6 * m_radius * SF;
    S = (3 * sqrt(3) / 2) * m_radius * m_radius * SF * SF;
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
    QPolygon polygon;
    for(const QPoint& vertice: vertices){
        polygon << (vertice - m_center) * SF + m_center;
    }
    painter.drawPolygon(polygon);

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

void Hexagon::updatePos(QPoint diff) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] += diff;
    }
    m_center += diff;
}

void Hexagon::showInformation(QPainter& painter, int height) {

    painter.setPen(Qt::white);
    QRect rect(20, height - 43, 100, 20);
    painter.drawText(rect, Qt::AlignLeft, QString("P: ") + QString::number(P, 'f', 2));

    QRect rect2(20, height - 22, 100, 20);
    painter.drawText(rect2, Qt::AlignLeft, QString("S: ") + QString::number(S, 'f', 2));

    //QRect rect3(142, height - 22, 100, 20);
    // painter.drawText(rect3, Qt::AlignLeft, QString("Угол: ") + QString::number(-this->rotation, 'f', 2));

    QRect rect4(118, height - 43, 100, 20);
    painter.drawText(rect4, Qt::AlignLeft, QString("Маcштаб: ") + QString::number(SF, 'f', 2));


    QRect rect5(250, height - 22, 100, 20);
    painter.drawText(rect5, Qt::AlignLeft, QString("ЦМ X: ") + QString::number(m_center.x(), 'f', 2));

    QRect rect6(250, height - 43, 100, 20);
    painter.drawText(rect6, Qt::AlignLeft, QString("ЦМ Y: ") + QString::number(m_center.y(), 'f', 2));
}
