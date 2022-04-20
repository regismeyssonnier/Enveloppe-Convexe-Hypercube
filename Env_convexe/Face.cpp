#include "Face.h"




Face::Face(Sommet *s1, Sommet *s2, Sommet *s3, Sommet *s4)
{
    this->Lsom_Face.append(s1);
    this->Lsom_Face.append(s2);
    this->Lsom_Face.append(s3);
    this->Lsom_Face.append(s4);

}


bool Face::Est_Active()
{
    int i;

    for(i = 0;i < 4;i++)
    {
        if(this->Lsom_Face.at(i)->Get_actif() == false)
            return false;

    }

    return true;


}

bool Face::Est_Lier()
{
    int i;
    Sommet *s;

    for(i = 0;i < 4;i++)
    {
        s = this->Lsom_Face.at((i+1)%3);
        if(this->Lsom_Face.at(i)->Possede_Fils(s) == false)
            return false;

    }

    return true;

}

void Face::Set_cube(Cube *c)
{
    this->cube = c;

}

bool Face::Est_meme_Face(Sommet *s1, Sommet *s2)
{
    int i;
    bool b1 = false, b2 = false;

    for(i = 0;i < 4;i++)
    {
        if(this->Lsom_Face.at(i)->Get_actif() == true)
        {
            if((b1 == false) && (s1->Get_num() == this->Lsom_Face.at(i)->Get_num()))
            {
                b1 = true;
            }

            if((b2 == false) && (s2->Get_num() == this->Lsom_Face.at(i)->Get_num()))
            {
                b2 = true;
            }

        }

    }

    return ((b1 == true) && (b2 == true));

}

Cube* Face::Get_cube()
{
    return this->cube;
}

void Face::Creer_voisinage_Sommet_Face()
{
    Sommet *s1, *s2, *s3, *s4;

    s1 = this->Lsom_Face.at(0);
    s2 = this->Lsom_Face.at(1);
    s3 = this->Lsom_Face.at(2);
    s4 = this->Lsom_Face.at(3);

    s1->Add_voisinage_conv(s2);
    s1->Add_Type_Voisin(1);
    s1->Add_voisinage_conv(s3);
    s1->Add_Type_Voisin(1);

    s2->Add_voisinage_conv(s4);
    s2->Add_Type_Voisin(1);
    s2->Add_voisinage_conv(s1);
    s2->Add_Type_Voisin(1);

    s3->Add_voisinage_conv(s1);
    s3->Add_Type_Voisin(1);
    s3->Add_voisinage_conv(s4);
    s3->Add_Type_Voisin(1);

    s4->Add_voisinage_conv(s3);
    s4->Add_Type_Voisin(1);
    s4->Add_voisinage_conv(s2);
    s4->Add_Type_Voisin(1);


}

void Face::Lier_Face_Sommet(Sommet *s)
{
    int i;

    for(i = 0;i < 4;i++)
    {
        this->Lsom_Face.at(i)->Add_voisinage_conv(s);
        this->Lsom_Face.at(i)->Add_Type_Voisin(0);
        s->Add_voisinage_conv(this->Lsom_Face.at(i));
        s->Add_Type_Voisin(0);
    }

}







