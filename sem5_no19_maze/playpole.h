#ifndef PLAYPOLE_H
#define PLAYPOLE_H


#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtMath>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class PlayPole: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit PlayPole(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~PlayPole();

    int level = 1;
    int segment = 600 / level - 30;
    int k = 1;

    void getLevel(int Level);

//private:
//    QPointF     previousPoint;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
public slots:
    QRectF boundingRect() const;
};

#endif // PLAYPOLE_H

