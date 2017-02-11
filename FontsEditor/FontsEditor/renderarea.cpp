#include <QtGui>

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

void RenderArea::setPenColor(const QColor &color)
{
    penColor = color;
    update();
}

void RenderArea::updatePath(const QPainterPath &p) {
    path = p;
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

    painter.drawPath(path);
}
