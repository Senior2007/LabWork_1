#include "canvas.h"
#include "circle.h"
#include "ellipse.h"
#include "square.h"
#include "rectangle.h"
#include "triangle.h"
#include "rhomb.h"
#include "hexagon.h"
#include "stars.h"
#include <QPainter>
#include <QMouseEvent>
#include <cmath>

Canvas::Canvas(QWidget* parent) : QWidget(parent) {}

void Canvas::setShapeType(ShapeType type) {
    m_currentShapeType = type;
}

Shape* Canvas::findShapeAt(const QPoint& point) const {
    for (auto it = m_shapes.rbegin(); it != m_shapes.rend(); ++it) {
        if ((*it)->contains(point)) {
            return it->get();
        }
    }
    return nullptr;
}

void Canvas::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        m_startPos = event->pos();
        m_currentPos = event->pos();
        m_isDrawing = true;
        m_selectedShape = findShapeAt(event->pos());
        update();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent* event) {
    if (m_isDrawing) {
        m_currentPos = event->pos();
        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && m_isDrawing) {
        switch(m_currentShapeType) {
            case CircleType: {
                int radius = static_cast<int>(sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) + pow(m_currentPos.y() - m_startPos.y(), 2)));
                m_shapes.push_back(std::make_unique<Circle>(m_startPos, radius));
                break;
            }
            case EllipseType: {
                int radiusX = abs(m_currentPos.x() - m_startPos.x());
                int radiusY = abs(m_currentPos.y() - m_startPos.y());
                m_shapes.push_back(std::make_unique<Ellipse>(m_startPos, radiusX, radiusY));
                break;
            }

            case SquareType: {
                int dx = m_currentPos.x() - m_startPos.x();
                int dy = m_currentPos.y() - m_startPos.y();
                int size = std::max(abs(dx), abs(dy));

                if (dx < 0 && dy < 0) {
                    m_startPos.setX(m_startPos.x() - size);
                    m_startPos.setY(m_startPos.y() - size);
                }

                if (dx > 0 && dy < 0) {
                    m_startPos.setY(m_startPos.y() - size);
                }

                if (dx < 0 && dy > 0) {
                    m_startPos.setX(m_startPos.x() - size);
                }

                QPoint endPos(m_startPos.x() + size, m_startPos.y() + size);
                m_shapes.push_back(std::make_unique<Square>(m_startPos, endPos));
                break;
            }
            case RectangleType: {
                int dx = m_currentPos.x() - m_startPos.x();
                int dy = m_currentPos.y() - m_startPos.y();
                int size_x = abs(dx), size_y = abs(dy);

                if (dx < 0 && dy < 0) {
                    m_startPos.setX(m_startPos.x() - size_x);
                    m_startPos.setY(m_startPos.y() - size_y);
                }

                if (dx > 0 && dy < 0) {
                    m_startPos.setY(m_startPos.y() - size_y);
                }

                if (dx < 0 && dy > 0) {
                    m_startPos.setX(m_startPos.x() - size_x);
                }

                QPoint endPos(m_startPos.x() + size_x, m_startPos.y() + size_y);
                m_shapes.push_back(std::make_unique<Rectangle>(m_startPos, endPos));
                break;
            }
            case TriangleType: {
                QPoint endPos(m_currentPos.x(), m_currentPos.y());
                QPoint midPos(m_startPos.x() - (endPos.x() - m_startPos.x()), endPos.y());
                m_shapes.push_back(std::make_unique<Triangle>(m_startPos, endPos, midPos));
                break;
            }
            case RhombType: {
                QPoint endPos(m_currentPos.x(), m_currentPos.y());
                QPoint m_3(m_startPos.x(), 2 * endPos.y() - m_startPos.y());
                QPoint m_4(2 * m_startPos.x() - endPos.x(), endPos.y());
                m_shapes.push_back(std::make_unique<Rhomb>(m_startPos, endPos, m_3, m_4));
                break;
            }
            case HexagonType: {
                int radius = static_cast<int>(sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) + pow(m_currentPos.y() - m_startPos.y(), 2)));
                m_shapes.push_back(std::make_unique<Hexagon>(m_startPos, radius));
                break;
            }
            case Star5Type: {
                int outerRadius = static_cast<int>(sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) + pow(m_currentPos.y() - m_startPos.y(), 2)));
                int innerRadius = outerRadius / 2;
                int numPoints = 5;
                m_shapes.push_back(std::make_unique<Stars>(m_startPos, outerRadius, innerRadius, numPoints));
                break;
            }
            case Star6Type: {
                int outerRadius = static_cast<int>(sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) + pow(m_currentPos.y() - m_startPos.y(), 2)));
                int innerRadius = outerRadius / 2;
                int numPoints = 6;
                m_shapes.push_back(std::make_unique<Stars>(m_startPos, outerRadius, innerRadius, numPoints));
                break;
            }

            case Star8Type: {
                int outerRadius = static_cast<int>(sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) + pow(m_currentPos.y() - m_startPos.y(), 2)));
                int innerRadius = outerRadius / 2;
                int numPoints = 8;
                m_shapes.push_back(std::make_unique<Stars>(m_startPos, outerRadius, innerRadius, numPoints));
                break;
            }
        }
        m_isDrawing = false;
        update();
    }
}

void Canvas::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (const auto& shape : m_shapes) {
        shape->draw(painter, m_selectedShape);
    }

    // Draw preview
    if (m_isDrawing) {
        painter.setPen(Qt::red);
        painter.setBrush(Qt::NoBrush);

        switch(m_currentShapeType) {
            case CircleType: {
                int radius = static_cast<int>(sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) + pow(m_currentPos.y() - m_startPos.y(), 2)));
                painter.drawEllipse(m_startPos, radius, radius);
                break;
            }
            case EllipseType: {
                int radiusX = abs(m_currentPos.x() - m_startPos.x());
                int radiusY = abs(m_currentPos.y() - m_startPos.y());
                painter.drawEllipse(m_startPos, radiusX, radiusY);
                break;
            }
            case SquareType: {
                int dx = m_currentPos.x() - m_startPos.x();
                int dy = m_currentPos.y() - m_startPos.y();
                int size = std::max(abs(dx), abs(dy));
                QPoint endPos(m_startPos.x() + (dx > 0 ? size : -size), m_startPos.y() + (dy > 0 ? size : -size));
                painter.drawRect(QRect(m_startPos, endPos));
                break;
            }
            case RectangleType: {
                painter.drawRect(QRect(m_startPos, m_currentPos));
                break;
            }
            case TriangleType: {
                QPoint endPos(m_currentPos.x(), m_currentPos.y());
                QPoint midPos(m_startPos.x() - (endPos.x() - m_startPos.x()), endPos.y());

                QPolygon triangle;
                triangle << m_startPos << endPos << midPos;
                painter.drawPolygon(triangle);
                break;
            }
            case RhombType: {
                QPoint endPos(m_currentPos.x(), m_currentPos.y());
                QPoint m_3(m_startPos.x(), 2 * endPos.y() - m_startPos.y());
                QPoint m_4(2 * m_startPos.x() - endPos.x(), endPos.y());

                QPolygon rhomb;
                rhomb << m_startPos << endPos << m_3 << m_4;
                painter.drawPolygon(rhomb);
                break;
            }
            case HexagonType: {
                int radius = static_cast<int>(sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) + pow(m_currentPos.y() - m_startPos.y(), 2)));
                Hexagon previewHexagon(m_startPos, radius);
                painter.drawPolygon(previewHexagon.calculateVertices());
                break;
            }
            case Star5Type: {
                int outerRadius = static_cast<int>(sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) + pow(m_currentPos.y() - m_startPos.y(), 2)));
                int innerRadius = outerRadius / 2;
                int numPoints = 5;
                Stars previewStar(m_startPos, outerRadius, innerRadius, numPoints);
                painter.drawPolygon(previewStar.calculateVertices());
                break;
            }
            case Star6Type: {
                int outerRadius = static_cast<int>(sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) + pow(m_currentPos.y() - m_startPos.y(), 2)));
                int innerRadius = outerRadius / 2;
                int numPoints = 6;
                Stars previewStar(m_startPos, outerRadius, innerRadius, numPoints);
                painter.drawPolygon(previewStar.calculateVertices());
                break;
            }
            case Star8Type: {
                int outerRadius = static_cast<int>(sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) + pow(m_currentPos.y() - m_startPos.y(), 2)));
                int innerRadius = outerRadius / 2;
                int numPoints = 8;
                Stars previewStar(m_startPos, outerRadius, innerRadius, numPoints);
                painter.drawPolygon(previewStar.calculateVertices());
                break;
            }
        }
    }
}


void Canvas::clear_shapes() {
    m_shapes.clear();
    update();
}
