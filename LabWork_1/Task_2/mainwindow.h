#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QMenu>
#include "canvas.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private slots:
    void selectCircle();
    void selectSquare();

private:
    Canvas* m_canvas;
    QToolButton* m_btnMenu;
    QMenu* m_shapeMenu;
};

#endif // MAINWINDOW_H
