#include "widget.h"
#include "ui_widget.h"
#include <QtMath>
#include <QPointF>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

int squareCount = 0;
int circleCount = 0;

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this); // Создаём объект отрисовщика
    // Устанавливаем кисть абриса
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

        int Start = 20;
        int mainRadius = ui->widget->width()/(squareCount*2 + 1);

        for(int i = 0; i < squareCount; i++ ){

            painter.drawRect(Start, Start, mainRadius, mainRadius);
            //painter.drawEllipse(Start, Start, mainRadius, mainRadius);

                for (int j = 0; j < circleCount; j++) {

                    int radius = (mainRadius/2)*(j+1)/circleCount;

                    QPoint pointCenter;
                    pointCenter.setX(pointCenter.x() + Start + mainRadius/2);
                    pointCenter.setY(pointCenter.y() + Start + mainRadius/2);

                    painter.drawEllipse(pointCenter, radius, radius);
                }
                Start = Start + mainRadius;
        }
}


int countOfSquares;
int countOfCircles;
bool isIntSqauareCount = false;
bool isIntCircleCount = false;
bool is_int;
bool is_int_1;

void Widget::on_squareEdit_textChanged()
{
    QString from_inbox = ui->squareEdit->text();

    if (from_inbox != ""){
        countOfSquares = from_inbox.toInt(&is_int,10);
    }

    if (is_int && countOfSquares > 0) {
        isIntSqauareCount = true;
    }

    if (isIntCircleCount && isIntSqauareCount){
        ui->doButton->setEnabled(true);
        QString line = "Draw "+ QString::number(countOfCircles) + " circles in " + QString::number(countOfSquares) + " squares" ;
        ui->TaskTextEdit->setText(line);


    } else {
        isIntCircleCount = false;
        ui->doButton->setEnabled(false);
    }
}

void Widget::on_circleEdit_textChanged()
{
    QString from_inbox = ui->circleEdit->text();

    if (from_inbox != ""){
        countOfCircles = from_inbox.toInt(&is_int_1,10);
    }

    if (is_int_1 && countOfCircles > 0) {
        isIntCircleCount = true;
    }

    if (isIntCircleCount && isIntSqauareCount){
        ui->doButton->setEnabled(true);
        QString line = "Draw "+ QString::number(countOfCircles) + " circles in " + QString::number(countOfSquares) + " squares" ;
        ui->TaskTextEdit->setText(line);

    } else {
        isIntSqauareCount = false;
        ui->doButton->setEnabled(false);

    }
}

void Widget::on_doButton_clicked()
{
    squareCount = countOfSquares;
    circleCount = countOfCircles;
    repaint();
}

void Widget::on_clearButton_clicked()
{
    ui->circleEdit->clear();
    ui->squareEdit->clear();
    ui->doButton->setEnabled(false);
    ui->TaskTextEdit->clear();
    countOfSquares = 0;
    countOfCircles = 0;
    isIntSqauareCount = false;
    isIntCircleCount = false;
    squareCount = 0;
    circleCount = 0;
    repaint();
}
