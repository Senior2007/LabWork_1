#include "triangle.h"

Triangle::Triangle(const QPoint& start, const QPoint& end, const QPoint& middle) : Polygon(QPoint(0, 0)), m_start(start), m_end(end), m_middle(middle) {
    vertices = {m_start, m_end, m_middle};
    int h = abs(m_start.y() - m_end.y());
    h /= 3;
    if (m_end.y() > m_start.y()) {
        h = -h;
    }

    m_center = QPoint(m_start.x(), m_end.y() + h);

    double r1 = sqrt(pow(start.x() - end.x(), 2) + pow(start.y() - end.y(), 2));
    double r2 = sqrt(pow(start.x() - middle.x(), 2) + pow(start.y() - middle.y(), 2));
    double r3 = sqrt(pow(middle.x() - end.x(), 2) + pow(middle.y() - end.y(), 2));
    P = r1 + r2 + r3;

    double p = P / 2;
    S = sqrt(p * (p - r1) * (p - r2) * (p - r3));
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

    QPolygon polygon;
    for(const QPoint& vertice: vertices){
        polygon << (vertice - m_start) * SF + m_start;
    }
    painter.drawPolygon(polygon);

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

void Triangle::scale(double factor) {
    if(SF * factor > 10) SF = 10;
    else if(SF * factor < 0.1) SF = 0.1;
    else SF *= factor;

    QPolygon polygon;
    for(const QPoint& vertice: vertices){
        polygon << (vertice - m_start) * SF + m_start;
    }

    QPoint start = polygon[0];
    QPoint end = polygon[1];
    QPoint middle = polygon[2];

    int h = abs(start.y() - end.y());
    h /= 3;
    if (end.y() > start.y()) {
        h = -h;
    }

    m_center = QPoint(start.x(), end.y() + h);

    double r1 = sqrt(pow(start.x() - end.x(), 2) + pow(start.y() - end.y(), 2));
    double r2 = sqrt(pow(start.x() - middle.x(), 2) + pow(start.y() - middle.y(), 2));
    double r3 = sqrt(pow(middle.x() - end.x(), 2) + pow(middle.y() - end.y(), 2));
    P = r1 + r2 + r3;

    double p = P / 2;
    S = sqrt(p * (p - r1) * (p - r2) * (p - r3));
}

void Triangle::showInformation(QPainter& painter, int height) {

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
