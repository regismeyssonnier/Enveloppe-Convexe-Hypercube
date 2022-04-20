#ifndef SOMMET_HYP_AFF_H
#define SOMMET_HYP_AFF_H

#include "Vec_4D.h"

class Sommet_hyp_aff
{
    //Constructeur
public:
    Sommet_hyp_aff(Vec_4D *v, int num);

    //Variable prive
private:
    Vec_4D *vecteur;
    int num;
    bool allumer;


    //Methode public
public:
    int Get_Num();
    Vec_4D* Get_Coord();
    void Allumer();
    void Eteindre();
    bool Get_Etat();
    void Set_coord(double x, double y, double z, double t);


};

#endif // SOMMET_HYP_AFF_H
