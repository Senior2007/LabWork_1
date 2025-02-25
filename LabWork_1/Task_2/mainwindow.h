#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QMenu>
#include <QPushButton>
#include "canvas.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private slots:
    void selectCircle();
    void selectSquare();
    void selectRectangle();
    void selectTriangle();
    void clearShapes();
private:
    Canvas* m_canvas;
    QToolButton* m_btnMenu;
    QMenu* m_shapeMenu;
    QPushButton* m_btnClear;
};

#endif // MAINWINDOW_H
