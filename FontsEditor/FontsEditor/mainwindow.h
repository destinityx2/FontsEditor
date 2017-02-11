#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QPainterPath>
#include <QBoxLayout>

#include <vector>
#include <algorithm>

#include "renderarea.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent( QMouseEvent* ev );
    ~MainWindow();

private:
    QPainterPath path;
    RenderArea *area;
    std::vector<QPoint> points;
};

#endif // MAINWINDOW_H
