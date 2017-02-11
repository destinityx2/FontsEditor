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

    // Create menu
    QMenu *file = menuBar()->addMenu(tr("&File"));
    QAction *save = file->addAction(tr("&Save"));
    QAction *load = file->addAction(tr("&Load"));

    QMenu *edit = menuBar()->addMenu(tr("&Edit"));

    QAction *undo = edit->addAction(tr("&Undo"));
    QAction *changeFillingeMode = edit->addAction(tr("&Change Filling Mode"));
    QAction *startNewContour = edit->addAction(tr("&Start New Contour"));

    edit->addSeparator();

    QMenu *del = edit->addMenu(tr("&Delete"));
    QMenu *copy = edit->addMenu(tr("&Copy"));
    QMenu *move = edit->addMenu(tr("&Move"));

    // Add connections
    connect(changeFillingeMode, SIGNAL(triggered(bool)), area, SLOT(swapBrush()));
}

void MainWindow::paintEvent(QPaintEvent *) {
    qDebug("Repainted MainWindow!");
}


MainWindow::~MainWindow()
{
}
