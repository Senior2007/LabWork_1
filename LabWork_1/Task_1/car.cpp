#include "car.h"
#include <QPainter>

Car::Car(QWidget *parent) : MovingRectangle(parent), doorsOpen(false), lightsOn(false) {}

void Car::toggleDoors() {
    doorsOpen = !doorsOpen;
    update();
}

void Car::toggleLights() {
    lightsOn = !lightsOn;
    update();
}

void Car::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.setBrush(Qt::green);
    painter.drawRect(x, y, width, height);

    painter.setBrush(Qt::black);
    if (doorsOpen) {
        painter.drawRect(x + 40, y - 20, 20, 20);
        painter.drawRect(x + 40, y + 50, 20, 20);
    }

    painter.setBrush(lightsOn ? Qt::yellow : Qt::gray);
    painter.drawEllipse(x + width, y + 10, 10, 10);
    painter.drawEllipse(x + width, y + height - 20, 10, 10);
}
