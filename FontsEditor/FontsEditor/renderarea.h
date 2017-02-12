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
    void setFillRule(Qt::FillRule rule);
    void setPenWidth(int width);
    void setPenColor(const QColor &color);
    void setBrush(QBrush br);
    void swapBrush();
    void addNewActiveContour(Contour c);
    void changeActiveContour(int i);
    void deleteLastPointIfExists();

    QBrush getBrush() const;

public:
    void mousePressEvent( QMouseEvent* ev );

protected:
    void paintEvent(QPaintEvent *event);

private:
    QBrush brush;
    int penWidth;
    QColor penColor;

    QPainterPath active_path;

    std::vector<Contour> contours;
    int active_contour_index;

    void constructActivePath(Contour c);
};

#endif
