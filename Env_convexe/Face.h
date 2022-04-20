#ifndef FACE_H
#define FACE_H

#include "Header_general.h"
#include "Constant_project.h"

#include <iostream>
#include "Sommet.h"
#include "Cube.h"
#include <QList>

QT_BEGIN_NAMESPACE
class Cube;
QT_END_NAMESPACE

class Face
{
    //Constructeur
public:
    Face(Sommet *s1, Sommet *s2, Sommet *s3, Sommet *s4);

    //Variable privé
private:
    QList<Sommet*> Lsom_Face;
    Cube *cube;

    //Methode public
public:
    bool Est_Active();
    void Set_cube(Cube *c);
    Cube* Get_cube();
    bool Est_meme_Face(Sommet *s1, Sommet *s2);
    void Creer_voisinage_Sommet_Face();
    void Lier_Face_Sommet(Sommet *s);
    bool Est_Lier();



};

#endif // FACE_H
