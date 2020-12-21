#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
     Scene();

     int posx = 0;
     int posy = 0;

private:
     bool isPressed = false;
     QPointF     previousPoint;


signals:
    void isFail();
    void isVin();

private slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SCENE_H
