#include "Hypercube_aff.h"


Hypercube_aff::Hypercube_aff()
{
    Vec_4D *v;

    //Cube int
    //Sommet 1
    v = new Vec_4D(-0.5, -0.5, 0.5, 0.0);
    this->sommet[0] = new Sommet_hyp_aff(v, 1);

    //Sommet 2
    v = new Vec_4D(0.5, -0.5, 0.5, 0.0);
    this->sommet[1] = new Sommet_hyp_aff(v, 2);

    //Sommet 3
    v = new Vec_4D(-0.5, 0.5, 0.5, 0.0);
    this->sommet[2] = new Sommet_hyp_aff(v, 3);

    //Sommet 4
    v = new Vec_4D(0.5, 0.5, 0.5, 0.0);
    this->sommet[3] = new Sommet_hyp_aff(v, 4);

    //Sommet 5
    v = new Vec_4D(-0.5, -0.5, -0.5, 0.0);
    this->sommet[4] = new Sommet_hyp_aff(v, 5);

    //Sommet 6
    v = new Vec_4D(0.5, -0.5, -0.5, 0.0);
    this->sommet[5] = new Sommet_hyp_aff(v, 6);

    //Sommet 7
    v = new Vec_4D(-0.5, 0.5, -0.5, 0.0);
    this->sommet[6] = new Sommet_hyp_aff(v, 7);

    //Sommet 8
    v = new Vec_4D(0.5, 0.5, -0.5, 0.0);
    this->sommet[7] = new Sommet_hyp_aff(v, 8);


    //------- Cube ext --------------------
    //Sommet 9
    v = new Vec_4D(-1, -1, 1, 1.0);
    this->sommet[8] = new Sommet_hyp_aff(v, 9);

    //Sommet 10
    v = new Vec_4D(1, -1, 1, 1.0);
    this->sommet[9] = new Sommet_hyp_aff(v, 10);

    //Sommet 11
    v = new Vec_4D(-1, 1, 1, 1.0);
    this->sommet[10] = new Sommet_hyp_aff(v, 11);

    //Sommet 12
    v = new Vec_4D(1, 1, 1, 1.0);
    this->sommet[11] = new Sommet_hyp_aff(v, 12);

    //Sommet 13
    v = new Vec_4D(-1, -1, -1, 1.0);
    this->sommet[12] = new Sommet_hyp_aff(v, 13);

    //Sommet 14
    v = new Vec_4D(1, -1, -1, 1.0);
    this->sommet[13] = new Sommet_hyp_aff(v, 14);

    //Sommet 15
    v = new Vec_4D(-1, 1, -1, 1.0);
    this->sommet[14] = new Sommet_hyp_aff(v, 15);

    //Sommet 16
    v = new Vec_4D(1, 1, -1, 1.0);
    this->sommet[15] = new Sommet_hyp_aff(v, 16);

    this->set_aff = false;

}

Sommet_hyp_aff* Hypercube_aff::Get_Sommet(int num)
{
    if((num >= 1) && (num <= 16))
        return sommet[num-1];
    else
        return 0;

}

void Hypercube_aff::Afficher_Hypercube(bool point)
{
    Vec_4D *v;

    glLineWidth(2.0f);

    glBegin(GL_LINES);


        glColor4f(0.0f, .0f, 1.0f, 1.0f);

        //Cube interieur
        //Face 1
        //Ligne bas
        v = this->sommet[0]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[1]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[2]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[3]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne gauche
        v = this->sommet[0]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[2]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne droite
        v = this->sommet[1]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[3]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //------- Face derriere ----------------
        //Ligne bas
        v = this->sommet[4]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[5]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[6]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[7]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne gauche
        v = this->sommet[4]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[6]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne droite
        v = this->sommet[5]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[7]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);


        //------ Face cote gauche -------
        //Ligne bas
        v = this->sommet[0]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[4]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[2]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[6]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //------ Face cote droit -------
        //Ligne bas
        v = this->sommet[1]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[5]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[3]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[7]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        /*-------------------------------------------------------*/

        //Cube exterieur
        //Face 1
        //Ligne bas
        v = this->sommet[8]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[9]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[10]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[11]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne gauche
        v = this->sommet[8]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[10]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne droite
        v = this->sommet[9]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[11]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //------- Face derriere ----------------
        //Ligne bas
        v = this->sommet[12]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[13]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[14]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[15]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne gauche
        v = this->sommet[12]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[14]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne droite
        v = this->sommet[13]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[15]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);


        //------ Face cote gauche -------
        //Ligne bas
        v = this->sommet[8]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[12]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[10]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[14]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //------ Face cote droit -------
        //Ligne bas
        v = this->sommet[9]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[13]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[11]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[15]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);


        /*-------------------------------------------*/
        //------ Haut inter -------
        //Ligne bas
        v = this->sommet[2]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[10]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[6]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[14]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //------ Face cote droit -------
        //Ligne bas
        v = this->sommet[3]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[11]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[7]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[15]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);


        /*-------------------------------------------*/
        //------ Bas inter -------
        //Ligne bas
        v = this->sommet[0]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[8]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[4]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[12]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //------ Face cote droit -------
        //Ligne bas
        v = this->sommet[1]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[9]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        //Ligne haut
        v = this->sommet[5]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);

        v = this->sommet[13]->Get_Coord();
        glVertex3f(v->x, v->y, v->z);





    glEnd();

    if(point == true)
    {
        int i;

        glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
        glPointSize(10.0f);

        glBegin(GL_POINTS);
        for(i = 0;i < 16;i++)
        {

            if(this->sommet[i]->Get_Etat() == false)
                glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
            else
                glColor4f(1.0f, 0.0f, 0.0f, 1.0f);


            v = this->sommet[i]->Get_Coord();
            glVertex3f(v->x, v->y, v->z);
        }

        glEnd();

    }


}

void Hypercube_aff::Set_GLWIDGET(GLWidget *g)
{
    this->gl_widget = g;
}


void Hypercube_aff::Allumer_Sommet(int num)
{
    if((num >= 1) && (num <= 16))
    {
        this->sommet[num-1]->Allumer();




    }

}


void Hypercube_aff::Eteindre_Sommet(int num)
{
    if((num >= 1) && (num <= 16))
        this->sommet[num-1]->Eteindre();

}


void Hypercube_aff::Charger_Enveloppe_conv(Env_convexe *ec, Hypercube *h, QString nom_fichier)
{
    int i, n;

    for(i = 0;i < 16;i++)
    {
        this->sommet[i]->Eteindre();
    }

    this->Arrete_env.clear();
    this->Triangle_env.clear();

    ec->Charger_Env_convexe(nom_fichier, &Arrete_env, &Triangle_env);

    n = this->Arrete_env.count();

    for(i = 0;i < n;i++)
    {
        this->sommet[this->Arrete_env.at(i)->Get_S1()->Get_num()-1]->Allumer();
        this->sommet[this->Arrete_env.at(i)->Get_S2()->Get_num()-1]->Allumer();
    }



}


void Hypercube_aff::Afficher_Enveloppe_conv(bool btri, bool bar)
{
    int n = this->Arrete_env.count();
    int i;
    int v1, v2, v3;
    Sommet_hyp_aff *s1, *s2, *s3;
    Vec_4D *v;
    int *Tri;



    if(bar == true)
    {
        glLineWidth(3.5f);
        glColor4f(0.0f, 0.0f, 0.0f, 1.0f);

        for(i = 0;i < n;i++)
        {
            glBegin(GL_LINES);
                v1 = this->Arrete_env.at(i)->Get_S1()->Get_num();
                v2 = this->Arrete_env.at(i)->Get_S2()->Get_num();
                s1 = this->sommet[v1-1];
                s2 = this->sommet[v2-1];

                v = s1->Get_Coord();
                glVertex3f(v->x, v->y, v->z);

                v = s2->Get_Coord();
                glVertex3f(v->x, v->y, v->z);


            glEnd();

        }

        glLineWidth(2.0f);

    }

    if(btri == true)
    {

        glColor4f(0.0f, 0.1f, 0.85f, 0.25f);

        n = this->Triangle_env.count();

        for(i = 0;i < n;i++)
        {
            Tri = this->Triangle_env.at(i);
            glBegin(GL_TRIANGLES);
                s1 = this->sommet[Tri[0]-1];
                s2 = this->sommet[Tri[1]-1];
                s3 = this->sommet[Tri[2]-1];

                v = s1->Get_Coord();
                glVertex3f(v->x, v->y, v->z);

                v = s2->Get_Coord();
                glVertex3f(v->x, v->y, v->z);

                v = s3->Get_Coord();
                glVertex3f(v->x, v->y, v->z);


            glEnd();

        }



    }

}









