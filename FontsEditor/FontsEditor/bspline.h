#ifndef BSPLINE_H
#define BSPLINE_H

#include <QPoint>

class BSpline
{
public:
    BSpline();

    static QPoint interpolate(QPoint p1, QPoint p2, QPoint p3, QPoint p4, float t);
};

#endif // BSPLINE_H
