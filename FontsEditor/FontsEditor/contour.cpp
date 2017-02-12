#include "contour.h"

Contour::Contour() {
}

Contour::Contour(QPoint startPoint) {
    points.push_back(startPoint);
}

Contour::Contour(std::vector<QPoint> pts) {
    points = pts;
}

int Contour::size() const {
    return points.size();
}

QPoint Contour::at(int i) {
    return points[i];
}

void Contour::set(int i, QPoint p) {
    points[i] = p;
}

void Contour::push(QPoint p) {
    points.push_back(p);
}

void Contour::pop() {
    points.pop_back();
}
