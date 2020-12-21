#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QScrollArea>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtMath>
#include <QVector>
#include <cyrcles.h>
#include <squarepole.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void failMessage();

    QVector<QVector<int>> cyrcles;
    Cyrcles *first;
    Cyrcles *second;
    Cyrcles *third;
    Cyrcles *fourth;
    Cyrcles *fifth;
    SquarePole *pole;


private slots:
    void on_doButton_clicked();

    void on_checkButton_clicked();

    void on_reButton_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
};
#endif // WIDGET_H
