#include "Cube.h"

// Classe Cube

Cube:: Cube(int num, Sommet *s1, Sommet *s2, Sommet *s3, Sommet *s4, Sommet *s5, Sommet *s6, Sommet *s7, Sommet *s8)
{
    this->num = num;
    this->som_cube[0] = s1;
    this->som_cube[1] = s2;
    this->som_cube[2] = s3;
    this->som_cube[3] = s4;
    this->som_cube[4] = s5;
    this->som_cube[5] = s6;
    this->som_cube[6] = s7;
    this->som_cube[7] = s8;

    this->LFace.append(new Face(s1, s2, s3, s4));
    this->LFace.append(new Face(s5, s6, s7, s8));
    this->LFace.append(new Face(s2, s6, s4, s8));
    this->LFace.append(new Face(s1, s5, s3, s7));
    this->LFace.append(new Face(s3, s4, s7, s8));
    this->LFace.append(new Face(s1, s2, s5, s6));

    /*ana*/
    this->LFace.append(new Face(s1, s2, s7, s8));
    this->LFace.append(new Face(s3, s4, s5, s6));
    this->LFace.append(new Face(s1, s5, s4, s8));
    this->LFace.append(new Face(s3, s7, s2, s6));

    this->LFace.append(new Face(s1, s6, s3, s8));
    this->LFace.append(new Face(s2, s5, s4, s7));



    this->LArrete_int.append(new Arrete_interieur(s1, s8, 1));
    this->LArrete_int.append(new Arrete_interieur(s2, s7, 2));
    this->LArrete_int.append(new Arrete_interieur(s3, s6, 3));
    this->LArrete_int.append(new Arrete_interieur(s4, s5, 4));

    /*
    this->Ajouter_triangle_Int(1, s4, s7, s6);
    this->Ajouter_triangle_Int(1, s3, s5, s2);
    this->Ajouter_triangle_Int(2, s3, s8, s5);
    this->Ajouter_triangle_Int(2, s1, s6, s4);
    this->Ajouter_triangle_Int(3, s4, s7, s1);
    this->Ajouter_triangle_Int(3, s2, s5, s8);
    this->Ajouter_triangle_Int(4, s3, s8, s2);
    this->Ajouter_triangle_Int(4, s1, s6, s7);
    */


    if((this->num == 1) || (this->num == 2))
    {
        this->LArrete_int.at(0)->Ajoute_Arete_Hyp_Cop(3);
        this->LArrete_int.at(0)->Ajoute_Arete_Hyp_Cop(7);
        this->LArrete_int.at(0)->Ajoute_Arete_Hyp_Cop(8);
        this->LArrete_int.at(0)->Ajoute_Arete_Hyp_Cop(1);
        this->LArrete_int.at(0)->Ajoute_Arete_Hyp_Cop(5);
        this->LArrete_int.at(0)->Ajoute_Arete_Hyp_Cop(4);

        /*if(this->num == 1)
        {
            this->LArrete_int.at(0)->Ajoute_Arete_Hyp_Cop(2);
            this->LArrete_int.at(0)->Ajoute_Arete_Hyp_Cop(6);
        }*/


        this->LArrete_int.at(1)->Ajoute_Arete_Hyp_Cop(2);
        this->LArrete_int.at(1)->Ajoute_Arete_Hyp_Cop(5);
        this->LArrete_int.at(1)->Ajoute_Arete_Hyp_Cop(6);
        this->LArrete_int.at(1)->Ajoute_Arete_Hyp_Cop(4);
        this->LArrete_int.at(1)->Ajoute_Arete_Hyp_Cop(1);
        this->LArrete_int.at(1)->Ajoute_Arete_Hyp_Cop(7);

        /*if(this->num == 1)
        {
            this->LArrete_int.at(1)->Ajoute_Arete_Hyp_Cop(3);
            this->LArrete_int.at(1)->Ajoute_Arete_Hyp_Cop(8);
        }*/


        this->LArrete_int.at(2)->Ajoute_Arete_Hyp_Cop(3);
        this->LArrete_int.at(2)->Ajoute_Arete_Hyp_Cop(7);
        this->LArrete_int.at(2)->Ajoute_Arete_Hyp_Cop(8);
        this->LArrete_int.at(2)->Ajoute_Arete_Hyp_Cop(1);
        this->LArrete_int.at(2)->Ajoute_Arete_Hyp_Cop(2);
        this->LArrete_int.at(2)->Ajoute_Arete_Hyp_Cop(6);

        /*if(this->num == 1)
        {
            this->LArrete_int.at(2)->Ajoute_Arete_Hyp_Cop(4);
            this->LArrete_int.at(2)->Ajoute_Arete_Hyp_Cop(5);
        }*/

        this->LArrete_int.at(3)->Ajoute_Arete_Hyp_Cop(2);
        this->LArrete_int.at(3)->Ajoute_Arete_Hyp_Cop(5);
        this->LArrete_int.at(3)->Ajoute_Arete_Hyp_Cop(6);
        this->LArrete_int.at(3)->Ajoute_Arete_Hyp_Cop(4);
        this->LArrete_int.at(3)->Ajoute_Arete_Hyp_Cop(3);
        this->LArrete_int.at(3)->Ajoute_Arete_Hyp_Cop(8);

        /*if(this->num == 1)
        {
            this->LArrete_int.at(3)->Ajoute_Arete_Hyp_Cop(1);
            this->LArrete_int.at(3)->Ajoute_Arete_Hyp_Cop(7);
        }*/




    }


}

QList<Sommet*>* Cube::Get_Sommet_Actif()
{
    int i;

    if(this->LSommet_Act.count() == 0)
    {
        for(i = 0;i < 8;i++)
        {
            if(this->som_cube[i]->Get_actif() == true)
                this->LSommet_Act.append(this->som_cube[i]);

        }
    }

    return &LSommet_Act;
}

int Cube::Get_num()
{
    return this->num;
}

Arrete_interieur* Cube::Get_Arrete_interieur(int num)
{
    if((num < 1) && (num > 4))
        throw new ExceptionNumberArrete_int(num);
    else
        return this->LArrete_int.at(num-1);
}

bool Cube::Est_Sommet_Actif_Du_Cube(Sommet *s)
{
    int i, n;
    n = this->LSommet_Act.count();
    for(i = 0;i < n;i++)
    {
        if( (this->LSommet_Act.at(i)->Get_num() == s->Get_num()) &&
            (this->LSommet_Act.at(i)->Get_actif() == true)
          )
            return true;
    }

    return false;

}

bool Cube::Est_meme_Face(Sommet *s1, Sommet *s2)
{
    int i;
    for(i = 0;i < 12;i++)
    {
        if((this->LFace.at(i)->Est_Active() == true) && (this->LFace.at(i)->Est_meme_Face(s1, s2) == true))
        {
            return true;
        }
    }

    return false;

}

bool Cube::Est_meme_Face_Hyp(Sommet *s1, Sommet *s2)
{
    int i;
    for(i = 0;i < 6;i++)
    {
        if((this->LFace.at(i)->Est_Active() == true) && (this->LFace.at(i)->Est_meme_Face(s1, s2) == true))
        {
            return true;
        }
    }

    return false;

}

bool Cube::Est_Arrete_interieur(Sommet *s1, Sommet *s2)
{
    int i, n;
    n = this->LArrete_int.count();

    for(i = 0;i < n;i++)
    {
        if(this->LArrete_int.at(i)->Test_arrete(s1, s2) == true)
            return true;
    }

    return false;

}

bool Cube::Possede_Face_active()
{
    int i;

    for(i = 0;i < 12;i++)
    {
        if(this->LFace.at(i)->Est_Active() == true)
            return true;
    }

    return false;

}

bool Cube::Possede_Face_active(int *num)
{
    int i;

    for(i = 0;i < 12;i++)
    {
        if(this->LFace.at(i)->Est_Active() == true)
        {
            (*num) = i+1;
            return true;
        }
    }

    return false;

}

void Cube::Lier_Face_Sommet(int num_face, Sommet *s)
{
    if((num_face < 1) && (num_face > 12))
        throw new ExceptionNumberFace(num_face);
    else
    {
        this->LFace.at(num_face-1)->Lier_Face_Sommet(s);
    }
}

void Cube::Creer_voisinage_Face(int numf)
{
    if((numf < 1) && (numf > 12))
        throw new ExceptionNumberFace(numf);
    else
    {
        this->LFace.at(numf-1)->Creer_voisinage_Sommet_Face();
    }

}

bool Cube::Possede_Arete_Interieur()
{
    int i;

    for(i = 0;i < 4;i++)
    {
        if(this->LArrete_int.at(i)->Est_Active() == true)
            return true;

    }

    return false;

}

bool Cube::Est_Actif()
{
    int i, nb;

    nb = 0;
    for(i = 0;i < 8;i++)
    {
        if(this->som_cube[i]->Get_actif() == true)
            nb++;

    }

    return ((nb == 8) ? true : false);

}

void Cube::Ajouter_Arete_Int_Cext(QList<Arrete_interieur *> *Lai, QList<Arrete_interieur *> *Lai2, QList<Arrete_interieur *> *Lai3, QList<Arrete_interieur *> *Lai4)
{
    this->LArrete_int.at(0)->Ajouter_Arete_int_cext(Lai);
    this->LArrete_int.at(1)->Ajouter_Arete_int_cext(Lai2);
    this->LArrete_int.at(2)->Ajouter_Arete_int_cext(Lai3);
    this->LArrete_int.at(3)->Ajouter_Arete_int_cext(Lai4);


}

bool Cube::Possede_Face_Diagonale_Active()
{
    int i;

    for(i = 6;i < 12;i++)
    {
        if(this->LFace.at(i)->Est_Active() == true)
            return true;
    }

    return false;

}

void Cube::Ajouter_triangle_Int(int num, Sommet *s1, Sommet *s2, Sommet *s3)
{
    this->LArrete_int.at(num-1)->Ajoute_Triangle_Int(s1, s2, s3);


}


bool Cube::Est_Meme_Cube(QList<Sommet *> *LS)
{
    int i;
    int n = LS->count();


    for(i = 0;i < n;i++)
    {
        if(this->Est_Sommet_Actif_Du_Cube(LS->at(i)) == false)
            return false;

    }

    return true;

}

QList<Sommet*>* Cube::Get_Sommet_Libre(QList<Sommet *> *LS)
{
    int i, j, n;
    int nb;
    QList<Sommet*> *LR = new QList<Sommet*>();
    QList<Sommet*> *LSA = this->Get_Sommet_Actif();
    n = LSA->count();

    //Pour ts sommets actifs
    for(j = 0;j < n;j++)
    {
        nb = 0;
        for(i = 0;i < 3;i++)
        {
            if(LSA->at(j)->Get_num() != LS->at(i)->Get_num())
            {
                nb++;
            }

        }

        if(nb == 3)
        {
            LR->append(LSA->at(j));
        }

    }

    return LR;

}


Cube::~Cube()
{



}


#ifdef QT_HYP_CMODE

void Cube::Affiche_Cube()
{
    int i;

    for(i = 0;i < 8;i++)
    {
        this->som_cube[i]->Affiche_Sommet();
    }

}

#endif


//Fin Classe Cube
