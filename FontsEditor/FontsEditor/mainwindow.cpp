#include "mainwindow.h"
#include "renderarea.h"
#include "contour.h"

#include <QMouseEvent>
#include <iostream>
#include <QShortcut>
#include <QFileDialog>
#include <QTextStream>
#include <QMenuBar>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    area = new RenderArea();
    setCentralWidget(area);

    configureMenu();

    resize(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void MainWindow::configureMenu() {
    // Create menu
    file = menuBar()->addMenu(tr("&File"));
    save = file->addAction(tr("&Save"));
    load = file->addAction(tr("&Load"));

    edit = menuBar()->addMenu(tr("&Edit"));

    undo = edit->addAction(tr("&Undo"));
//    changeFillingeMode = edit->addAction(tr("&Change Filling Mode"));
    startNewContour = edit->addAction(tr("&Start New Contour"));

    edit->addSeparator();

    del = edit->addAction(tr("&Delete"));
    copy = edit->addAction(tr("&Copy"));

    activeInd = menuBar()->addAction(tr("Active: 0"));

    // Set connections
    connect(undo, SIGNAL(triggered(bool)), area, SLOT(deleteLastPointIfExists()));
//    connect(changeFillingeMode, SIGNAL(triggered(bool)), area, SLOT(swapBrush()));
    connect(startNewContour, SIGNAL(triggered(bool)), this, SLOT(addNewContour()));

    connect(area, SIGNAL(activeIndexChanged(int)), this, SLOT(changeActiveIndex(int)));
    connect(activeInd, SIGNAL(triggered(bool)), this, SLOT(nextContour()));

    connect(save, SIGNAL(triggered(bool)), this, SLOT(saveFile()));
    connect(load, SIGNAL(triggered(bool)), this, SLOT(loadFile()));

    connect(del, SIGNAL(triggered(bool)), area, SLOT(deleteActiveContour()));
    connect(copy, SIGNAL(triggered(bool)), area, SLOT(copyActiveContour()));

    // Set shortcuts
    setShortcuts();
}

// (?)TODO: ADD OPPORTUNITY TO CHANGE PEN SIZE
/**
 * Output file syntax:
 * <NUMBER_OF_CONTOURS> <ACTIVE_CONTOUR_INDEX>
 * <N_POINTS> <p1_x> <p1_y> <p2_x> <p2_y> <p3_x> <p3_y> ...
 * <N_POINTS> <p1_x> <p1_y> <p2_x> <p2_y> <p3_x> <p3_y> ...
 * ...
 *
 * After the first line containing "N", there are "N" contours.
 */
void MainWindow::saveFile() const {
    std::vector<Contour> contours = area->getContours();

    QString filename = QFileDialog::getSaveFileName();
    QFile f(filename);
    if (!f.open(QIODevice::WriteOnly))
        return;

    QTextStream stream(&f);

    stream << contours.size() << " " << area->getActiveContourIndex() << endl;
    for (int k = 0; k < contours.size(); ++k) {
        Contour c = contours[k];

        stream << c.size() << " ";
        for (int i = 0; i < c.size(); ++i) {
            QPoint p = c.at(i);

            stream << p.x() << " " << p.y() << " ";
        }
        stream << endl;
    }

    f.close();
}

void MainWindow::loadFile() {
    std::vector<Contour> contours;

    QString filename = QFileDialog::getOpenFileName();
    QFile f(filename);

    if (!f.open(QIODevice::ReadOnly))
        return;

    QTextStream stream(&f);

    int nContours = 0;
    int activeContourIndex = 0;

    stream >> nContours >> activeContourIndex;

    for (int i = 0; i < nContours; ++i) {
        Contour c;
        int nPoints;
        stream >> nPoints;

        for (int j = 0; j < nPoints; ++j) {
            int x, y;
            stream >> x >> y;
            c.push(QPoint(x, y));
        }
        contours.push_back(c);
    }

    area->setContours(contours);
    area->changeActiveContour(activeContourIndex);
}

void MainWindow::addNewContour() {
    area->addNewActiveContour(Contour());
}

void MainWindow::nextContour() {
    int nextIndex = (area->getActiveContourIndex() + 1) % area->contoursSize();
    area->changeActiveContour(nextIndex);
}

void MainWindow::setShortcuts() {
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
    QObject::connect(shortcut, SIGNAL(activated()), area, SLOT(deleteLastPointIfExists()));

    shortcut = new QShortcut(QKeySequence("Del"), this);
    QObject::connect(shortcut, SIGNAL(activated()), area, SLOT(deleteActiveContour()));
}

void MainWindow::changeActiveIndex(int i) {
    activeInd->setText("Active: " + QString::number(i));
}

void MainWindow::paintEvent(QPaintEvent *) {
    qDebug("Repainted MainWindow!");
}

void MainWindow::keyPressEvent(QKeyEvent *ev) {

    const int CONTOUR_STEP_SIZE = 3;
    const int POINT_STEP_SIZE = 1;

    // Process contour
    int key = ev->key();
    int dx = 0;
    int dy = 0;

    if (key == Qt::Key_Right) {
        dx = CONTOUR_STEP_SIZE;
    } else if (key == Qt::Key_Left) {
        dx = -CONTOUR_STEP_SIZE;
    } else if (key == Qt::Key_Up) {
        dy = -CONTOUR_STEP_SIZE;
    } else if (key == Qt::Key_Down) {
        dy = CONTOUR_STEP_SIZE;
    }

    if (dx != 0 || dy != 0) {
        area->moveActiveContour(dx, dy);
    }

    // Process point
    dx = 0;
    dy = 0;

    if (key == Qt::Key_D) {
        dx = CONTOUR_STEP_SIZE;
    } else if (key == Qt::Key_A) {
        dx = -CONTOUR_STEP_SIZE;
    } else if (key == Qt::Key_W) {
        dy = -CONTOUR_STEP_SIZE;
    } else if (key == Qt::Key_S) {
        dy = CONTOUR_STEP_SIZE;
    }

    if (dx != 0 || dy != 0) {
        area->changeSelectedPoint(QPoint(dx, dy));
    }

    // Process next point
    if (key == Qt::Key_P) {
        area->selectPoint((area->selectedPointIndex() + 1) % area->activeContourSize());
    } else if (key == Qt::Key_O) {
        int newInd = area->selectedPointIndex() - 1;
        if (newInd < 0)
            newInd += area->activeContourSize();

        area->selectPoint(newInd);
    }
}

MainWindow::~MainWindow()
{
}
