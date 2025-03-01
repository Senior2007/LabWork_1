#include "square.h"
#include <QPainter>
#include <algorithm>

Square::Square(const QPoint& start, const QPoint& end) : Polygon(QPoint(0, 0)), m_start(start), m_end(end) {
    vertices = {m_start, QPoint(m_end.x(), m_start.y()), m_end, QPoint(m_start.x(), m_end.y())};
    P = (m_end.x() - m_start.x()) * 4;
    S = (m_end.x() - m_start.x()) * (m_end.x() - m_start.x());
    m_center = m_start;
}

void Square::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;

    if (selectedShape == this) {
        painter.setPen(Qt::red);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }
    painter.setBrush(Qt::green);

    int lx = m_start.x(), ly = m_start.y(), rx = m_end.x(), ry = m_end.y();
    int size = std::max(abs(rx - lx) * SF, abs(ry - ly) * SF);
    painter.drawRect(m_start.x(), m_start.y(), size, size);

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(QPoint(m_start.x() + size / 2, m_start.y() + size / 2), 3, 3);
    }
}

void Square::updatePos(QPoint diff) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] += diff;
    }
    m_start += diff;
    m_end += diff;
    m_center += diff;
}

void Square::scale(double factor) {
    if(SF * factor > 10) SF = 10;
    else if(SF * factor < 0.1) SF = 0.1;
    else SF *= factor;

    P = (m_end.x() - m_start.x()) * 4 * SF;
    S = (m_end.x() - m_start.x()) * (m_end.x() - m_start.x()) * SF * SF;
}

void Square::showInformation(QPainter& painter, int height) {

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
