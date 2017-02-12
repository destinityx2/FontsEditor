#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QPainterPath>
#include <QWidget>
#include <QBrush>

#include <vector>

#include "contour.h"

class RenderArea : public QWidget
{
    Q_OBJECT

signals:
    void activeIndexChanged(int);

public:
    RenderArea(QWidget *parent = 0);

public slots:
    void setPenWidth(int width);
    void setBrush(QBrush br);
    void swapBrush();
    void addNewActiveContour(Contour c);
    void changeActiveContour(int i);
    void deleteLastPointIfExists();

    void setContours(std::vector<Contour> conts);

    QBrush getBrush() const;
    int getActiveContourIndex() const;

public:
    void mousePressEvent( QMouseEvent* ev );
    std::vector<Contour> getContours() const;
    int contoursSize() const;

    const QColor active_pen_color;
    const QColor non_active_pen_color;

protected:
    void paintEvent(QPaintEvent *event);

private:
    QBrush brush;
    int penWidth;

    std::vector<Contour> contours;
    int active_contour_index;

    QPainterPath constructActivePath(Contour c);
};

#endif
