#include "bspline.h"

BSpline::BSpline() {

}

QPoint BSpline::interpolate(QPoint p1, QPoint p2, QPoint p3, QPoint p4, float t) {
    float s = 1.0f - t;
    float t2 = t * t;
    float t3 = t2 * t;

    return (s*s*s * p1 + (3*t3 - 6*t2 + 4) * p2 + (-3*t3 + 3*t2 + 3*t + 1)*p3 + t3*p4) / 6.0f;
}
