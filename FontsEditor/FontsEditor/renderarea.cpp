#include <QtGui>

#include <iostream>

#include "renderarea.h"

RenderArea::RenderArea(const QPainterPath &path, QWidget *parent)
    : QWidget(parent), path(path)
{
    penWidth = 1;
    setBackgroundRole(QPalette::Base);
    brush = QBrush(QColor("black"));
}

void RenderArea::setFillRule(Qt::FillRule rule)
{
    path.setFillRule(rule);
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
    qDebug("SWAP");
    QBrush emptyBrush;
    setBrush((brush == emptyBrush) ? QBrush(QColor("black")) : emptyBrush);
}

void RenderArea::setPenColor(const QColor &color)
{
    penColor = color;
    update();
}

void RenderArea::updatePath(const QPainterPath &p) {
    path = p;
    update();
}

void RenderArea::mousePressEvent( QMouseEvent* ev ) {
    QPoint p = ev->pos();

    std::cout << p.x() << " " << p.y() << std::endl;
    qDebug("Mouse pressed!");
    points.push_back(p);
    path = QPainterPath(points[0]);
    for (int i = 1; i < points.size(); ++i)
        path.lineTo(points[i]);

    updatePath(path);
}

void RenderArea::paintEvent(QPaintEvent *)
{
    qDebug("Repainted RenderArea!");
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    painter.setBrush(brush);

    painter.drawPath(path);
}
