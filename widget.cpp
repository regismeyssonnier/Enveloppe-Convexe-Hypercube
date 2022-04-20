#include "widget.h"
#include "ui_widget.h"
#include "Trackball.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    qquat = new QQuaternion();

    this->setWindowTitle("Projet Hypercube - Régis Meyssonnier - M2 SIS IN");

    gl_widget = new GLWidget(parent);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(gl_widget);
    setLayout(mainLayout);


}

void Widget::Fermer_App()
{
    this->close();
}



/*
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        this->trackball->move(event->pos(), trackball->rotation().conjugate());
        event->accept();
     } else {
        this->trackball->release(event->pos(), trackball->rotation().conjugate());
     }

}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        this->trackball->push(event->pos(), trackball->rotation().conjugate());
        event->accept();
    }

}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        this->trackball->release(event->pos(), trackball->rotation().conjugate());
        event->accept();
    }

}
*/



Widget::~Widget()
{

    delete trackball;
}
