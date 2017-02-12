#include <QtGui>

#include <iostream>

#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent), active_pen_color(QColor("black")), non_active_pen_color(QColor("gray"))
{
    penWidth = 1;
    setBackgroundRole(QPalette::Base);
    brush = QBrush();

    contours.push_back(Contour());
    changeActiveContour(0);
}

void RenderArea::setContours(std::vector<Contour> conts) {
    contours = conts;
    update();
}

int RenderArea::getActiveContourIndex() const {
    return active_contour_index;
}

void RenderArea::setPenWidth(int width)
{
    penWidth = width;
    update();
}

std::vector<Contour> RenderArea::getContours() const {
    return contours;
}

void RenderArea::setBrush(QBrush br)
{
    brush = br;
    update();
}

QBrush RenderArea::getBrush() const {
    return brush;
}

void RenderArea::swapBrush() {
    qDebug("Brush swapped");
    QBrush emptyBrush;
    setBrush((brush == emptyBrush) ? QBrush(QColor("black")) : emptyBrush);
}

void RenderArea::addNewActiveContour(Contour c) {
    qDebug("New Contour Started!");
    changeActiveContour(contours.size());
    contours.push_back(c);
    update();
}

void RenderArea::changeActiveContour(int i) {
    active_contour_index = i;
    emit activeIndexChanged(i);
}

QPainterPath RenderArea::constructActivePath(Contour c) {
    QPainterPath active_path;

    if (c.size() == 0) {
        return active_path;
    }

    active_path.moveTo(c.at(0));
    for (int i = 1; i < c.size(); ++i)
        active_path.lineTo(c.at(i));

    return active_path;
}

void RenderArea::deleteLastPointIfExists() {
    Contour &c = contours[active_contour_index];
    if (c.size() > 0) {
        c.pop();
    }

    update();
}

void RenderArea::mousePressEvent( QMouseEvent* ev ) {
    QPoint p = ev->pos();

    std::cout << p.x() << " " << p.y() << std::endl;
    qDebug("Mouse pressed!");

    Contour &c = contours[active_contour_index];
    c.push(p);

    update();
}

void RenderArea::paintEvent(QPaintEvent *)
{
    qDebug("Repainted RenderArea!");

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(QPen(QBrush(non_active_pen_color), penWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    painter.setBrush(brush);

    for (int i = 0; i < contours.size(); ++i) {
        if (i == active_contour_index)
            painter.setPen(QPen(QBrush(active_pen_color), penWidth, Qt::SolidLine, Qt::RoundCap,
                                Qt::RoundJoin));

        QPainterPath active_path = constructActivePath(contours[i]);
        painter.drawPath(active_path);

        if (i == active_contour_index)
            painter.setPen(QPen(QBrush(non_active_pen_color), penWidth, Qt::SolidLine, Qt::RoundCap,
                                Qt::RoundJoin));
    }
}
