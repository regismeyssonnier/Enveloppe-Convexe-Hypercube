#ifndef SOMMET_H
#define SOMMET_H

#include "Header_general.h"
#include "Constant_project.h"

#include <iostream>
#include "Vec_4D.h"
#include <QList>
#include "Arrete.h"

QT_BEGIN_NAMESPACE
class Arrete;
class Arrete_interieur;
QT_END_NAMESPACE

class Sommet
{

    //Constructeur
    public:
       Sommet(Vec_4D *vec, int num, Sommet *s);
       Sommet(int num);

    //variable prive
    private:
        Vec_4D *vec_som;
        int num;
        Sommet *som_parent;
        bool actif;
        QList<Sommet*> som_voisin;
        int Cube_ass[4];
        QList<Sommet*> som_vois_ec;
        Arrete_interieur *arete_int;
        bool a_arete_int;
        QList<int> triangle;
        QList<int> t_som_voisin;

    //methode public
    public:
        void Add_parente(Sommet *s);
        void Add_voisinage(Sommet *s);
        void Add_voisinage_conv(Sommet *s);
        QList<Sommet*>* Get_voisinage();
        QList<Sommet*>* Get_voisinage_conv();
        bool Existe_voisin_conv(Sommet *s);
        int Get_num();
        int Get_NB_Voisin_conv();
        Arrete_interieur* Get_Arrete_interieur();
        bool Possede_Arrete_int();
        void Set_Arrete_int(Arrete_interieur *a);
        bool Possede_Fils(Sommet *s);
        bool Possede_Fils(Sommet *s, int &num);
        void Add_Triangle(int tri);
        QList<int>* Get_triangle();
        int Get_NB_Triangle();
        void Add_Type_Voisin(int type);
        int Get_Type_Voisin(int num);


    //Accesseur
    public:
        void Set_actif(bool b);
        bool Get_actif();
        int* Get_cube_associe();
        void Set_Cube_associe(int ca[4]);

    //--methode public QTconsole--//
    #ifdef QT_HYP_CMODE
    public:
       void Affiche_Sommet();
    #endif
    //--Fin methode public QTconsole--//

    public:
        ~Sommet();

};

#endif // SOMMET_H
