#ifndef CUBE_H
#define CUBE_H

#include "Header_general.h"
#include "Constant_project.h"

#include <iostream>
#include <QList>
#include "Sommet.h"
#include "Face.h"
#include "Arrete.h"

QT_BEGIN_NAMESPACE
class Face;
QT_END_NAMESPACE

class Cube
{
    //Constructeur
    public:
        Cube(int num, Sommet *s1, Sommet *s2, Sommet *s3, Sommet *s4, Sommet *s5, Sommet *s6, Sommet *s7, Sommet *s8);

    //variable privé
    private:
        Sommet *som_cube[8];
        int num;
        int nb_som_act;
        QList<Face*> LFace;
        QList<Sommet*> LSommet_Act;
        QList<Arrete_interieur*> LArrete_int;

    //Methode public
    public:
        QList<Sommet*>* Get_Sommet_Actif();
        int Get_num();
        bool Test_Arrete_interieur(Sommet *s1, Sommet *s2);
        Arrete_interieur* Get_Arrete_interieur(int num);
        bool Est_Sommet_Actif_Du_Cube(Sommet *s);
        bool Est_meme_Face(Sommet *s1, Sommet *s2);
        bool Est_meme_Face_Hyp(Sommet *s1, Sommet *s2);
        bool Est_Arrete_interieur(Sommet *s1, Sommet *s2);
        bool Possede_Face_active();
        bool Possede_Face_active(int *num);
        void Lier_Face_Sommet(int num_face, Sommet *s);
        void Creer_voisinage_Face(int num);
        bool Possede_Arete_Interieur();
        bool Est_Actif();
        void Ajouter_Arete_Int_Cext(QList<Arrete_interieur*>* Lai, QList<Arrete_interieur*>* Lai2,
                                    QList<Arrete_interieur*>* Lai3, QList<Arrete_interieur*>* Lai4);

        bool Possede_Face_Diagonale_Active();
        void Ajouter_triangle_Int(int num, Sommet *s1, Sommet *s2, Sommet *s3);
        bool Est_Meme_Cube(QList<Sommet*>* LS);
        QList<Sommet*>* Get_Sommet_Libre(QList<Sommet*>* LS);


    //--methode public QTconsole--//
    #ifdef QT_HYP_CMODE
    public:
       void Affiche_Cube();
    #endif
    //--Fin methode public QTconsole--//

    //destructeur
    public:
        ~Cube();

};

#endif // CUBE_H
