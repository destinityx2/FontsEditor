#include "mainwindow.h"
#include "renderarea.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <iostream>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    area = new RenderArea();
    setCentralWidget(area);

    configureMenu();

    resize(300, 300);
}

void MainWindow::configureMenu() {
    // Create menu
    file = menuBar()->addMenu(tr("&File"));
    save = file->addAction(tr("&Save"));
    load = file->addAction(tr("&Load"));

    edit = menuBar()->addMenu(tr("&Edit"));

    undo = edit->addAction(tr("&Undo"));
    changeFillingeMode = edit->addAction(tr("&Change Filling Mode"));
    startNewContour = edit->addAction(tr("&Start New Contour"));

    edit->addSeparator();

    del = edit->addMenu(tr("&Delete"));
    copy = edit->addMenu(tr("&Copy"));
    move = edit->addMenu(tr("&Move"));

    activeInd = menuBar()->addAction(tr("Active: 0"));

    // Set connections
    connect(changeFillingeMode, SIGNAL(triggered(bool)), area, SLOT(swapBrush()));
    connect(undo, SIGNAL(triggered(bool)), area, SLOT(deleteLastPointIfExists()));
    connect(startNewContour, SIGNAL(triggered(bool)), this, SLOT(addNewContour()));

    connect(area, SIGNAL(activeIndexChanged(int)), this, SLOT(changeActiveIndex(int)));


    // Set shortcuts
    setShortcuts();
}

void MainWindow::addNewContour() {
    area->addNewActiveContour(Contour());
}

void MainWindow::setShortcuts() {
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
    QObject::connect(shortcut, SIGNAL(activated()), area, SLOT(deleteLastPointIfExists()));
}

void MainWindow::changeActiveIndex(int i) {
    activeInd->setText("Active: " + QString::number(i));
}

void MainWindow::paintEvent(QPaintEvent *) {
    qDebug("Repainted MainWindow!");
}

MainWindow::~MainWindow()
{
}
