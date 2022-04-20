#include "Arrete.h"

//Classe Arrete
Arrete::Arrete(Sommet *s1, Sommet *s2, int num)
{
    this->s1 = s1;
    this->s2 = s2;
    this->num = num;
}


bool Arrete::Test_arrete(Sommet *s1, Sommet *s2)
{
    if( ((this->s1->Get_num() == s1->Get_num()) && (this->s2->Get_num() == s2->Get_num())) ||
        ((this->s1->Get_num() == s2->Get_num()) && (this->s2->Get_num() == s1->Get_num()))
      )
        return true;
    else
        return false;

}

int Arrete::Get_num()
{
    return this->num;
}

Sommet* Arrete::Get_S1()
{
    return this->s1;

}

Sommet* Arrete::Get_S2()
{
    return this->s2;

}

bool Arrete::Est_Active()
{
    if((this->s1->Get_actif() == true) && (this->s2->Get_actif() == true))
        return true;
    else
        return false;

}

//Fin Classe Arrete


//Classe Arrete interieur
Arrete_interieur::Arrete_interieur(Sommet *s1, Sommet *s2, int num) : Arrete(s1, s2, num)
{
    this->s1->Set_Arrete_int(this);
    this->s2->Set_Arrete_int(this);
    this->LArete_int_cext = 0;

}

void Arrete_interieur::Ajoute_Triangle_Int(Sommet *s1, Sommet *s2, Sommet *s3)
{
    QList<Sommet*>* Ls = new QList<Sommet*>();
    Ls->append(s1);
    Ls->append(s2);
    Ls->append(s3);

    this->LSommet_tri_int.append(Ls);


}

void Arrete_interieur::Ajoute_Arete_Hyp_Cop(int num)
{
    this->Lind_arete_hyp_cop.append(num);
}

int Arrete_interieur::Get_Num_Arete_Cop(int num)
{
    return this->Lind_arete_hyp_cop.at(num);
}

bool Arrete_interieur::Est_Ajoutable(QList<Arrete_interieur *> *LHA)
{
    int i, num, n, j;

    int nb =0;
    n = this->LSommet_tri_int.count();
    for(i = 0;i < n;i++)
    {
        nb = 0;
        QList<Sommet*>* tri = this->LSommet_tri_int.at(i);
        for(j = 0;j < 3;j++)
        {
            if(tri->at(j)->Get_actif() == true)
            {
                if( (this->Get_S1()->Get_actif() == true) &&
                    (this->Get_S2()->Get_actif() == true)
                  )
                {
                    nb++;
                }

            }
        }

        if(nb == 3)return true;


    }

    /*n = this->Lind_arete_hyp_cop.count();
    for(i = 0;i < n;i++)
    {
        num = this->Lind_arete_hyp_cop.at(i);
        if(LHA->at(num-1)->Est_Active() == true)
            return false;

    }

    if(this->LArete_int_cext != 0)
    {
        n = this->LArete_int_cext->count();
        for(i = 0;i < n;i++)
        {
            if(this->LArete_int_cext->at(i)->Est_Active() == true)
                return false;
        }
    }*/

    return true;

}

bool Arrete_interieur::Est_Ajoutable_Hyp()
{
    int i, n, j;

    n = this->LSommet_face.count();
    for(i = 0;i < n;i++)
    {
        if(this->LSommet_face.at(i)->Get_actif() == true)
            return false;
    }

    int nb =0;
    n = this->LSommet_tri_int.count();
    for(i = 0;i < n;i++)
    {
        nb = 0;
        QList<Sommet*>* tri = this->LSommet_tri_int.at(i);
        for(j = 0;j < 3;j++)
        {
            if(tri->at(j)->Get_actif() == true)
            {
                if( (this->Get_S1()->Get_actif() == true) &&
                    (this->Get_S2()->Get_actif() == true)
                  )
                {
                    nb++;
                }

            }
        }

        if(nb == 3)return true;


    }

    n = this->LArete_int_cext->count();
    for(i = 0;i < n;i++)
    {
        if(this->LArete_int_cext->at(i)->Est_Active() == true)
            return false;
    }




    return true;

}

void Arrete_interieur::Ajouter_Arete_int_cext(QList<Arrete_interieur *> *Lai)
{
    this->LArete_int_cext = Lai;
}

bool Arrete_interieur::Est_Actif_Triangle_Int()
{
    int i, j, n;

    int nb =0;
    n = this->LSommet_tri_int.count();
    for(i = 0;i < n;i++)
    {
        nb = 0;
        QList<Sommet*>* tri = this->LSommet_tri_int.at(i);
        for(j = 0;j < 3;j++)
        {
            if(tri->at(j)->Get_actif() == true)
            {
                nb++;
            }
        }

        if(nb == 3)return true;


    }

    return false;



}

void Arrete_interieur::Lier_Sommet_Face_Adjacente(Sommet *s)
{
    this->LSommet_face.append(s);

}

void Arrete_interieur::Lier_Sommet_Facece1(Sommet *s)
{
    this->LSommet_facece1.append(s);
}

void Arrete_interieur::Lier_Sommet_Facece2(Sommet *s)
{
    this->LSommet_facece2.append(s);
}

void Arrete_interieur::Lier_Sommet_Facece3(Sommet *s)
{
    this->LSommet_facece3.append(s);
}

void Arrete_interieur::Lier_Sommet_Faceci1(Sommet *s)
{
    this->LSommet_faceci1.append(s);
}

void Arrete_interieur::Lier_Sommet_Faceci2(Sommet *s)
{
    this->LSommet_faceci2.append(s);
}

void Arrete_interieur::Lier_Sommet_Faceci3(Sommet *s)
{
    this->LSommet_faceci3.append(s);
}

bool Arrete_interieur::Forme_Pyramide()
{
    int i;
    bool result1 = true;

    Sommet *si = ((this->s1->Get_num() >= 1) && (this->s1->Get_num() <= 8)) ? this->s1 : this->s2;
    Sommet *se = ((this->s2->Get_num() >= 9) && (this->s2->Get_num() <= 16)) ? this->s2 : this->s1;

    int nb = 0;
    for(i = 0;i < 3;i++)
    {
        if(this->LSommet_faceci1.at(i)->Get_actif() == true)
        {
            if(this->LSommet_faceci1.at(i)->Possede_Fils(se) == false)
            {
                return false;
            }
            /*nb++;
            result1 = false;
            break;*/
            nb++;

        }

    }
    //if(nb == 0)result1 = false;



    bool result2 = true;
    for(i = 0;i < 3;i++)
    {
        if(this->LSommet_faceci2.at(i)->Get_actif() == true)
        {
            if(this->LSommet_faceci2.at(i)->Possede_Fils(se) == false)
            {
                return false;
            }
            nb++;

            /*nb++;
            result2 = false;
            break;*/

        }

    }
    //if(nb == 0)result2 = false;


    bool result3 = true;
    for(i = 0;i < 3;i++)
    {
        if(this->LSommet_faceci3.at(i)->Get_actif() == true)
        {
            if(this->LSommet_faceci3.at(i)->Possede_Fils(se) == false)
            {
                return false;
            }

            nb++;
            /*nb++;
            result3 = false;
            break;*/

        }

    }
    //if(nb == 0)result3 = false;

    //Si sommet actif lié
    if(nb != 0)
        return true;
    else
        return false;

    nb = 0;

    bool result4 = true;
    for(i = 0;i < 3;i++)
    {
        if(this->LSommet_facece1.at(i)->Get_actif() == true)
        {
            if(this->LSommet_facece1.at(i)->Possede_Fils(si) == false)
            {
                return false;
            }

            nb++;

            /*
            nb++;
            result4 = false;
            break;*/

        }

    }
    //if(nb == 0)result4 = false;



    bool result5 = true;
    for(i = 0;i < 3;i++)
    {
        if(this->LSommet_facece2.at(i)->Get_actif() == true)
        {
            if(this->LSommet_facece2.at(i)->Possede_Fils(si) == false)
            {
                return false;
            }

            nb++;

            /*nb++;
            result5 = false;
            break;*/

        }

    }
    if(nb == 0)result5 = false;


    bool result6 = true;
    for(i = 0;i < 3;i++)
    {
        if(this->LSommet_facece3.at(i)->Get_actif() == true)
        {
            if(this->LSommet_facece3.at(i)->Possede_Fils(si) == false)
            {
                return false;
            }

            nb++;

            /*nb++;
            result6 = false;
            break;*/

        }

    }
    //if(nb == 0)result6 = false;

    qDebug() << "si" << si->Get_num();
    qDebug() << "se" << se->Get_num();
    qDebug() << "r1" << result1;
    qDebug() << "r2" << result2;
    qDebug() << "r3" << result3;
    qDebug() << "r4" << result4;
    qDebug() << "r5" << result5;
    qDebug() << "r6" << result6;

    /*if((result1 == true) || (result2 == true) || (result3 == true) || (result4 == true) || (result5 == true) || (result6 == true))
        return true;
    else
        return false;*/

    if(nb != 0)
        return true;
    else
        return false;


}

//Fin Classe Arrete interieur
