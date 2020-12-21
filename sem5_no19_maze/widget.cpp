#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new Scene();
    rect = new PlayPole();
    mouse = new Square();
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов


    ui->graphicsView->resize(600,640);  // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView

    // Включение обрабоки сигналов от мыши для graphicsView
    ui->graphicsView->setMouseTracking(true);


    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    scene->setSceneRect(0,0,600,640); // Устанавливаем размер сцены

    connect(scene, &Scene::isFail, this, &Widget::slotFromScene);
    connect(mouse, &Square::isFail, this, &Widget::slotFromScene);
    connect(scene, &Scene::isVin, this, &Widget::winSlot);


}

Widget::~Widget()
{
    delete ui;
    delete scene;
}

void Widget::slotFromScene(){
    scene->clear();
    scene->removeItem(rect);
    scene->removeItem(mouse);
    delete scene;
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    rect = new PlayPole();
    mouse = new Square();
    rect->getLevel(level);
    rect->boundingRect();
    rect->setPos(10,10);
    scene->addItem(rect);
    scene->addItem(mouse);
    ui->lineEdit->setText(QString::number(level));
}

void Widget::winSlot()
{
    scene->removeItem(rect);
    delete scene;
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    ui->lineEdit->setText("1");
}

void Widget::on_lineEdit_textChanged()
{

    QString from_inbox = ui->lineEdit->text();

    if (from_inbox != ""){
        level = from_inbox.toInt(&isInt,10);
    }

    rect->getLevel(level);

}

void Widget::on_playButton_clicked()
{
    rect = new PlayPole();
    mouse = new Square();

    rect->getLevel(level);
    rect->boundingRect();
    rect->setPos(10,10);
    scene->addItem(rect);
    scene->addItem(mouse);

}

void Widget::on_reButton_clicked()
{
    scene->removeItem(rect);
    scene->removeItem(mouse);
    delete scene;
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    ui->lineEdit->setText("1");

}


