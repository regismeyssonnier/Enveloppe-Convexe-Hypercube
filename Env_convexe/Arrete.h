#ifndef ARRETE_H
#define ARRETE_H

#include <QDebug>
#include "Sommet.h"
QT_BEGIN_NAMESPACE
class Sommet;
QT_END_NAMESPACE

class Arrete
{
    //Constructeur
public:
    Arrete(Sommet *s1, Sommet *s2, int num);

    //Variable protégé
protected:
    Sommet *s1;
    Sommet *s2;
    int num;

    //Variable public
public:
    int Get_num();
    Sommet* Get_S1();
    Sommet* Get_S2();


    //Methode public
public:
    virtual bool Test_arrete(Sommet *s1, Sommet *s2);
    bool Est_Active();



};

//Arrete intérieure d'un cube
class Arrete_interieur : public Arrete
{
    //Constructeur
public:
    Arrete_interieur(Sommet *s1, Sommet *s2, int num);

    //Variable privé
private:
    QList<QList<Sommet*>*> LSommet_tri_int;
    QList<int> Lind_arete_hyp_cop;
    QList<Arrete_interieur*> *LArete_int_cext;
    QList<Sommet*> LSommet_face;
    QList<Sommet*> LSommet_faceci1, LSommet_faceci2, LSommet_faceci3;
    QList<Sommet*> LSommet_facece1, LSommet_facece2, LSommet_facece3;

public:
    void Ajoute_Triangle_Int(Sommet *s1, Sommet *s2, Sommet *s3);
    void Ajoute_Arete_Hyp_Cop(int num);
    int Get_Num_Arete_Cop(int num);
    bool Est_Ajoutable(QList<Arrete_interieur*> *LArrete_int);
    bool Est_Ajoutable_Hyp();
    void Ajouter_Arete_int_cext(QList<Arrete_interieur*>* Lai);
    bool Est_Actif_Triangle_Int();
    void Lier_Sommet_Face_Adjacente(Sommet *s);
    void Lier_Sommet_Faceci1(Sommet *s);
    void Lier_Sommet_Faceci2(Sommet *s);
    void Lier_Sommet_Faceci3(Sommet *s);
    void Lier_Sommet_Facece1(Sommet *s);
    void Lier_Sommet_Facece2(Sommet *s);
    void Lier_Sommet_Facece3(Sommet *s);
    bool Forme_Pyramide();

};

#endif // ARRETE_H
