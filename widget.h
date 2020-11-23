#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_squareEdit_textChanged();

    void on_circleEdit_textChanged();

    void on_doButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
