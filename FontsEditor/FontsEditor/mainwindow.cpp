#include "mainwindow.h"
#include "renderarea.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    path = QPainterPath();
    area = new RenderArea(path);

    QBoxLayout *mainLayout = new QBoxLayout(QBoxLayout::Down);
    mainLayout->addWidget(area);

    setLayout(mainLayout);
    resize(300, 300);
}

void MainWindow::paintEvent(QPaintEvent *) {
    qDebug("Repainted MainWindow!");
}

void MainWindow::mousePressEvent( QMouseEvent* ev ) {
    QPoint p = ev->pos();

    std::cout << p.x() << " " << p.y() << std::endl;
    qDebug("Mouse pressed!" + p.x());
    points.push_back(p);
    path = QPainterPath(points[0]);
    for (int i = 1; i < points.size(); ++i)
        path.lineTo(points[i]);

    area->updatePath(path);
    update();
}


MainWindow::~MainWindow()
{
}
