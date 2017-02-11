#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QPainterPath>
#include <QBoxLayout>
#include <QMainWindow>

#include <vector>
#include <algorithm>

#include "renderarea.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    ~MainWindow();

private:
    QPainterPath path;
    RenderArea *area;
    std::vector<QPoint> points;

    void configureMenu();
};

#endif // MAINWINDOW_H
