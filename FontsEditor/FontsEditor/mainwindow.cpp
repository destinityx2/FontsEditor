#include "mainwindow.h"
#include "renderarea.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    path = QPainterPath();
    area = new RenderArea(path);

    // QBoxLayout *mainLayout = new QBoxLayout(QBoxLayout::Down);
    // mainLayout->addWidget(area);

    // setLayout(mainLayout);
    setCentralWidget(area);

    configureMenu();

    resize(300, 300);
}

void MainWindow::configureMenu() {
    QMenu *file = menuBar()->addMenu(tr("&File"));
    QAction *save = file->addAction("&Save");
    QAction *load = file->addAction("&Load");

    QMenu *actions = menuBar()->addMenu(tr("&Actions"));

    QMenu *del = actions->addMenu(tr("&Delete"));
    QMenu *copy = actions->addMenu(tr("&Copy"));
    QMenu *move = actions->addMenu(tr("&Move"));
    actions->addSeparator();
    QAction *changFillingeMode = actions->addAction(tr("Change Filling Mode"));

}

void MainWindow::paintEvent(QPaintEvent *) {
    qDebug("Repainted MainWindow!");
}


MainWindow::~MainWindow()
{
}
