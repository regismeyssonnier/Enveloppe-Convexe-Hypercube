#include "Exception.h"


//Classe ExceptionNumberSommet
ExceptionNumberSommet::ExceptionNumberSommet(int num)
{
    this->num = num;

}

#ifdef QT_HYP_CMODE
void ExceptionNumberSommet::Display_Error()
{
    std::cout << "Numero de sommet invalide : " << this->num << std::endl;
    std::cout << "Compris entre 1 et 16 inclus" << std::endl;



}
#endif

// Fin Classe ExceptionNumberSommet

/*******************************************************************************/

// Classe ExceptionNumberSommetCube
ExceptionNumberCube::ExceptionNumberCube(int num) : ExceptionNumberSommet(num)
{

}

#ifdef QT_HYP_CMODE
void ExceptionNumberCube::Display_Error()
{
    std::cout << "Numero de cube invalide : " << this->num << std::endl;
    std::cout << "Compris entre 1 et 8 inclus" << std::endl;



}
#endif



//Fin classe ExceptionNumberSommetCube

/*******************************************************************************/

// Classe ExceptionNumberArrete_int
ExceptionNumberArrete_int::ExceptionNumberArrete_int(int num) : ExceptionNumberSommet(num)
{

}

#ifdef QT_HYP_CMODE
void ExceptionNumberArrete_int::Display_Error()
{
    std::cout << "Numero d'arrete interieure du cube invalide : " << this->num << std::endl;
    std::cout << "Compris entre 1 et 4 inclus" << std::endl;



}
#endif



//Fin classe ExceptionNumberArrete_int

/*******************************************************************************/

// Classe ExceptionNumberArreteIntHyp
ExceptionNumberArreteIntHyp::ExceptionNumberArreteIntHyp(int num) : ExceptionNumberSommet(num)
{

}

#ifdef QT_HYP_CMODE
void ExceptionNumberArreteIntHyp::Display_Error()
{
    std::cout << "Numero d'arête d'intérieure de l'hypercube invalide : " << this->num << std::endl;
    std::cout << "Compris entre 1 et 8 inclus" << std::endl;

}
#endif



//Fin classe ExceptionNumberSommetCube

/********************************************************************************/

//Classe ExceptionPasArreteInt
ExceptionPasArreteInt::ExceptionPasArreteInt(int num)
{
    this->num = num;
}

void ExceptionPasArreteInt::Display_Error()
{
    std::cout << "Pas d'arrete interieur pour le sommet " << this->num << std::endl;

}

//Fin Classe ExceptionPasArreteInt

/********************************************************************************/

//Classe ExceptionNumberFace
ExceptionNumberFace::ExceptionNumberFace(int num)
{
    this->num = num;
}

void ExceptionNumberFace::Display_Error()
{
    std::cout << "Mauvais numero de face : " << this->num << std::endl;
    std::cout << "Compris entre 1 et 6." << std::endl;

}

//Fin Classe ExceptionNumberFace
