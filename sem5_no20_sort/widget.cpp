#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->resize(1000,840);  // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView

    // Включение обрабоки сигналов от мыши для graphicsView
    ui->graphicsView->setMouseTracking(true);


    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    scene->setSceneRect(0,0,1000,840); // Устанавливаем размер сцены
    pole = new SquarePole();
    pole->boundingRect();
    pole->setPos(20, 300);
    scene->addItem(pole);
//    first = new Cyrcles();
//    second = new Cyrcles();
//    third = new Cyrcles();
//    fourth = new Cyrcles();
//    fifth = new Cyrcles();
//    pole = new SquarePole();

}

Widget::~Widget()
{
    delete ui;
    delete scene;
}

void Widget::failMessage()
{
    delete first;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    ui->checkButton->setEnabled(false);

}


void Widget::on_doButton_clicked()
{

    first = new Cyrcles();
    second = new Cyrcles();
    third = new Cyrcles();
    fourth = new Cyrcles();
    fifth = new Cyrcles();


    srand(time(NULL));
    ui->checkButton->setEnabled(true);
    for(int i = 0; i < 5; i++){
        QVector<int> temp;
        temp.push_back(qrand() % 190 + 20);
        temp.push_back(qrand() % 90 + 10);
        temp.push_back(i);
        cyrcles.push_back(temp);
        temp.clear();
    }
    qDebug() << cyrcles;
    first->reseveNumber(cyrcles[0][1]);
    first->reseveRadius(cyrcles[0][0]);
    first->boundingRect();
    first->setPos(20, 20);
    scene->addItem(first);

    second->reseveNumber(cyrcles[1][1]);
    second->reseveRadius(cyrcles[1][0]);
    second->boundingRect();
    second->setPos(220, 20);
    scene->addItem(second);

    third->reseveNumber(cyrcles[2][1]);
    third->reseveRadius(cyrcles[2][0]);
    third->boundingRect();
    third->setPos(420, 20);
    scene->addItem(third);

    fourth->reseveNumber(cyrcles[3][1]);
    fourth->reseveRadius(cyrcles[3][0]);
    fourth->boundingRect();
    fourth->setPos(620, 20);
    scene->addItem(fourth);

    fifth->reseveNumber(cyrcles[4][1]);
    fifth->reseveRadius(cyrcles[4][0]);
    fifth->boundingRect();
    fifth->setPos(820, 20);
    scene->addItem(fifth);

    for (int i = 0; i < 5; i++) {
        cyrcles[i].push_back(0);
        cyrcles[i].push_back(0);
    }

}

void Widget::on_checkButton_clicked()
{

    QVector<QVector<int>> nevCheckable = cyrcles;
    bool chek = true;
    int firstX = static_cast<int>((first->pos()).x());
    int secondX = static_cast<int>((second->pos()).x());
    int thirdX = static_cast<int>((third->pos()).x());
    int fourthX = static_cast<int>((fourth->pos()).x());
    int fifthX = static_cast<int>((fifth->pos()).x());
    nevCheckable[0][3] = (firstX);
    nevCheckable[1][3] =(secondX);
    nevCheckable[2][3] =(thirdX);
    nevCheckable[3][3] =(fourthX);
    nevCheckable[4][3] =(fifthX);
    qDebug() << nevCheckable;

    int firstY = static_cast<int>((first->pos()).y());
    int secondY = static_cast<int>((second->pos()).y());
    int thirdY = static_cast<int>((third->pos()).y());
    int fourthY = static_cast<int>((fourth->pos()).y());
    int fifthY = static_cast<int>((fifth->pos()).y());

    nevCheckable[0][4] = (firstY);
    nevCheckable[1][4] =(secondY);
    nevCheckable[2][4] =(thirdY);
    nevCheckable[3][4] =(fourthY);
    nevCheckable[4][4] =(fifthY);

    for (int i = 0; i < 5; i++) {
        qDebug() << nevCheckable[i][3] + nevCheckable[i][0] / 2;
        if(nevCheckable[i][4] + nevCheckable[i][0] / 2 > 520 || nevCheckable[i][4] < 300){
            QMessageBox msgBox;
            msgBox.setText("Неправильная расстановка!");
            msgBox.exec();
            chek = false;
            //cyrcles.clear();
            break;
        }
    }

    QVector<int> temp;
    for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 - i; j++) {
                if (nevCheckable[j][1] > nevCheckable[j + 1][1]) {
                    // меняем элементы местами
                    temp = nevCheckable[j];
                    nevCheckable[j] = nevCheckable[j + 1];
                    nevCheckable[j + 1] = temp;
                }
            }
        }

    for(int i = 0; i < 5; i++){
        if((i * 220 + 20 > nevCheckable[i][3]) || ((i + 1) * 220 + 20 < nevCheckable[i][3] + nevCheckable[i][0])){
            QMessageBox msgBox;
            msgBox.setText("Неправильная расстановка!");
            msgBox.exec();
            chek = false;
            //cyrcles.clear();
            break;
        }
    }

    for(int i = 0; i < 4; i++){
        if(nevCheckable[i][3] > nevCheckable[i + 1][3]){
            QMessageBox msgBox;
            msgBox.setText("Неправильная расстановка!");
            msgBox.exec();
            chek = false;
            //cyrcles.clear();
            break;

            //failMessage();

        }
    }

    if(chek){
        QMessageBox msgBox;
        msgBox.setText("Правильная расстановка!");
        msgBox.exec();
        failMessage();
        cyrcles.clear();
        first = new Cyrcles();
        second = new Cyrcles();
        third = new Cyrcles();
        fourth = new Cyrcles();
        fifth = new Cyrcles();
    }


}

void Widget::on_reButton_clicked()
{

    cyrcles.clear();
    failMessage();
    first = new Cyrcles();
    second = new Cyrcles();
    third = new Cyrcles();
    fourth = new Cyrcles();
    fifth = new Cyrcles();
}
