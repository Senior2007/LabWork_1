#ifndef MOVINGRECTANGLE_H
#define MOVINGRECTANGLE_H

#include <QWidget>
#include <QTimer>

class MovingRectangle : public QWidget {
    Q_OBJECT

protected:
    int x, y;
    int width, height;
    QTimer *timer;

public:
    explicit MovingRectangle(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void move();
};

#endif
