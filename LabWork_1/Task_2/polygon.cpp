#include "polygon.h"

Polygon::Polygon() {}

void Polygon::draw(QPainter& painter, const Shape* selectedShape) const {
}

bool Polygon::contains(const QPoint& point) const {
    QPolygon polygon;

    for (const QPoint& v : vertices) {
        polygon << v;
    }

    return polygon.containsPoint(point, Qt::OddEvenFill);
}

void Polygon::updatePos(QPoint diff) {

}
