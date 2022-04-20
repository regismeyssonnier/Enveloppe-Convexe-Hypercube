#include "Sommet.h"


//classe Sommet

Sommet::Sommet(Vec_4D *vec, int num, Sommet *s)
{
    this->vec_som = new Vec_4D(vec->x, vec->y, vec->z, vec->t);
    this->num = num;
    this->som_parent = s;
    this->actif = false;
    this->a_arete_int = false;

}

Sommet::Sommet(int num)
{
    this->num = num;
}

void Sommet::Add_parente(Sommet *s)
{
    this->som_parent = s;
}

void Sommet::Add_voisinage(Sommet *s)
{
    this->som_voisin.append(s);


}

void Sommet::Add_voisinage_conv(Sommet *s)
{
    this->som_vois_ec.append(s);
}

void Sommet::Set_actif(bool b)
{
    this->actif = b;
}

bool Sommet::Get_actif()
{
    return this->actif;
}

QList<Sommet*>* Sommet::Get_voisinage()
{
    return &som_voisin;

}

QList<Sommet*>* Sommet::Get_voisinage_conv()
{
    return &som_vois_ec;

}

int* Sommet::Get_cube_associe()
{
    return &Cube_ass[0];
}

void Sommet::Set_Cube_associe(int ca[4])
{
    int i;
    for(i = 0;i < 4;i++)
        this->Cube_ass[i] = ca[i];

}

int Sommet::Get_num()
{
    return this->num;
}

bool Sommet::Existe_voisin_conv(Sommet *s)
{
    int i, n;
    n = this->som_vois_ec.count();
    for(i = 0;i < n;i++)
    {
        if(this->som_vois_ec.at(i)->Get_num() == s->Get_num())
            return true;
    }

    return false;

}

int Sommet::Get_NB_Voisin_conv()
{
    return this->som_vois_ec.count();

}

Arrete_interieur* Sommet::Get_Arrete_interieur()
{
    if(this->a_arete_int == false)
        throw new ExceptionPasArreteInt(this->num);
    else
        return this->arete_int;
}

bool Sommet::Possede_Arrete_int()
{
    return this->a_arete_int;
}

void Sommet::Set_Arrete_int(Arrete_interieur *a)
{
    this->arete_int = a;
}

bool Sommet::Possede_Fils(Sommet *s)
{
    int i, n;

    n = this->som_vois_ec.count();
    for(i = 0;i < n;i++)
    {
        if(this->som_vois_ec.at(i)->Get_num() == s->Get_num())
        {
            return true;
        }
    }

    return false;

}

bool Sommet::Possede_Fils(Sommet *s, int &num)
{
    int i, n;

    n = this->som_vois_ec.count();
    for(i = 0;i < n;i++)
    {
        if(this->som_vois_ec.at(i)->Get_num() == s->Get_num())
        {
            num = i;
            return true;
        }
    }

    return false;

}

QList<int>* Sommet::Get_triangle()
{
    return &triangle;
}

void Sommet::Add_Triangle(int tri)
{
    this->triangle.append(tri);
}

int Sommet::Get_NB_Triangle()
{
    return this->triangle.count();

}

void Sommet::Add_Type_Voisin(int type)
{
    this->t_som_voisin.append(type);

}

int Sommet::Get_Type_Voisin(int num)
{
    return this->t_som_voisin.at(num);
}

Sommet::~Sommet()
{
    delete vec_som;

}

#ifdef QT_HYP_CMODE
void Sommet::Affiche_Sommet()
{
    std::cout << "num : " << this->num << ", parent : " << this->som_parent->num << " ,vec X : " << this->vec_som->x << " , y : " << this->vec_som->y << " , z : " << this->vec_som->z << " , t : " << this->vec_som->t << "\n";

}

#endif

// fin classe Sommet
