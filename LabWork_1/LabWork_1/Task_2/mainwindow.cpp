#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QAction>
#include <QFrame>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    m_canvas(new Canvas(this)),
    m_btnMenu(new QToolButton(this)),
    m_shapeMenu(new QMenu(this)),
    m_btnClear(new QPushButton("Очистить", this))
{
    setWindowTitle("Рисовалка фигур");
    resize(800, 600);

    m_btnMenu->setText("Фигуры");
    m_btnMenu->setFixedSize(100, 30);
    m_btnMenu->setPopupMode(QToolButton::InstantPopup);

    QAction* actionCircle = new QAction("Круг", this);
    QAction* actionSquare = new QAction("Квадрат", this);
    QAction* actionRectangle = new QAction("Прямоугольник", this);
    QAction* actionTriangle = new QAction("Треугольник", this);
    QAction* actionRhomb = new QAction("Ромб", this);
    m_shapeMenu->addAction(actionCircle);
    m_shapeMenu->addAction(actionSquare);
    m_shapeMenu->addAction(actionRectangle);
    m_shapeMenu->addAction(actionTriangle);
    m_shapeMenu->addAction(actionRhomb);
    m_btnMenu->setMenu(m_shapeMenu);

    m_btnClear->setFixedSize(100, 35);
    // Контейнер для кнопок (правый верхний угол)
    QWidget* topPanel = new QWidget(this);
    QHBoxLayout* topLayout = new QHBoxLayout(topPanel);
    topLayout->setContentsMargins(0, 10, 10, 0); // Отступ справа 10px
    topLayout->addStretch(); // Растягиваемое пространство слева
    topLayout->addWidget(m_btnClear);
    topLayout->addWidget(m_btnMenu);

    // Основной layout
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0); // Убрать все отступы

    mainLayout->addWidget(topPanel);
    mainLayout->addWidget(m_canvas, 1); // stretch factor = 1s

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Сигналы и слоты
    connect(actionCircle, &QAction::triggered, this, &MainWindow::selectCircle);
    connect(actionSquare, &QAction::triggered, this, &MainWindow::selectSquare);
    connect(actionRectangle, &QAction::triggered, this, &MainWindow::selectRectangle);
    connect(actionTriangle, &QAction::triggered, this, &MainWindow::selectTriangle);
    connect(actionRhomb, &QAction::triggered, this, &MainWindow::selectRhomb);
    connect(m_btnClear, &QPushButton::clicked, this, &MainWindow::clearShapes);
}

void MainWindow::selectCircle() {
    m_canvas->setShapeType(Canvas::CircleType);
    m_btnMenu->setText("Круг");
}

void MainWindow::selectSquare() {
    m_canvas->setShapeType(Canvas::SquareType);
    m_btnMenu->setText("Квадрат");
}

void MainWindow::selectRectangle() {
    m_canvas->setShapeType(Canvas::RectangleType);
    m_btnMenu->setText("Прямоугольник");
}

void MainWindow::selectTriangle() {
    m_canvas->setShapeType(Canvas::TriangleType);
    m_btnMenu->setText("Треугольник");
}

void MainWindow::selectRhomb() {
    m_canvas->setShapeType(Canvas::RhombType);
    m_btnMenu->setText("Ромб");
}


void MainWindow::clearShapes() {
    m_canvas->clear_shapes();
}
