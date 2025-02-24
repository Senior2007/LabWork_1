#include "canvas.h"
#include "circle.h"
#include "square.h"
#include <QPainter>
#include <QMouseEvent>
#include <cmath>

Canvas::Canvas(QWidget* parent) : QWidget(parent) {}

void Canvas::setShapeType(ShapeType type) {
    m_currentShapeType = type;
}

void Canvas::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        m_startPos = event->pos();
        m_currentPos = event->pos();
        m_isDrawing = true;
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
            int radius = static_cast<int>(
                sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) +
                     pow(m_currentPos.y() - m_startPos.y(), 2))
                );
            m_shapes.push_back(std::make_unique<Circle>(m_startPos, radius));
            break;
        }
        case SquareType: {
            int dx = m_currentPos.x() - m_startPos.x();
            int dy = m_currentPos.y() - m_startPos.y();
            int size = std::max(abs(dx), abs(dy));
            QPoint endPos(
                m_startPos.x() + (dx > 0 ? size : -size),
                m_startPos.y() + (dy > 0 ? size : -size)
                );
            m_shapes.push_back(std::make_unique<Square>(m_startPos, endPos));
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

    // Draw all shapes
    for (const auto& shape : m_shapes) {
        shape->draw(painter);
    }

    // Draw preview
    if (m_isDrawing) {
        painter.setPen(Qt::red);
        painter.setBrush(Qt::NoBrush);

        switch(m_currentShapeType) {
        case CircleType: {
            int radius = static_cast<int>(
                sqrt(pow(m_currentPos.x() - m_startPos.x(), 2) +
                     pow(m_currentPos.y() - m_startPos.y(), 2))
                );
            painter.drawEllipse(m_startPos, radius, radius);
            break;
        }
        case SquareType: {
            int dx = m_currentPos.x() - m_startPos.x();
            int dy = m_currentPos.y() - m_startPos.y();
            int size = std::max(abs(dx), abs(dy));
            QPoint endPos(
                m_startPos.x() + (dx > 0 ? size : -size),
                m_startPos.y() + (dy > 0 ? size : -size)
                );
            painter.drawRect(QRect(m_startPos, endPos));
            break;
        }
        }
    }
}
