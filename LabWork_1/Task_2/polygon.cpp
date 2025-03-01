#include "polygon.h"

Polygon::Polygon(QPoint center) : m_center(center) {

}

void Polygon::draw(QPainter& painter, const Shape* selectedShape) const {
}

bool Polygon::contains(const QPoint& point) const {
    QPolygon polygon;

    for (const QPoint& v : vertices) {
        polygon << (v - m_center) * SF + m_center;
    }

    return polygon.containsPoint(point, Qt::OddEvenFill);
}

void Polygon::updatePos(QPoint diff) {

}

void Polygon::scale(double scalefactor) {

}

void Polygon::showInformation(QPainter& painter, int height) {

}
