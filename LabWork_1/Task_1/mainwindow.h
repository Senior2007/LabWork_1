#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "car.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Car *car;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif
