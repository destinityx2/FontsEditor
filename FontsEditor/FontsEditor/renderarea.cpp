#include <QtGui>

#include <iostream>

#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    penWidth = 1;
    setBackgroundRole(QPalette::Base);
    brush = QBrush();

    contours.push_back(Contour());
    changeActiveContour(0);
}

void RenderArea::setFillRule(Qt::FillRule rule)
{
    active_path.setFillRule(rule);
    update();
}

void RenderArea::setPenWidth(int width)
{
    penWidth = width;
    update();
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

void RenderArea::setPenColor(const QColor &color)
{
    penColor = color;
    update();
}

void RenderArea::addNewActiveContour(Contour c) {
    qDebug("New Contour Started!");
    changeActiveContour(contours.size());
    contours.push_back(c);
}

void RenderArea::changeActiveContour(int i) {
    active_contour_index = i;
    emit activeIndexChanged(i);
}

void RenderArea::constructActivePath(Contour c) {
    if (c.size() == 0) {
        active_path = QPainterPath();
        return;
    }

    active_path = QPainterPath(c.at(0));
    for (int i = 1; i < c.size(); ++i)
        active_path.lineTo(c.at(i));
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

    painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    painter.setBrush(brush);

    for (int i = 0; i < contours.size(); ++i) {
        constructActivePath(contours[i]);
        painter.drawPath(active_path);
    }
}
