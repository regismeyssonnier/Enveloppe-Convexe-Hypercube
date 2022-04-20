#ifndef ENV_CONVEXE_H
#define ENV_CONVEXE_H

#include "Header_general.h"
#include "Constant_project.h"

#include "Sommet.h"
#include "hypercube.h"
#include <QList>
#include <QFile>
#include <QDataStream>
#include <QDebug>

class Env_convexe
{

    //Constructeur
public:
    Env_convexe(Hypercube **h);

    //Methode public
public:
    void Creer_Env_convexe();
    void Sauvegarder_Env_convexe(QString nom_fichier);
    void Charger_Env_convexe(QString nom_fichier, QList<Arrete*>* Ar, QList<int*>* Triangle);
    bool Est_Dans_2Triangles(Sommet *s, Sommet *p, int marque[]);

    //Methode prive
private:
    void Creer_Liste_voisinage();
    void Liste_voisinage();
    void Creer_Env_convexe_fdf();
    void Creer_Env_convexe_fdf3_5();
    Sommet* Get_SA(int num);
    void Trouver_tetraedre();
    void Trianguler_env_convexe();



    //Variable public
public:
    Hypercube **Hyper;

    //Variable privé
private:
    Sommet *som_hyp[16];
    QList<int*> Triangle;
    QList<int*> Tetra;


    //Destructeur
public:
    ~Env_convexe();

};



#endif // ENV_CONVEXE_H
