#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QPainterPath>
#include <QWidget>
#include <QBrush>

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

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPainterPath path;
    QColor fillColor1;
    QColor fillColor2;
    QBrush brush;
    int penWidth;
    QColor penColor;
};

#endif
