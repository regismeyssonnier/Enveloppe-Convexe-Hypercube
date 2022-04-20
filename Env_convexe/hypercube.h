#ifndef HYPERCUBE_H
#define HYPERCUBE_H

#include "Header_general.h"
#include "Constant_project.h"

#include <iostream>
#include "Vec_4D.h"
#include "Sommet.h"
#include "Cube.h"



class Hypercube
{

    //Constructeur
    public:
        Hypercube();

    //variable prive
    private:
        Cube *cube[8];
        Sommet *som_hyp[16];
        int nb_som_act;
        QList<Arrete_interieur*> LArrete_int;
        QList<Face*> LFace_D;

    //--methode public QTconsole--//
    #ifdef QT_HYP_CMODE
    public:
       void Affiche_Hypercube();
    #endif
    //--Fin methode public QTconsole--//

    public:
       void Set_Sommet_Actif(int num);
       void Active_All_Sommet();
       void Desactive_All_Sommet();
       Sommet* Get_Sommet_Hyper(int i);
       int Get_NB_Sommet_actif();
       Cube* Get_Cube(int num);
       Arrete_interieur* Get_Arrete_interieur(int num);
       QList<Arrete_interieur*>* Get_Arrete_interieur();
       bool Possede_Face_Diag_Active();

    //Destruction
    public:
        ~Hypercube();



};

#endif // HYPERCUBE_H
