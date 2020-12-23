#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QtMath>

class Square : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Square(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Square();
    int width_sq = 60;
    int heith_sq = 60;
    int R_gb = qrand() % (255 + 1);
    int r_G_b = qrand() % (255 + 1);
    int rg_B = qrand() % (255 + 1);
    int step_of_paint = 0;

    QPointF previous_point;


public slots:
    QRectF boundingRect() const;
    void reseveWidthAndHeith(int squareWidth, int squareHeith);
    void reseveStep(int step);

};

#endif // SQUARE_H
