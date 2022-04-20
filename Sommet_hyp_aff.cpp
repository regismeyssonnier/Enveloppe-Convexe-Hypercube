#include "Sommet_hyp_aff.h"


Sommet_hyp_aff::Sommet_hyp_aff(Vec_4D *v, int num)
{
    this->vecteur = v;
    this->num = num;
    this->allumer = false;
}

Vec_4D* Sommet_hyp_aff::Get_Coord()
{
    return this->vecteur;
}

int Sommet_hyp_aff::Get_Num()
{
    return this->num;
}

void Sommet_hyp_aff::Allumer()
{

        this->allumer = true;

}

void Sommet_hyp_aff::Eteindre()
{

        this->allumer = false;

}


bool Sommet_hyp_aff::Get_Etat()
{
    return this->allumer;
}

void Sommet_hyp_aff::Set_coord(double x, double y, double z, double t)
{
    this->vecteur->x = x;
    this->vecteur->y = y;
    this->vecteur->z = z;
    this->vecteur->t = t;

}


