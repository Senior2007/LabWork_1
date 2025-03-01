#include "rhomb.h"
#include <QPainter>

Rhomb::Rhomb(const QPoint& start, const QPoint& end, const QPoint& P3, const QPoint& P4): Polygon(QPoint(0, 0)), m_start(start), m_end(end), m_3(P3), m_4(P4) {
    vertices = {m_start, m_end, m_3, m_4};
    m_center = QPoint(m_start.x(), m_end.y());

    P = sqrt(pow(m_start.x() - m_end.x(), 2) + pow(m_start.y() - m_end.y(), 2));

    double d1 = sqrt(pow(m_start.x() - P3.x(), 2) + pow(m_start.y() - P3.y(), 2));
    double d2 = sqrt(pow(P4.x() - m_end.x(), 2) + pow(P4.y() - m_end.y(), 2));

    S = (d1 * d2) / 2;
}

void Rhomb::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;
    if (selectedShape == this) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::magenta);

    QPolygon polygon;
    for(int i = 0; i < 4; i++)
        polygon << (vertices[i]- m_start) * SF + m_start;
    painter.drawPolygon(polygon);

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(m_center, 3, 3);
    }
}

void Rhomb::updatePos(QPoint diff) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] += diff;
    }
    m_start += diff;
    m_end += diff;
    m_3 += diff;
    m_4 += diff;
    m_center += diff;
}

void Rhomb::scale(double factor) {
    if(SF * factor > 10) SF = 10;
    else if(SF * factor < 0.1) SF = 0.1;
    else SF *= factor;

    P = sqrt(pow(m_start.x() - m_end.x(), 2) + pow(m_start.y() - m_end.y(), 2)) * SF;

    double d1 = sqrt(pow((m_start.x() - m_3.x()) * SF, 2) + pow((m_start.y() - m_3.y()) * SF, 2));
    double d2 = sqrt(pow((m_4.x() - m_end.x()) * SF, 2) + pow((m_4.y() - m_end.y()) * SF, 2));

    S = (d1 * d2) / 2;

    QPolygon polygon;
    for(int i = 0; i < 4; i++)
        polygon << (vertices[i]- m_start) * SF + m_start;

    m_center = QPoint(polygon[0].x(), polygon[1].y());
}

void Rhomb::showInformation(QPainter& painter, int height) {

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
