#ifndef CYRCLES_H
#define CYRCLES_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class Cyrcles: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Cyrcles(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Cyrcles();
    int radius = 0;
    int number = 0;
    QPoint center;

public slots:
    QRectF boundingRect() const;
    void reseveRadius(int rad);
    void reseveNumber(int num);

private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // CYRCLES_H
