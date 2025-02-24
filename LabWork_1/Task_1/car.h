#ifndef CAR_H
#define CAR_H

#include "movingrectangle.h"

class Car : public MovingRectangle {
    Q_OBJECT

private:
    bool doorsOpen;
    bool lightsOn;

public:
    explicit Car(QWidget *parent = nullptr);

    void toggleDoors();
    void toggleLights();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // CAR_H
