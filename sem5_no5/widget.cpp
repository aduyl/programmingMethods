#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(1000,1000);          // Устанавливаем размеры окна приложения
    //this->setFixedSize(700,700);

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов


    ui->graphicsView->resize(690,690);  // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);


    scene->setSceneRect(0,0,690,690); // Устанавливаем размер сцены
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_aEdit_textChanged()
{
    QString from_inbox = ui->aEdit->text();

    if (from_inbox != ""){
        width_of_Square = from_inbox.toInt(&is_Int,10);
    }

    if (is_Int && width_of_Square > 0) {
        is_Int_Bottom = true;
    }else{
        is_Int_Bottom = false;
    }


    if (is_Int_Side && is_Int_Bottom){
        ui->doButton->setEnabled(true);

    } else {
        is_Int_Side = false;
        ui->doButton->setEnabled(false);
    }
}

void Widget::on_bEdit_textChanged()
{
    QString from_inbox = ui->bEdit->text();

    if (from_inbox != ""){
        heith_of_Square = from_inbox.toInt(&is_Int_Second,10);
    }

    if (is_Int_Second && heith_of_Square > 0) {
        is_Int_Side = true;
    }else{
        is_Int_Side = false;
    }


    if (is_Int_Side && is_Int_Bottom){
        ui->doButton->setEnabled(true);

    } else {
        is_Int_Bottom = false;
        ui->doButton->setEnabled(false);
    }
}

void Widget::on_doButton_clicked()
{
    ui->stepButton->setEnabled(true);
    item = new Square();
    item->reseveWidthAndHeith(width_of_Square, heith_of_Square);
    item->boundingRect();
    item->setPos(345 - width_of_Square / 2, 345 - heith_of_Square / 2);
    scene->addItem(item);

}

void Widget::on_stepButton_clicked()
{
    step_of_paint++;
    delete item;
    item = new Square();
    item->reseveStep(step_of_paint);
    item->reseveWidthAndHeith(width_of_Square, heith_of_Square);
    item->boundingRect();
    item->setPos(345 - width_of_Square / 2, 345 - heith_of_Square / 2);
    scene->addItem(item);

}

void Widget::on_reButton_clicked()
{
    step_of_paint = 0;
    ui->aEdit->clear();
    ui->bEdit->clear();
    ui->stepButton->setEnabled(false);
    scene->removeItem(item);
    delete scene;

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->doButton->setEnabled(false);
}
