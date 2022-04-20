#ifndef HYPERCUBE_AFF_H
#define HYPERCUBE_AFF_H

#include <QWidget>
#include <QtGui>
#include <QtOpenGL>
#include "Sommet_hyp_aff.h"
#include "gl_widget.h"
#include "Env_convexe/Env_convexe.h"
#include "Env_convexe/hypercube.h"
#include "Env_convexe/Arrete.h"
#include <QList>
#include <GL/glut.h>
#include <QVariant>

class GLWidget;

class Hypercube_aff
{


    //Constructeur
public:
    Hypercube_aff();

    //Methode public
public:
    void Afficher_Hypercube(bool point);
    Sommet_hyp_aff* Get_Sommet(int num);
    void Allumer_Sommet(int num);
    void Eteindre_Sommet(int num);
    void Charger_Enveloppe_conv(Env_convexe *ec, Hypercube *h, QString nom_fichier);
    void Afficher_Enveloppe_conv(bool btri, bool bar);
    void Set_GLWIDGET(GLWidget *g);


    //Variable prive
private:
    Sommet_hyp_aff *sommet[16];
    Env_convexe *Env_conv;
    Hypercube *Hyper;
    bool set_aff;
    QList<Arrete*> Arrete_env;
    QList<int*> Triangle_env;
    GLWidget *gl_widget;

};


#endif // HYPERCUBE_AFF_H
