#ifndef SQUARE_H
#define SQUARE_H

#include "polygon.h"
#include <QPoint>

class Square : public Polygon {
public:
    Square(const QPoint& start, const QPoint& end);
    void draw(QPainter& painter, const Shape* selectedShape) const override;
    void updatePos(QPoint diff) override;
    void scale(double scalefactor) override;
    void showInformation(QPainter& painter, int height) override;

private:
    QPoint m_start;
    QPoint m_end;
};

#endif // SQUARE_H
