#ifndef BOUTON_SOMMET_H
#define BOUTON_SOMMET_H

#include <QtOpenGL>

class Bouton_sommet
{
public:
    Bouton_sommet();

public:
    void Afficher_bouton();
    int Determiner_Click_Bouton();

public:
    double largeur;
    double hauteur;

};

#endif // BOUTON_SOMMET_H
