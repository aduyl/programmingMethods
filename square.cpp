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
    return QRectF (0,0,width_sq + 100,heith_sq + 100);
}

void Square::reseveWidthAndHeith(int squareWidth, int squareHeith)
{
    width_sq = squareWidth;
    heith_sq = squareHeith;
}

void Square::reseveStep(int step)
{
    step_of_paint = step;
}



void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(0,0,0));
    painter->drawRect(0, 0, width_sq, heith_sq);
    QPointF first;
    first.setX(0);
    first.setY(0);

    QPointF second;
    second.setX(0);
    second.setY(heith_sq);

    QPointF third;
    third.setX(width_sq);
    third.setY(heith_sq);

    QPointF fourth;
    fourth.setX(width_sq);
    fourth.setY(0);


//    previous_point.setX(0);
//    previous_point.setY(0);

//    QPointF new_point;
//    new_point.setX(qMin(square_width, square_heith));
//    new_point.setY(qMin(square_width, square_heith));

  //  int max_var = qMax(square_width, square_heith);

    QPointF vec;
    vec.setX(1);
    vec.setY(-1);

    for(int i = 0; i < step_of_paint; i++){
        previous_point.setX(0);
        previous_point.setY(0);
        QPointF new_point;
        int angle = 3;
        int side;
        if(heith_sq > width_sq){
            side = -4;
        }else{
            side = -2;
        }

        qDebug() << "side " << side << " angle " << angle;

        if(angle == 3){
            if(side == -2){
                if(static_cast<int>(previous_point.x()) == 0){
                    new_point.setX(heith_sq - previous_point.y());
                    qDebug() << new_point.x();
                }else{

                    new_point.setX(heith_sq + previous_point.y());
                    qDebug() << new_point.x();
                }
                new_point.setY(heith_sq);
                side = -4;

            }else if(side == -4){
                new_point.setX(width_sq);
                if(static_cast<int>(previous_point.y()) == 0){
                    new_point.setY(width_sq - previous_point.x());
                }else{
                    new_point.setY(width_sq + previous_point.x());
                }
                side = -2;
            }

        }else if( angle == -1){
            if(side == -2){
                if(static_cast<int>(previous_point.x()) == width_sq){
                    new_point.setX(width_sq - previous_point.y());
                }else{
                    new_point.setX(width_sq + previous_point.x());
                }
                new_point.setY(heith_sq);
                side = 4;

            }else if(side == 4){
                new_point.setX(0);
                if(static_cast<int>(previous_point.y()) == 0){
                    new_point.setY(previous_point.x());
                }else{
                    new_point.setY(width_sq + previous_point.y());
                }
                side = -2;
            }

        }else if(angle == 1){
            if(side == 2){
                if(static_cast<int>(previous_point.x()) == 0){
                    new_point.setX(previous_point.y());
                }else{
                    new_point.setX(heith_sq + previous_point.x());
                }
                new_point.setY(0);
                side = -4;

            }else if(side == -4){
                new_point.setX(width_sq);
                if(static_cast<int>(previous_point.y()) == heith_sq){
                    new_point.setY(heith_sq - (width_sq - previous_point.x()));
                }else{
                    new_point.setY(previous_point.y() - width_sq);
                }
                side = 2;
            }

        }else if(angle == -3){
            if(side == 2){
                if(static_cast<int>(previous_point.x()) == width_sq){
                    new_point.setX(width_sq - previous_point.y());
                }else{
                    new_point.setX(width_sq - previous_point.x());
                }
                new_point.setY(0);
                side = 4;

            }else if(side == 4){
                new_point.setX(0);
                if(static_cast<int>(previous_point.y()) == heith_sq){
                    new_point.setY(heith_sq - previous_point.x());
                }else{
                    new_point.setY(heith_sq - (width_sq + previous_point.y()));
                }
                side = 2;
            }
        }
        painter->drawLine(previous_point, new_point);
        previous_point = new_point;
        angle = angle + side;

    }

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
