#ifndef WIDGET_NEW_HYP_H
#define WIDGET_NEW_HYP_H

#include <QWidget>
#include <QtGui>
#include <QCheckBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLayout>
#include <QAction>
#include "Hypercube_aff.h"
#include "gl_widget.h"




class Widget_New_Hyp : public QWidget
{
    Q_OBJECT

    //Constructeur et Destructeur
public:
    explicit Widget_New_Hyp(QWidget *parent = 0);
    ~Widget_New_Hyp();

    //Variable public
private:
    QCheckBox check[16];
    QVBoxLayout vbox;
    QGroupBox groupbox;
    QVBoxLayout qlay;


    //Methode public
public:
    void Set_Etat_Sommet(bool etat);


    //slots privé
private slots:
    void Cocher_sommet1();
    void Cocher_sommet2();
    void Cocher_sommet3();
    void Cocher_sommet4();
    void Cocher_sommet5();
    void Cocher_sommet6();
    void Cocher_sommet7();
    void Cocher_sommet8();
    void Cocher_sommet9();
    void Cocher_sommet10();
    void Cocher_sommet11();
    void Cocher_sommet12();
    void Cocher_sommet13();
    void Cocher_sommet14();
    void Cocher_sommet15();
    void Cocher_sommet16();


};


#endif // WIDGET_NEW_HYP_H
