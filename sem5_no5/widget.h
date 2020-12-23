#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <square.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int width_of_Square = 60;
    int heith_of_Square = 60;

    bool is_Int = false;
    bool is_Int_Second = false;

    bool is_Int_Side = false;
    bool is_Int_Bottom = false;

    int step_of_paint = 0;

    Square *item;

private slots:
    void on_aEdit_textChanged();

    void on_bEdit_textChanged();

    void on_doButton_clicked();

    void on_stepButton_clicked();

    void on_reButton_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;

};
#endif // WIDGET_H
