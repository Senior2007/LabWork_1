#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <QPainter>

class Shape : public QWidget {
    Q_OBJECT

public:
    explicit Shape(QWidget* parent = nullptr);
    virtual ~Shape() = default;

    virtual void startDrawing(const QPoint& position) = 0;
    virtual void updateShape(const QPoint& position) = 0;
    virtual void paint(QPainter& painter) const = 0;

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // SHAPE_H
