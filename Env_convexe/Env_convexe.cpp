#include "Env_convexe.h"


Env_convexe::Env_convexe(Hypercube **h)
{
    this->Hyper = h;
}


void Env_convexe::Creer_Env_convexe()
{
    if((*Hyper)->Get_NB_Sommet_actif() <= 5)
        this->Creer_Env_convexe_fdf3_5();
    else
        this->Creer_Env_convexe_fdf();

}


void Env_convexe::Creer_Env_convexe_fdf()
{

    int i, j=0,w=0;
    Hypercube *h = *Hyper;
    int SA[h->Get_NB_Sommet_actif()];
    int CA[8] = {0,0,0,0,0,0,0,0};

    //Cherche les sommets actifs
    //et les place ds un tableau
    for(i = 1;i <= 16;i++)
    {
        if(this->Get_SA(i)->Get_actif() == true)
        {
            SA[j] = i;
            j++;

            //Cherche Cube actif
            int *t = this->Get_SA(i)->Get_cube_associe();
            for(w = 0;w < 4;w++)
            {
                CA[t[w]-1] = 1;
            }

        }

    }

#ifdef DEBUG_ENV_CONV
    for(i = 0;i < 8;i++)
        std::cout << "CA : " << CA[i] << std::endl;

    for(i = 0;i < j;i++)
    {
        std::cout << "nb som : " << SA[i] << std::endl;

    }
#endif

    //Créer arrête de l'env convexe,
    //deja existante ds l'hypercube
    QList<Sommet*>* lv;
    int n, k, l;
    for(i = 0;i < j;i++)
    {
        for(k = 0;k < j;k++)
        {

            lv = this->Get_SA(SA[i])->Get_voisinage();
            n = lv->count();
            for(l = 0;l < n;l++)
            {
                if(lv->at(l)->Get_num() == SA[k])
                {
                    this->Get_SA(SA[i])->Add_voisinage_conv(this->Get_SA(SA[k]));
                    this->Get_SA(SA[i])->Add_Type_Voisin(1);

                }


            }

        }

    }



#ifdef DEBUG_ENV_CONV
    for(i = 0;i < j;i++)
    {
        lv = this->Get_SA(SA[i])->Get_voisinage_conv();
        n = lv->count();
        for(l = 0;l < n;l++)
        {
            std::cout << "sommet : " << SA[i] << ", voisin : " << lv->at(l)->Get_num() << std::endl;

        }

        std::cout << std::endl;

    }


    for(i = 1;i <= 8;i++)
    {
        std::cout << "Cube : " << (*Hyper)->Get_Cube(i)->Get_num() << std::endl;
        n = (*Hyper)->Get_Cube(i)->Get_Sommet_Actif()->count();
        lv = (*Hyper)->Get_Cube(i)->Get_Sommet_Actif();

        for(l = 0;l < n;l++)
        {
            std::cout << "Sommet actif : " << lv->at(l)->Get_num() << std::endl;
        }

    }

    for(i = 1;i <= 8;i++)
    {
        n = (*Hyper)->Get_Cube(i)->Get_Sommet_Actif()->count();
        for(l = 1;l <= 4;l++)
        {
            Arrete_interieur *a = (*Hyper)->Get_Cube(i)->Get_Arrete_interieur(l);
            std::cout << "Cube : " << i << ", Arrete int  : " << a->Get_num() << ", s1 : " << a->Get_S1()->Get_num() << ", s2 : " << a->Get_S2()->Get_num() << std::endl;
        }
        std::cout << "i : " << i << std::endl;
    }
     std::cout << "i : " << i << std::endl;
#endif

    //Calcule des arretes a ajouter

    int num, nv2, iv, l2;
    int trouve = 0;
    QList<Sommet*>* lv2;
    Cube *c;
    Arrete_interieur *ai;
    Sommet *sv;
    //Pour chaque cube actif
    for(i = 0;i < 8;i++)
    {
        num = i+1;
        if(CA[i] == 1)
        {
            trouve = 0;
            n = (*Hyper)->Get_Cube(num)->Get_Sommet_Actif()->count();
            lv = (*Hyper)->Get_Cube(num)->Get_Sommet_Actif();
            c = (*Hyper)->Get_Cube(num);
            //Pour chaque sommet actif de ce cube
            for(l = 0;l < n;l++)
            {
                //Ajout de l'arrete d'interieur
                //Si nb sommet <= 5
                if((((n >= 2) && (n <= 4)) || ((n == 5) && (c->Possede_Face_active() == true))) && (trouve == 0))
                //if(((n >= 2) && (n <= 4)) && (trouve == 0))
                {
                    std::cout << "Cube : " << i+1 << ", n:" << n  << std::endl;
                    Sommet *s = lv->at(l);
                    //Recherche de l'arrete interieur
                    for(iv = 1;iv <= 4;iv++)
                    {

                        ai = c->Get_Arrete_interieur(iv);
                        //Si c'est l'arrete interieur
                        if( (ai->Get_S1()->Get_num() == s->Get_num()) ||
                            (ai->Get_S2()->Get_num() == s->Get_num())
                          )
                        {
                            sv = (ai->Get_S1()->Get_num() == s->Get_num()) ? ai->Get_S2() : ai->Get_S1();
                            if((c->Est_Sommet_Actif_Du_Cube(sv)) && (c->Est_meme_Face(s, sv) == false))
                            {
                                //Si cube interne
                                //if((i == 0) || (i == 1))
                                //{
                                    if(ai->Est_Ajoutable(h->Get_Arrete_interieur()) == true)
                                    {
                                        s->Add_voisinage_conv(sv);
                                        s->Add_Type_Voisin(0);
                                        sv->Add_voisinage_conv(s);
                                        sv->Add_Type_Voisin(0);
                                        trouve = 1;
                                        break;

                                    }

                                /*}
                                else
                                {
                                    s->Add_voisinage_conv(sv);
                                    s->Add_Type_Voisin(0);
                                    sv->Add_voisinage_conv(s);
                                    sv->Add_Type_Voisin(0);
                                    trouve = 1;
                                    break;

                                }*/



                            }

                        }

                    }


                }


                //Ajout des aretes manquantes
                //avec les autres sommets du meme cube
                //n'appartenant pas a la meme face
                nv2 = (*Hyper)->Get_Cube(num)->Get_Sommet_Actif()->count();
                lv2 = (*Hyper)->Get_Cube(num)->Get_Sommet_Actif();
                Sommet *sommet_courant;
                Sommet *s;

                if(nv2 <= 7)
                {
                    //Pour tous les sommets actifs
                    for(l2 = 0;l2 < nv2;l2++)
                    {
                        s = lv2->at(l2);
                        //l : indice sommet actif courant
                        sommet_courant = lv->at(l);
                        if(s->Get_num() != sommet_courant->Get_num())
                        {
                            //Si arrete est inexistante
                            if(sommet_courant->Existe_voisin_conv(s) == false)
                            {
                                //Si meme face pas active
                                if((c->Est_meme_Face_Hyp(sommet_courant, s) == false) && (c->Est_Arrete_interieur(sommet_courant, s) == false))
                                {
                                    //qDebug() << "Cube:" << c->Get_num() << ", ajout s:" << s->Get_num()  << ", som_courant : " << sommet_courant->Get_num() << endl;
                                    sommet_courant->Add_voisinage_conv(s);
                                    sommet_courant->Add_Type_Voisin(0);

                                }
                            }

                        }

                    }

                }



            }

        }

    }


    //Dernier passage
    //Test s'il y a des arêtes d'intérieure
    //de l'hypercube à ajouter

    trouve = 0;
    for(i = 1;(i <= 16) /*&&(trouve == 0)*/;i++)
    {
        Sommet *s = this->Get_SA(i);
        if(s->Get_actif())
        {

            //Recherche de l'arrete interieur
            for(iv = 1;iv <= 8;iv++)
            {

                ai = (*Hyper)->Get_Arrete_interieur(iv);
                sv = (ai->Get_S1()->Get_num() == s->Get_num()) ? ai->Get_S2() : ai->Get_S1();
                //Si c'est l'arrete interieur
                if((sv->Get_actif() == true) && (ai->Test_arrete(s, sv) == true))
                {
                    if(/*(h->Get_Cube(1)->Est_Actif() == false) && (h->Get_Cube(1)->Possede_Face_Diagonale_Active() == false) &&
                       (ai->Est_Actif_Triangle_Int() == false) && (ai->Est_Ajoutable_Hyp() == true) &&
                       (h->Possede_Face_Diag_Active() == false) &&*/ (ai->Forme_Pyramide() == true)
                      )
                    {
                        //qDebug() << "num ai : " << ai->Get_S1()->Get_num() << endl;
                        s->Add_voisinage_conv(sv);
                        s->Add_Type_Voisin(0);
                        sv->Add_voisinage_conv(s);
                        sv->Add_Type_Voisin(0);
                        trouve = 1;
                        break;

                    }

                }

            }



        }

    }





#ifdef DEBUG_ENV_CONV
    //Affichage env convexe
    Sommet *s;
    for(i = 1;i <= 16;i++)
    {
        if(h->Get_Sommet_Hyper(i)->Get_actif())
        {
            s = h->Get_Sommet_Hyper(i);
            lv = s->Get_voisinage_conv();
            n = lv->count();
            for(j = 0;j < n;j++)
            {
                std::cout << "Sommet : " << s->Get_num() << ", voisin : " << lv->at(j)->Get_num() << ", type : " << s->Get_Type_Voisin(j) <<  std::endl;
            }

        }
    }
#endif



}

void Env_convexe::Creer_Env_convexe_fdf3_5()
{
    Hypercube *h = *Hyper;
    int nb_sa, i, j, w, n, k;
    int SA[h->Get_NB_Sommet_actif()];
    int CA[8] = {0,0,0,0,0,0,0,0};
    Cube *c;
    QList<Sommet*> *lv;

    //nb sommet actif
    nb_sa = (*Hyper)->Get_NB_Sommet_actif();


    //Cherche les sommets actifs
    //et les place ds un tableau
    j = 0;
    for(i = 1;i <= 16;i++)
    {
        if(this->Get_SA(i)->Get_actif() == true)
        {
            SA[j] = i;
            j++;

            //Cherche Cube actif
            int *t = this->Get_SA(i)->Get_cube_associe();
            for(w = 0;w < 4;w++)
            {
                CA[t[w]-1] = 1;
            }

        }

    }


    if(nb_sa == 2)
    {
        this->Get_SA(SA[0])->Add_voisinage_conv(this->Get_SA(SA[1]));
        this->Get_SA(SA[1])->Add_voisinage_conv(this->Get_SA(SA[0]));
    }
    else if(nb_sa == 3)
    {
        this->Get_SA(SA[0])->Add_voisinage_conv(this->Get_SA(SA[1]));
        this->Get_SA(SA[0])->Add_voisinage_conv(this->Get_SA(SA[2]));

        this->Get_SA(SA[1])->Add_voisinage_conv(this->Get_SA(SA[0]));
        this->Get_SA(SA[1])->Add_voisinage_conv(this->Get_SA(SA[2]));

        this->Get_SA(SA[2])->Add_voisinage_conv(this->Get_SA(SA[0]));
        this->Get_SA(SA[2])->Add_voisinage_conv(this->Get_SA(SA[1]));

    }
    else if(nb_sa == 4)
    {
        int num = -1;

        //Trouver une face active
        for(i = 1;i <= 8;i++)
        {
            c = h->Get_Cube(i);
            if(c->Possede_Face_active(&num) == true)
            {
                break;
            }

        }

        //Si trouver une face
        if(num != -1)
        {
            c->Creer_voisinage_Face(num);

        }
        else
        {
            this->Creer_Env_convexe_fdf();
            return;

        }


    }

    else if(nb_sa == 5)
    {
        int num, snum, trouve = 0, num_sl;
        int nb, n;

        std::cout << "5 sommets" << std::endl;

        num = -1;

        //Trouver une face active
        for(i = 1;i <= 8;i++)
        {
            c = h->Get_Cube(i);
            if(c->Possede_Face_active(&num) == true)
            {
                std::cout << "Face active" << std::endl;
                break;
            }

        }

        std::cout << "Face : " << num << std::endl;
        //Si trouver une face
        if(num != -1)
        {
            c->Creer_voisinage_Face(num);
            std::cout << "Cherche sommet libre" << std::endl;
            for(i = 1;i <= 16;i++)
            {
                std::cout << "i : " << i << std::endl;
                if(this->Get_SA(i)->Get_actif() == true)
                {
                    if(this->Get_SA(i)->Get_NB_Voisin_conv() < 2)
                    {
                        num_sl = i;
                        break;
                    }
                }

            }


            c->Lier_Face_Sommet(num, this->Get_SA(num_sl));

        }
        else
        {
            this->Creer_Env_convexe_fdf();
            return;

        }



    }


#ifdef DEBUG_ENV_CONV
    //Affichage env convexe
    Sommet *s;
    for(i = 1;i <= 16;i++)
    {
        if(h->Get_Sommet_Hyper(i)->Get_actif())
        {
            s = h->Get_Sommet_Hyper(i);
            lv = s->Get_voisinage_conv();
            n = lv->count();
            for(j = 0;j < n;j++)
            {
                std::cout << "Sommet : " << s->Get_num() << ", voisin : " << lv->at(j)->Get_num() << std::endl;
            }

        }
    }
#endif


}





void Env_convexe::Trianguler_env_convexe()
{
    int i, j, k, l, n;

    int marque[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


    QList<Sommet*> *Fils;
    QList<Sommet*> *Filsj;
    int nj, ind, ntr, num;

    for(i = 1;i <= 16;i++)
    {
        if(this->Get_SA(i)->Get_actif() == true)
        {
            //std::cout << "0" << std::endl;
            //std::cout << "sc : " << this->Get_SA(i)->Get_num() << std::endl;
            n = this->Get_SA(i)->Get_NB_Voisin_conv();
            Fils = this->Get_SA(i)->Get_voisinage_conv();
            for(j = 0;j < (n-1);j++)
            {
                //std::cout << "1" << std::endl;
                for(k = j+1;k < n;k++)
                {
                    if( (marque[Fils->at(j)->Get_num()-1] == 0) && (marque[Fils->at(k)->Get_num()-1] == 0) )
                    {
                        // std::cout << "2" << std::endl;
                        //Si triangle
                        if(Fils->at(j)->Possede_Fils(Fils->at(k)))
                        {
                            std::cout << "3" << std::endl;
                            int *tri = new int[3];
                            tri[0] = this->Get_SA(i)->Get_num();
                            tri[1] = Fils->at(j)->Get_num();
                            tri[2] = Fils->at(k)->Get_num();
                            this->Triangle.append(tri);


                        }
                        else
                        {
                            //std::cout << "4" << std::endl;
                            nj = Fils->at(j)->Get_NB_Voisin_conv();
                            Filsj = Fils->at(j)->Get_voisinage_conv();
                            //Pour tt fils de j
                            for(l = 0;l < nj;l++)
                            {
                                if(Filsj->at(l)->Get_num() != this->Get_SA(i)->Get_num())
                                {
                                    bool rf = Filsj->at(l)->Possede_Fils(Fils->at(k), num);
                                    if(rf == true)
                                    {
                                        std::cout << "possede fils " << (num) << std::endl;
                                        if (Filsj->at(l)->Get_Type_Voisin(num) == this->Get_SA(i)->Get_Type_Voisin(j))
                                        {

                                            int *tri = new int[3];
                                            tri[0] = this->Get_SA(i)->Get_num();
                                            tri[1] = Fils->at(j)->Get_num();
                                            tri[2] = Fils->at(k)->Get_num();
                                            this->Triangle.append(tri);



                                            tri = new int[3];
                                            tri[0] = Fils->at(j)->Get_num();
                                            tri[1] = Filsj->at(l)->Get_num();
                                            tri[2] = Fils->at(k)->Get_num();
                                            this->Triangle.append(tri);

                                        }


                                        break;

                                    }
                                }
                            }

                        }

                    }
                }
            }

            marque[i-1] = 1;

        }

    }


    #ifdef DEBUG_ENV_CONV
    n = this->Triangle.count();
    int *tri;
    for(i = 0;i < n;i++)
    {
        tri = this->Triangle.at(i);
        std::cout << "Triangle : " << i << ", " << tri[0] << "," << tri[1] << "," << tri[2] << std::endl;
    }

    #endif


    //this->Trouver_tetraedre();


}

void Env_convexe::Sauvegarder_Env_convexe(QString nom_fichier)
{
    QFile *file;
    int i, j, k, l, n, num;
    int mat_num[16][16];
    QList<Sommet*>* Lsommet;
    Hypercube *h = *Hyper;

    for(i = 0;i < 16;i++)
        for(j = 0;j < 16;j++)
            mat_num[i][j] = 0;

    this->Trianguler_env_convexe();


    file = new QFile(nom_fichier);
    if(!file->open(QIODevice::WriteOnly| QIODevice::Text))
        return;
    QTextStream  out(file);
    out.setCodec("UTF-8");

    num = 1;
    for(i = 1;i <= 16;i++)
    {
        if(this->Get_SA(i)->Get_actif() == true)
        {
            n = this->Get_SA(i)->Get_NB_Voisin_conv();
            Lsommet = this->Get_SA(i)->Get_voisinage_conv();
            for(j = 0;j < n;j++)
            {
                if(mat_num[this->Get_SA(i)->Get_num()-1][Lsommet->at(j)->Get_num()-1] == 0)
                {
                    out << 'a' << " " << this->Get_SA(i)->Get_num() << " " << Lsommet->at(j)->Get_num() << endl;
                    mat_num[this->Get_SA(i)->Get_num()-1][Lsommet->at(j)->Get_num()-1] = num;
                    mat_num[Lsommet->at(j)->Get_num()-1][this->Get_SA(i)->Get_num()-1] = num;
                    num++;

                }
            }


        }

    }

    bool ajouter = false;
    int nb, nbs;
    QList<Sommet*> *LT = new QList<Sommet*>();
    QList<Sommet*> *LSL;
    int* Tri;
    n = this->Triangle.count();
    for(i = 0;i < n;i++)
    {
        Tri = this->Triangle.at(i);

        qDebug() << Tri[0] << " " << Tri[1] << " " << Tri[2];
        LT->clear();
        LT->append(this->Get_SA(Tri[0]));
        LT->append(this->Get_SA(Tri[1]));
        LT->append(this->Get_SA(Tri[2]));

        ajouter = true;

        for(j = 1;j <= 8;j++)
        {
            if(h->Get_Cube(j)->Get_Sommet_Actif()->count() == 5)
            {
                if(h->Get_Cube(j)->Est_Meme_Cube(LT) == true)
                {
                    nb = 0;

                    //qDebug() << "cube : " << j;
                    LSL = h->Get_Cube(j)->Get_Sommet_Libre(LT);
                    for(k = 0;k < 2;k++)
                    {
                        //qDebug() << "sommet : " << LSL->at(k)->Get_num();

                        for(l = 0;l < 3;l++)
                        {
                            if(LSL->at(k)->Possede_Fils(LT->at(l)) == true)
                            {
                                nb++;

                            }
                        }

                    }

                    if(nb == 6)
                        ajouter = false;

                    break;


                }


            }

        }

        if(ajouter == true)
        {
            out << 't' << " " << Tri[0] << " " << Tri[1] << " " << Tri[2] << endl;
        }



    }


    out << "f";

    file->close();




}

void Env_convexe::Charger_Env_convexe(QString nom_fichier, QList<Arrete *> *Ar, QList<int *> *Triangle)
{
    QFile *file;

    file = new QFile(nom_fichier);
    if(!file->open(QIODevice::ReadOnly| QIODevice::Text))
        return;

    QTextStream  in(file);
    QString c;
    int as1, as2, s1, s2, s3;
    Arrete *ar;
    Sommet *so1, *so2;
    int* Tri;

    c.append('0');
    in.setCodec("UTF-8");

    while(c.at(0) != 'f')
    {

        in >> c;
        if(c.at(0) == 'a')
        {
            in >> as1 >> as2;
            so1 = new Sommet(as1);
            so2 = new Sommet(as2);
            ar = new Arrete(so1, so2, 0);
            Ar->append(ar);

            //std::cout << "s1 : " << as1 << ", s2 : " << as2 << std::endl;
        }
        else if(c.at(0) == 't')
        {
            in >> s1 >> s2 >> s3;
            Tri = new int[3];
            Tri[0] = s1;
            Tri[1] = s2;
            Tri[2] = s3;
            Triangle->append(Tri);

            //std::cout << "triangle : " << "s1 : " << s1 << ", s2 : " << s2 << ", s3 : " << s3 << std::endl;
        }

    }

    file->close();

}

void Env_convexe::Trouver_tetraedre()
{
    int i, j, n = this->Triangle.count();
    int *marque = new int[n];
    QList<Sommet*>* Fils;


    for(i = 0;i < n;i++)
        marque[i] = 0;

    for(i = 1;i <= 16;i++)
    {
        if(this->Get_SA(i)->Get_actif() == true)
        {
            Fils = this->Get_SA(i)->Get_voisinage_conv();
            n = Fils->count();
            for(j = 0;j < n;j++)
            {
                std::cout << "fils : " << Fils->at(j)->Get_num() << std::endl;
                this->Est_Dans_2Triangles(Fils->at(j), this->Get_SA(i), marque);
                /*if(this->Est_Dans_2Triangles(Fils->at(j), marque))
                {

                }*/

                break;

            }


            break;

        }

    }




}

bool Env_convexe::Est_Dans_2Triangles(Sommet *s, Sommet *p, int marque[])
{
    int i, n, j, ind;
    n = s->Get_triangle()->count();
    QList<int>* tri = s->Get_triangle();
    int *stri, nb=0;
    int a1, a2, ind_a1, ind_a2;

    //Pour tous les triangles de s
    for(i = 0;i < n;i++)
    {
        ind = tri->at(i);
        stri = this->Triangle.at(ind);
        //Pour tous les sommets d'1 triangle de s
        for(j = 0;j < 3;j++)
        {
            if((stri[j] == s->Get_num()) && (marque[stri[j]] == 0))
            {
                nb++;

                break;
            }
            else if(p->Get_num() != stri[j])
            {
                if(nb == 1)
                {
                    a1 = stri[j];
                    ind_a1 = ind;
                }
                else
                {
                    a2 = stri[j];
                    ind_a2 = ind;
                }

            }

            std::cout << "s : " << stri[j] << std::endl;

        }

        if(nb == 2)
            break;
    }

    if(nb == 2)
    {
        /*std::cout << "-----------------" << std::endl;
        stri = this->Triangle.at(ind_a1);
        for(j = 0;j < 3;j++)
        {
            std::cout << "s : " << stri[j] << std::endl;
        }

        stri = this->Triangle.at(ind_a2);
        for(j = 0;j < 3;j++)
        {
            std::cout << "s : " << stri[j] << std::endl;
        }*/

        return true;

    }
    else
        return false;

}

Sommet* Env_convexe::Get_SA(int num)
{
    return (*Hyper)->Get_Sommet_Hyper(num);

}
