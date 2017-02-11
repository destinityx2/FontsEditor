#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QPainterPath>
#include <QWidget>
#include <QBrush>

#include <vector>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    RenderArea(const QPainterPath &path, QWidget *parent = 0);

public slots:
    void setFillRule(Qt::FillRule rule);
    void setPenWidth(int width);
    void setPenColor(const QColor &color);
    void setBrush(QBrush br);
    void updatePath(const QPainterPath &p);

public:
    void mousePressEvent( QMouseEvent* ev );

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPainterPath path;
    QBrush brush;
    int penWidth;
    QColor penColor;

    std::vector<QPoint> points;
};

#endif
