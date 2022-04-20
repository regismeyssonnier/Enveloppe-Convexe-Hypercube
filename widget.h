#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QQuaternion>
#include "gl_widget.h"
#include "Trackball.h"




class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void Creer_Menu();
    void Fermer_App();

public:
    TrackBall *trackball;
    QQuaternion *qquat;

private:

    GLWidget *gl_widget;


protected:
    /*virtual void mouseMoveEvent ( QMouseEvent * event );
    virtual void mousePressEvent ( QMouseEvent * event );
    virtual void mouseReleaseEvent ( QMouseEvent * event );*/

};

#endif // WIDGET_H
