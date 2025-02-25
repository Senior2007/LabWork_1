#include "movingrectangle.h"
#include <QPainter>

MovingRectangle::MovingRectangle(QWidget *parent) : QWidget(parent), x(50), y(150), width(100), height(50) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MovingRectangle::move);
    timer->start(20);
}

void MovingRectangle::move() {
    x += 1;
    if (x > parentWidget()->width()) x = 0;
    update();
}

void MovingRectangle::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    painter.drawRect(x, y, width, height);
}
