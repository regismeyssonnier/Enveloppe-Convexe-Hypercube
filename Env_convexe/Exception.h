#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Constant_project.h"

#include <iostream>
#include <stdexcept>



//Exception dans la numerotation des sommets -> 1 a 16
class ExceptionNumberSommet : public std::exception
{
    //Constructeur
public:
    ExceptionNumberSommet(int num);

    //Variable protected
protected:
    int num;

    #ifdef QT_HYP_CMODE
public:
    virtual void Display_Error();
    #endif

};


//Exception dans la numerotation des cubes -> 1 a 8
class ExceptionNumberCube : public ExceptionNumberSommet
{
    //Constructeur
public:
    ExceptionNumberCube(int num);


    #ifdef QT_HYP_CMODE
public:
    void Display_Error();
    #endif

};

//Exception dans la numerotation des arrete int € cube - numero de 1 a 4
class ExceptionNumberArrete_int : public ExceptionNumberSommet
{
    //Constructeur
public:
    ExceptionNumberArrete_int(int num);


    #ifdef QT_HYP_CMODE
public:
    void Display_Error();
    #endif

};

//Exception dans la numerotation arêtes int de l'hypercube -> 1 a 8
class ExceptionNumberArreteIntHyp : public ExceptionNumberSommet
{
    //Constructeur
public:
    ExceptionNumberArreteIntHyp(int num);


    #ifdef QT_HYP_CMODE
public:
    void Display_Error();
    #endif

};

//Exception Sommet Arrete interieur
class ExceptionPasArreteInt : public std::exception
{
    //Constructeur
public:
    ExceptionPasArreteInt(int num);

    //Variable privé
private:
    int num;

#ifdef QT_HYP_CMODE
public:
    void Display_Error();
#endif

};

//Exception dans la numerotation des face -> 1 a 6
class ExceptionNumberFace : public std::exception
{
    //Constructeur
public:
    ExceptionNumberFace(int num);

    //Variable protected
protected:
    int num;

    #ifdef QT_HYP_CMODE
public:
    virtual void Display_Error();
    #endif

};

#endif // EXCEPTION_H
