#include <QtGui>

#include <iostream>

#include "renderarea.h"
#include "bspline.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent), active_pen_color(QColor("black")),
      non_active_pen_color(QColor("gray")), selected_pen_color(QColor("blue"))
{
    penWidth = 1;
    setBackgroundRole(QPalette::Base);
    brush = QBrush();

    contours.push_back(Contour());
    changeActiveContour(0);

    selectPointAsDefault();
}

void RenderArea::setContours(std::vector<Contour> conts) {
    contours = conts;
    update();
}

int RenderArea::getActiveContourIndex() const {
    return active_contour_index;
}

int RenderArea::contoursSize() const {
    return contours.size();
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

    selectPointAsDefault();
    update();
}

void RenderArea::deleteActiveContour() {
    contours.erase(contours.begin() + active_contour_index);

    if (contours.size() == 0) {
        addNewActiveContour(Contour());
    }

    changeActiveContour(0);
    selectPointAsDefault();
}

void RenderArea::copyActiveContour() {
    contours.push_back(contours[active_contour_index]);
    update();
}

void RenderArea::moveActiveContour(int dx, int dy) {
    QPoint dif(dx, dy);

    Contour &c = contours[active_contour_index];
    for (int i = 0; i < c.size(); ++i) {
        c.set(i, c.at(i) + dif);
    }

    update();
}

void RenderArea::changeActiveContour(int i) {
    active_contour_index = i;
    update();
    emit activeIndexChanged(i);
    selectPointAsDefault();
}

int RenderArea::selectedPointIndex() const {
    return selected_point_index;
}

int RenderArea::activeContourSize() const {
    return contours[active_contour_index].size();
}

void RenderArea::selectPoint(int i) {
    selected_point_index = i;
    update();
}

void RenderArea::changeSelectedPoint(QPoint dx) {
    if (selected_point_index == -1)
        return;

    Contour &c = contours[active_contour_index];
    c.set(selected_point_index, c.at(selected_point_index) + dx);
    update();
}

QPainterPath RenderArea::constructActivePath(Contour c) {
    QPainterPath active_path;

    if (c.size() == 0) {
        return active_path;
    }

    active_path.moveTo(c.at(0));

    const int N = 20;
    float dt = 1.0f / N;

    for (int i = 1; i < c.size() - 2; ++i) {
        float t = 0.0f;
        for (int d = 0; d <= N; ++d) {
            QPoint p = BSpline::interpolate(c.at(i-1), c.at(i), c.at(i+1), c.at(i+2), t);
            t += dt;
            active_path.lineTo(p);
        }
    }

    return active_path;
}

void RenderArea::selectPointAsDefault() {
    selectPoint(contours[active_contour_index].size() - 1);
    update();
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
    if (ev->button() == Qt::LeftButton)
        c.push(p);
    else if (ev->button() == Qt::RightButton) {
        if (c.size() > 0) {
            c.push(c.at(0));
        }
    }

    update();
}


void RenderArea::paintEvent(QPaintEvent *)
{
    qDebug("Repainted RenderArea!");

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen activePen = QPen(QBrush(active_pen_color), penWidth, Qt::SolidLine, Qt::RoundCap,
                          Qt::RoundJoin);
    QPen nonActivePen = QPen(QBrush(non_active_pen_color), penWidth, Qt::SolidLine, Qt::RoundCap,
                             Qt::RoundJoin);

    painter.setPen(nonActivePen);

    painter.setBrush(brush);

    // Draw lines
    for (int i = 0; i < contours.size(); ++i) {
        if (i == active_contour_index)
            painter.setPen(activePen);

        QPainterPath active_path = constructActivePath(contours[i]);
        painter.drawPath(active_path);

        if (i == active_contour_index)
            painter.setPen(nonActivePen);
    }

    // Draw points of active curve
    QPen penForPoints(Qt::red);
    penForPoints.setCapStyle(Qt::RoundCap);
    penForPoints.setWidth(5);
    painter.setPen(penForPoints);

    Contour c = contours[active_contour_index];
    for (int i = 0; i < c.size() - 1; ++i) {
        painter.drawPoint(c.at(i));
    }

    if (c.size() > 0) {
        penForPoints.setColor(Qt::green);
        painter.setPen(penForPoints);
        painter.drawPoint(c.at(c.size() - 1));
    }

    //Draw selected point
    if (selected_point_index != -1) {
        penForPoints.setColor(selected_pen_color);
        painter.setPen(penForPoints);
        painter.drawPoint(c.at(selected_point_index));
    }

    painter.setPen(nonActivePen);
}
