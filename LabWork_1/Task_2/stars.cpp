#include "stars.h"
#include <QPainter>
#include <cmath>

Stars::Stars(const QPoint& center, int outerRadius, int innerRadius, int numPoints) : Polygon(center), m_outerRadius(outerRadius), m_innerRadius(innerRadius), m_numPoints(numPoints) {
    vertices = calculateVertices();
    for (int i = 0; i < vertices.size(); i++) {
        if (i != vertices.size() - 1) {
            P += rastq(vertices[i].x(), vertices[i].y(), vertices[i + 1].x(), vertices[i + 1].y());
        } else {
            P += rastq(vertices[i].x(), vertices[i].y(), vertices[0].x(), vertices[0].y());
        }
    }

    for (int i = 0; i < vertices.size(); i += 2) {
        int idx = i + 1;
        if (idx == vertices.size()) {
            idx = 0;
        }

        S += STriangle(vertices[(i - 1) < 0 ? vertices.size() - 1 : i - 1], vertices[i], vertices[idx]);
        S += STriangle(vertices[(i - 1) < 0 ? vertices.size() - 1 : i - 1], center, vertices[idx]);
    }
}

double Stars::rastq(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double Stars::STriangle(QPoint p1, QPoint p2, QPoint p3) {
    double r1 = sqrt(pow(p1.x() - p3.x(), 2) + pow(p1.y() - p3.y(), 2));
    double r2 = sqrt(pow(p1.x() - p2.x(), 2) + pow(p1.y() - p2.y(), 2));
    double r3 = sqrt(pow(p2.x() - p3.x(), 2) + pow(p2.y() - p3.y(), 2));
    double P = r1 + r2 + r3;

    double p = P / 2;
    double S = sqrt(p * (p - r1) * (p - r2) * (p - r3));

    return S;
}

void Stars::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;
    if (selectedShape == this) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::cyan);
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

QVector<QPoint> Stars::calculateVertices() const {
    QVector<QPoint> vertices;
    const double angleStep = 2 * M_PI / m_numPoints;

    for (int i = 0; i < m_numPoints; ++i) {
        // Внешняя точка (кончик луча)
        double outerAngle = angleStep * i + (-M_PI / 2);
        int outerX = m_center.x() + m_outerRadius * cos(outerAngle) * SF;
        int outerY = m_center.y() + m_outerRadius * sin(outerAngle) * SF;
        vertices.append(QPoint(outerX, outerY));

        // Внутренняя точка (впадина)
        double innerAngle = outerAngle + angleStep / 2;
        int innerX = m_center.x() + m_innerRadius * cos(innerAngle) * SF;
        int innerY = m_center.y() + m_innerRadius * sin(innerAngle) * SF;
        vertices.append(QPoint(innerX, innerY));
    }

    return vertices;
}

void Stars::updatePos(QPoint diff) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] += diff;
    }
    m_center += diff;
}

void Stars::scale(double factor) {
    if(SF * factor > 10) SF = 10;
    else if(SF * factor < 0.1) SF = 0.1;
    else SF *= factor;

    S = 0;
    P = 0;

    vertices = calculateVertices();
    for (int i = 0; i < vertices.size(); i++) {
        if (i != vertices.size() - 1) {
            P += rastq(vertices[i].x(), vertices[i].y(), vertices[i + 1].x(), vertices[i + 1].y());
        } else {
            P += rastq(vertices[i].x(), vertices[i].y(), vertices[0].x(), vertices[0].y());
        }
    }

    for (int i = 0; i < vertices.size(); i += 2) {
        int idx = i + 1;
        if (idx == vertices.size()) {
            idx = 0;
        }

        S += STriangle(vertices[(i - 1) < 0 ? vertices.size() - 1 : i - 1], vertices[i], vertices[idx]);
        S += STriangle(vertices[(i - 1) < 0 ? vertices.size() - 1 : i - 1], m_center, vertices[idx]);
    }
}


void Stars::showInformation(QPainter& painter, int height) {

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
