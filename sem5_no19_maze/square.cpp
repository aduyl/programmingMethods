#include "square.h"


Square::Square(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

Square::~Square()
{

}

QRectF Square::boundingRect() const
{
    return QRectF (0,0,2,2);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setPen(Qt::black);
//    painter->setBrush(QColor(210, 0, 57));
//    painter->drawRect(0,0,20,20);
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Square::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
    qDebug() << this->pos();

    if(!(this->collidingItems().isEmpty())){
        qDebug() << 1;
        QMessageBox msgBox;
        msgBox.setText("Вы проиграли");
        msgBox.exec();
        isFail();
    }
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    //qDebug() << 1;
    Q_UNUSED(event)
}

void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event)
}
