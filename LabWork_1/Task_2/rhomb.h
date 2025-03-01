#ifndef RHOMB_H
#define RHOMB_H

#include "polygon.h"
#include <QPoint>

class Rhomb : public Polygon {
public:
    Rhomb(const QPoint& start, const QPoint& end, const QPoint& m_3, const QPoint& m_4);
    void draw(QPainter& painter, const Shape* selectedShape) const override;
    void updatePos(QPoint diff) override;
    void scale(double scalefactor) override;
    void showInformation(QPainter& painter, int height) override;

private:
    QPoint m_start;
    QPoint m_end;
    QPoint m_3;
    QPoint m_4;
};

#endif // RHOMB_H
