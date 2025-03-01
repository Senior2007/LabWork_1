#include "ellipse.h"
#include <QPainter>

Ellipse::Ellipse(const QPoint& center, int radiusX, int radiusY): m_center(center), m_radiusX(radiusX), m_radiusY(radiusY) {
    S = M_PI * radiusX * radiusY;
    P = M_PI * (3 * (radiusX + radiusY) - sqrt((3 * radiusX + radiusY) * (radiusX + 3 * radiusY)));
}

void Ellipse::scale(double factor) {
    if(SF * factor > 10) SF = 10;
    else if(SF * factor < 0.1) SF = 0.1;
    else SF *= factor;

    S = M_PI * m_radiusX * m_radiusY * SF * SF;
    P = M_PI * (3 * (m_radiusX * SF + m_radiusY * SF) - sqrt((3 * m_radiusX * SF + m_radiusY * SF) * (m_radiusX * SF + 3 * m_radiusY * SF)));
}

void Ellipse::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;

    if (selectedShape == this) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::lightGray);
    painter.drawEllipse(m_center.x() - m_radiusX * SF, m_center.y() - m_radiusY * SF, 2 * m_radiusX * SF, 2 * m_radiusY * SF);

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(m_center, 3, 3);
    }
}

bool Ellipse::contains(const QPoint& point) const {
    double dx = point.x() - m_center.x();
    double dy = point.y() - m_center.y();

    return ((dx * dx) / (m_radiusX * m_radiusX * SF * SF) + (dy * dy) / (m_radiusY * m_radiusY * SF * SF)) <= 1.0;
}

void Ellipse::updatePos(QPoint diff) {
    m_center += diff;
}

void Ellipse::showInformation(QPainter& painter, int height) {

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
