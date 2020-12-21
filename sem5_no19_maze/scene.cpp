#include "scene.h"

#include "scene.h"


Scene::Scene()
{

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->scenePos().x() > 30 || event->scenePos().x() < 10) || (event->scenePos().y() < 570 || event->scenePos().y() > 600)){
        qDebug() << event->scenePos();
        QMessageBox msgBox;
        msgBox.setText("Вы проиграли");
        msgBox.exec();
        isPressed = false;
        isFail();
    }else{
        addEllipse(event->scenePos().x(),
                       event->scenePos().y(),
                       2,
                       2,
                       QPen(Qt::NoPen),
                       QBrush(QColor(0, 0, 0)));
            // Сохраняем координаты точки нажатия
            previousPoint = event->scenePos();
        isPressed = true;
    }

}


void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(isPressed){
        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(QColor(0, 0, 0), 1 ,Qt::SolidLine,Qt::RoundCap));
        // Обновляем данные о предыдущей координате
        previousPoint = event->scenePos();
    }
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    isPressed = false;
    if((event->scenePos().y() > 30 || event->scenePos().y() < 10) || (event->scenePos().x() < 570 || event->scenePos().x() > 600)){
        QMessageBox msgBox;
        msgBox.setText("Вы проиграли");
        msgBox.exec();
        isFail();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Вы выйграли! Поздравляем!");
        msgBox.exec();
        isVin();
    }
}


