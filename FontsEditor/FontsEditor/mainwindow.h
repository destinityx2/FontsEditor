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

public slots:
    void addNewContour();
    void changeActiveIndex(int i);
    void saveFile() const;
    void loadFile();
    void nextContour();

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *ev);
    ~MainWindow();

    const static int WINDOW_WIDTH = 300;
    const static int WINDOW_HEIGHT = 300;

private:
    RenderArea *area;

    void configureMenu();
    void setShortcuts();

    // Menu
    QMenu *file;
    QAction *save;
    QAction *load;

    QMenu *edit;

    QAction *undo;
//    QAction *changeFillingeMode;
    QAction *startNewContour;

    QAction *del;
    QAction *copy;

    QAction *activeInd;
};

#endif // MAINWINDOW_H
