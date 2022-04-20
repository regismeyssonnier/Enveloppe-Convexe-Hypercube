#include "Bouton_sommet.h"

Bouton_sommet::Bouton_sommet()
{
    this->hauteur = 20;
    this->largeur = 20;
}

void Bouton_sommet::Afficher_bouton()
{
    double i = 0.0;
    double n = 1.0 ;
    double pas =  0.1;

    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);

   /* glBegin(GL_QUADS);

        glColor4f(1.0f, .0f, .0f, 0.25f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(1.0f, 0.0f, 0.0f);
        glColor4f(1.0f, .0f, .0f, 0.5f);
        glVertex3f(1.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);

        glEnd();*/



    //for(i = 0;i < n;i+=pas)
    //{
        glBegin(GL_QUADS);
            glVertex3f(i * pas, 1.0f, 0.0f);
            glVertex3f((i+1) * pas, 1.0f, 0.0f);
            glVertex3f((i+1) * pas, 1.0f + pas, 0.0f);
            glVertex3f(i * pas, 1.0f + pas, 0.0f);

        glEnd();

        glBegin(GL_LINE_LOOP);
            glVertex3f(i * pas, 1.0f, 0.0f);
            glVertex3f((i+1) * pas, 1.0f, 0.0f);
            glVertex3f((i+1) * pas, 1.0f + pas, 0.0f);
            glVertex3f(i * pas, 1.0f + pas, 0.0f);

        glEnd();

    //}

}

int Bouton_sommet::Determiner_Click_Bouton()
{


}
