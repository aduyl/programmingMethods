#include "squarepole.h"


SquarePole::SquarePole(QObject *parent) :
  QObject(parent), QGraphicsItem()
{

}

void SquarePole::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int xx = 0;
    int yy = 0;
    painter->setPen(QColor(0, 139, 139));
    for(int i = 0; i < 5; i++){
        painter->drawRect(xx, yy, 220, 220);
        xx = xx + 220;
    }

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

SquarePole::~SquarePole()
{

}

QRectF SquarePole::boundingRect() const
{
    return QRectF(0, 0, 1100, 220);
}
