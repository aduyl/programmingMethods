#include "playpole.h"


PlayPole::PlayPole(QObject *parent):
    QObject(parent), QGraphicsItem()
{

}

PlayPole::~PlayPole()
{

}

void PlayPole::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPoint startPoint;
    QPoint finPoint;
    QPoint pointSecond;
    QPoint secondFin;

    painter->setPen(QPen(QColor(0, 0, 0), 2, Qt::SolidLine, Qt::FlatCap));
    painter->drawRect(0,0,600,600);
    painter->setBrush(QColor(255, 99, 71));
    painter->drawRect(0, 570, 30, 30);
    painter->setBrush(QColor(65, 105, 225));
    painter->drawRect(570, 0, 30, 30);


    painter->setPen(QPen(QColor(1, 1, 1), 2, Qt::SolidLine, Qt::FlatCap));
    //srand(time(NULL));
    segment = 600 / level;
    startPoint.setX(0);
    startPoint.setY(570);
    pointSecond.setX(30);
    pointSecond.setY(600);
    for(int i = 0; i < level - 1; i++){
        int x = segment * (i + 1);
        int y = qrand() % 100 + 150;
        int xx = segment * (i + 1) + 30;
        int yy;
        int x1 = startPoint.x();
        int x2 = x;
        int x3 = pointSecond.x();
        int x4 = xx;
        int y1 = startPoint.y();
        int y2 = y;
        int y3 = pointSecond.y(); // % ((high + 1) - low) + low
        do{
            yy =qrand() % (400 - (y + 30)) + y + 30;

        }while((x1 * y2 - x2 * y1)*(x4 - x3) - (x3 * yy - x4 * y3)*(x2 - x1) == 0 || (x1 * y2 - x2 * y1)*(yy - y3) - (x3 * yy - x4 * y3)*(y2 - y1) == 0 );


        finPoint.setX(x);
        finPoint.setY(y);
        secondFin.setX(xx);
        secondFin.setY(yy);
        painter->drawLine(startPoint, finPoint);
        painter->drawLine(pointSecond, secondFin);
        startPoint = finPoint;
        pointSecond = secondFin;
    }
    painter->drawLine(startPoint.x(), startPoint.y(), 570, 0);
    painter->drawLine(pointSecond.x(), pointSecond.y(), 600, 30);
    startPoint.setX(0);
    startPoint.setY(0);


    Q_UNUSED(option)
    Q_UNUSED(widget)
}



void PlayPole::getLevel(int Level)
{
    level = Level;
}




QRectF PlayPole::boundingRect() const
{
    return QRectF(0,0,605,605);
}
