#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->setStyleSheet("background-image: url(/Users/senior/Desktop/BSUIR/ОАиП/QT/LabWork_1/Task_1/background.jpg);");

    car = new Car(this);

    QPushButton *doorButton = new QPushButton("Переключатель дверей", this);
    doorButton->setStyleSheet("background-color: red;");
    connect(doorButton, &QPushButton::clicked, car, &Car::toggleDoors);

    QPushButton *lightButton = new QPushButton("Переключатель фар", this);
    lightButton->setStyleSheet("background-color: red;");
    connect(lightButton, &QPushButton::clicked, car, &Car::toggleLights);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(car);
    layout->addWidget(doorButton);
    layout->addWidget(lightButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {}
