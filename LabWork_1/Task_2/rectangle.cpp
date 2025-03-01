#include <rectangle.h>
#include <QPainter>

Rectangle::Rectangle(const QPoint& start, const QPoint& end): Polygon(QPoint(0, 0)), m_start(start), m_end(end) {
    vertices = {m_start, QPoint(m_end.x(), m_start.y()), m_end, QPoint(m_start.x(), m_end.y())};
    P = (m_end.x() - m_start.x() + m_end.y() - m_start.y()) * 2;
    S = (m_end.x() - m_start.x()) * (m_end.y() - m_start.y());

    m_center = m_start;
}

void Rectangle::draw(QPainter& painter, const Shape* selectedShape) const {
    bool pr = false;
    if (selectedShape == this) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::red);

    QPolygon polygon;
    for(const QPoint& vertice: vertices){
        polygon << (vertice - m_start) * SF + m_start;
    }
    painter.drawPolygon(polygon);


    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(QPoint(m_start.x() + (m_end.x() - m_start.x()) * SF / 2, m_start.y() + (m_end.y() - m_start.y()) * SF / 2), 3, 3);
    }
}

void Rectangle::updatePos(QPoint diff) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] += diff;
    }
    m_start += diff;
    m_end += diff;
    m_center += diff;
}

void Rectangle::scale(double factor) {
    if(SF * factor > 10) SF = 10;
    else if(SF * factor < 0.1) SF = 0.1;
    else SF *= factor;

    S = (m_end.x() - m_start.x()) * (m_end.y() - m_start.y()) * SF * SF;
    P = (m_end.x() - m_start.x() + m_end.y() - m_start.y()) * 2 * SF;
}

void Rectangle::showInformation(QPainter& painter, int height) {

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
