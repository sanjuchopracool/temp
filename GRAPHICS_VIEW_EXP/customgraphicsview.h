#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QGraphicsView>

class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    CustomGraphicsView(QWidget *parent = 0);
    ~CustomGraphicsView();

protected:
    void wheelEvent(QWheelEvent *) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    void setupMatrix();

private:
    bool panning = false;
    QPoint lastPos;
};

#endif // CUSTOMGRAPHICSVIEW_H
