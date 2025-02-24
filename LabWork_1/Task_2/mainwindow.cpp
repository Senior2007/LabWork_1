#include "mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), m_circle(new Circle(this)) {
    setCentralWidget(m_circle);
    setWindowTitle("Paint");
    resize(800, 600);
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        m_circle->startDrawing(event->pos());
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {
    m_circle->updateShape(event->pos());
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event) {
    Q_UNUSED(event);
    // Для завершения рисования можно добавить логику
}
