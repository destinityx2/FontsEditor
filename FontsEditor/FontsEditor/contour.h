#ifndef CONTOUR_H
#define CONTOUR_H

#include <QPoint>
#include <vector>

class Contour
{
public:
    Contour();
    Contour(QPoint startPoint);
    Contour(std::vector<QPoint> pts);

    int size() const;
    QPoint at(int i);
    void push(QPoint p);
    void pop();

private:
    std::vector<QPoint> points;
};

#endif // CONTOUR_H
