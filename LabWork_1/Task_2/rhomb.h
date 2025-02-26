#ifndef RHOMB_H
#define RHOMB_H

#include "polygon.h"
#include <QPoint>

class Rhomb : public Polygon {
public:
    Rhomb(const QPoint& start, const QPoint& end, const QPoint& m_3, const QPoint& m_4);
    void draw(QPainter& painter, const Shape* selectedShape) const override;
    void updatePos(QPoint diff) override;

private:
    QPoint m_start;
    QPoint m_end;
    QPoint m_3;
    QPoint m_4;
    QPoint m_center;
};

#endif // RHOMB_H
