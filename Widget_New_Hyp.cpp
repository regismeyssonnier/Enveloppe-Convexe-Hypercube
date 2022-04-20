#include "Widget_New_Hyp.h"



Widget_New_Hyp::Widget_New_Hyp(QWidget *parent)
{
    //this->Hyper = Hyper;

    this->check[0].setText(tr("1"));
    this->check[1].setText(tr("2"));
    this->check[2].setText(tr("3"));
    this->check[3].setText(tr("4"));
    this->check[4].setText(tr("5"));
    this->check[5].setText(tr("6"));
    this->check[6].setText(tr("7"));
    this->check[7].setText(tr("8"));
    this->check[8].setText(tr("9"));
    this->check[9].setText(tr("10"));
    this->check[10].setText(tr("11"));
    this->check[11].setText(tr("12"));
    this->check[12].setText(tr("13"));
    this->check[13].setText(tr("14"));
    this->check[14].setText(tr("15"));
    this->check[15].setText(tr("16"));


    connect(&check[0], SIGNAL(clicked()), this, SLOT(Cocher_sommet1()));


    this->vbox.addWidget(&this->check[0]);
    this->vbox.addWidget(&this->check[1]);
    this->vbox.addWidget(&this->check[2]);
    this->vbox.addWidget(&this->check[3]);
    this->vbox.addWidget(&this->check[4]);
    this->vbox.addWidget(&this->check[5]);
    this->vbox.addWidget(&this->check[6]);
    this->vbox.addWidget(&this->check[7]);
    this->vbox.addWidget(&this->check[8]);
    this->vbox.addWidget(&this->check[9]);
    this->vbox.addWidget(&this->check[10]);
    this->vbox.addWidget(&this->check[11]);
    this->vbox.addWidget(&this->check[12]);
    this->vbox.addWidget(&this->check[13]);
    this->vbox.addWidget(&this->check[14]);
    this->vbox.addWidget(&this->check[15]);
    this->vbox.setStretch(0,2);

    this->groupbox.setTitle(tr("Choisir un sommet de l'hypercube"));
    this->groupbox.setLayout(&vbox);

    this->qlay.addWidget(&groupbox);

    setLayout(&qlay);


}

void Widget_New_Hyp::Cocher_sommet1()
{
    //this->Hyper->Allumer_Sommet(1);

}

void Widget_New_Hyp::Cocher_sommet2()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet3()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet4()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet5()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet6()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet7()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet8()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet9()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet10()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet11()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet12()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet13()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet14()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet15()
{
    this->check[10].setChecked(true);

}

void Widget_New_Hyp::Cocher_sommet16()
{
    this->check[10].setChecked(true);

}

Widget_New_Hyp::~Widget_New_Hyp()
{

}
