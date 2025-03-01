#include "circle.h"
#include <QPainter>

Circle::Circle(const QPoint& center, int radius) : m_center(center), m_radius(radius) {
    S = M_PI * radius * radius;
    P = 2 * M_PI * radius;
}

void Circle::scale(double factor) {
    if(SF * factor > 10) SF = 10;
    else if(SF * factor < 0.1) SF = 0.1;
    else SF *= factor;

    S = M_PI * m_radius * m_radius * SF * SF;
    P = 2 * M_PI * m_radius * SF;
}

void Circle::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;
    if (selectedShape == this && m_radius != 0) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::blue);
    painter.drawEllipse(m_center.x() - m_radius * SF, m_center.y() - m_radius * SF, m_radius * 2 * SF, m_radius * 2 * SF);

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(m_center, 3, 3);
    }
}

bool Circle::contains(const QPoint& point) const {
    int dx = point.x() - m_center.x();
    int dy = point.y() - m_center.y();
    return (dx * dx + dy * dy) <= (m_radius * SF * m_radius * SF);
}

void Circle::updatePos(QPoint diff) {
    m_center += diff;
}

void Circle::showInformation(QPainter& painter, int height) {

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
