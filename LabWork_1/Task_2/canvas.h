#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <vector>
#include <memory>
#include "shape.h"

class Circle;
class Square;
class Rectangle;
class Triangle;
class Rhomb;
class Hexagon;
class Stars;
class Ellipse;

class Canvas : public QWidget {
    Q_OBJECT

public:
    enum ShapeType { CircleType, SquareType, RectangleType, TriangleType, RhombType, HexagonType, Star5Type, Star6Type, Star8Type, EllipseType };

    explicit Canvas(QWidget* parent = nullptr);
    void setShapeType(ShapeType type);
    void clear_shapes();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    std::vector<std::unique_ptr<Shape>> m_shapes;
    ShapeType m_currentShapeType = CircleType;
    QPoint m_startPos;
    QPoint m_currentPos;
    bool m_isDrawing = false;
};

#endif // CANVAS_H
