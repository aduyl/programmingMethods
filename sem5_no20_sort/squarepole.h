#ifndef SQUAREPOLE_H
#define SQUAREPOLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class SquarePole: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit SquarePole(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~SquarePole();

public slots:
    QRectF boundingRect() const;

};

#endif // SQUAREPOLE_H
