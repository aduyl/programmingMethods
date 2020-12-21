#include "cyrcles.h"

Cyrcles::Cyrcles(QObject *parent) :
  QObject(parent), QGraphicsItem()
{

}

Cyrcles::~Cyrcles()
{

}

QRectF Cyrcles::boundingRect() const
{
    return QRectF(0, 0, radius, radius);
}

void Cyrcles::reseveRadius(int rad)
{
    radius = rad;
}

void Cyrcles::reseveNumber(int num)
{
    number = num;
}

void Cyrcles::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    //qDebug() << event->pos();
    this->setPos(mapToScene(event->pos()));
}

void Cyrcles::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event)
}

void Cyrcles::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event)
}

void Cyrcles::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(144, 12, 63));
    center.setX(radius / 2);
    center.setY(radius / 2);
    painter->drawEllipse(center, radius/2, radius/2);
    painter->drawText(center.x() - 10, center.y(), QString::number(number));
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

