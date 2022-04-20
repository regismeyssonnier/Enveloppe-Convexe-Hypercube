#include "hypercube.h"




//classe Hypercube
Hypercube::Hypercube()
{

    Sommet *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s0 = 0;
    Sommet *s9, *s10, *s11, *s12, *s13, *s14, *s15, *s16;

    //Creation Sommet 1
    Vec_4D *v = new Vec_4D(0.0, 0.0, 0.0, 0.0);
    s1 = new Sommet(v, 1, s0);
    this->som_hyp[0] = s1;

    //Creation Sommet 2
    v = new Vec_4D(1.0, 0.0, 0.0, 0.0);
    s2 = new Sommet(v, 2, s0);
    this->som_hyp[1] = s2;

    //Creation Sommet 3
    v = new Vec_4D(0.0, 1.0, 0.0, 0.0);
    s3 = new Sommet(v, 3, s0);
    this->som_hyp[2] = s3;

    //Creation Sommet 4
    v = new Vec_4D(1.0, 1.0, 0.0, 0.0);
    s4 = new Sommet(v, 4, s0);
    this->som_hyp[3] = s4;

    //Creation Sommet 5
    v = new Vec_4D(0.0, 0.0, 1.0, 0.0);
    s5 = new Sommet(v, 5, s0);
    this->som_hyp[4] = s5;

    //Creation Sommet 6
    v = new Vec_4D(1.0, 0.0, 1.0, 0.0);
    s6 = new Sommet(v, 6, s0);
    this->som_hyp[5] = s6;

    //Creation Sommet 7
    v = new Vec_4D(0.0, 1.0, 1.0, 0.0);
    s7 = new Sommet(v, 7, s0);
    this->som_hyp[6] = s7;

    //Creation Sommet 8
    v = new Vec_4D(1.0, 1.0, 1.0, 0.0);
    s8 = new Sommet(v, 8, s0);
    this->som_hyp[7] = s8;

    //-----------Sommet Second Cube---------------//

    //Creation Sommet 9
    v = new Vec_4D(0.0, 0.0, 0.0, 1.0);
    s9 = new Sommet(v, 9, s1);
    this->som_hyp[8] = s9;

    //Creation Sommet 10
    v = new Vec_4D(1.0, 0.0, 0.0, 1.0);
    s10 = new Sommet(v, 10, s2);
    this->som_hyp[9] = s10;

    //Creation Sommet 11
    v = new Vec_4D(0.0, 1.0, 0.0, 1.0);
    s11 = new Sommet(v, 11, s3);
    this->som_hyp[10] = s11;

    //Creation Sommet 12
    v = new Vec_4D(1.0, 1.0, 0.0, 1.0);
    s12 = new Sommet(v, 12, s4);
    this->som_hyp[11] = s12;

    //Creation Sommet 13
    v = new Vec_4D(0.0, 0.0, 1.0, 1.0);
    s13 = new Sommet(v, 13, s5);
    this->som_hyp[12] = s13;

    //Creation Sommet 14
    v = new Vec_4D(1.0, 0.0, 1.0, 1.0);
    s14 = new Sommet(v, 14, s6);
    this->som_hyp[13] = s14;

    //Creation Sommet 15
    v = new Vec_4D(0.0, 1.0, 1.0, 1.0);
    s15 = new Sommet(v, 15, s7);
    this->som_hyp[14] = s15;

    //Creation Sommet 16
    v = new Vec_4D(1.0, 1.0, 1.0, 1.0);
    s16 = new Sommet(v, 16, s8);
    this->som_hyp[15] = s16;

    //Ajout de la parente
    s1->Add_parente(s9);
    s2->Add_parente(s10);
    s3->Add_parente(s11);
    s4->Add_parente(s12);
    s5->Add_parente(s13);
    s6->Add_parente(s14);
    s7->Add_parente(s15);
    s8->Add_parente(s16);

    //Ajout du voisinage
    s1->Add_voisinage(s2);
    s1->Add_voisinage(s3);
    s1->Add_voisinage(s5);
    s1->Add_voisinage(s9);

    s2->Add_voisinage(s1);
    s2->Add_voisinage(s4);
    s2->Add_voisinage(s6);
    s2->Add_voisinage(s10);

    s3->Add_voisinage(s1);
    s3->Add_voisinage(s4);
    s3->Add_voisinage(s7);
    s3->Add_voisinage(s11);

    s4->Add_voisinage(s2);
    s4->Add_voisinage(s3);
    s4->Add_voisinage(s8);
    s4->Add_voisinage(s12);

    s5->Add_voisinage(s1);
    s5->Add_voisinage(s6);
    s5->Add_voisinage(s7);
    s5->Add_voisinage(s13);

    s6->Add_voisinage(s2);
    s6->Add_voisinage(s5);
    s6->Add_voisinage(s8);
    s6->Add_voisinage(s14);

    s7->Add_voisinage(s3);
    s7->Add_voisinage(s5);
    s7->Add_voisinage(s8);
    s7->Add_voisinage(s15);

    s8->Add_voisinage(s4);
    s8->Add_voisinage(s6);
    s8->Add_voisinage(s7);
    s8->Add_voisinage(s16);

    s9->Add_voisinage(s1);
    s9->Add_voisinage(s10);
    s9->Add_voisinage(s11);
    s9->Add_voisinage(s13);

    s10->Add_voisinage(s2);
    s10->Add_voisinage(s9);
    s10->Add_voisinage(s12);
    s10->Add_voisinage(s14);

    s11->Add_voisinage(s3);
    s11->Add_voisinage(s9);
    s11->Add_voisinage(s12);
    s11->Add_voisinage(s15);

    s12->Add_voisinage(s4);
    s12->Add_voisinage(s10);
    s12->Add_voisinage(s11);
    s12->Add_voisinage(s16);

    s13->Add_voisinage(s5);
    s13->Add_voisinage(s9);
    s13->Add_voisinage(s14);
    s13->Add_voisinage(s15);

    s14->Add_voisinage(s6);
    s14->Add_voisinage(s10);
    s14->Add_voisinage(s13);
    s14->Add_voisinage(s16);

    s15->Add_voisinage(s7);
    s15->Add_voisinage(s11);
    s15->Add_voisinage(s13);
    s15->Add_voisinage(s16);

    s16->Add_voisinage(s8);
    s16->Add_voisinage(s12);
    s16->Add_voisinage(s14);
    s16->Add_voisinage(s15);



    //Creation des cubes : mode point
    //Cube int
    this->cube[0] = new Cube(1, s1, s2, s3, s4, s5, s6, s7, s8);
    QList<Arrete_interieur*>* Lai = new QList<Arrete_interieur*>();
    Lai->append(new Arrete_interieur(s10, s15, 1));
    Lai->append(new Arrete_interieur(s13, s12, 2));
    Lai->append(new Arrete_interieur(s11, s14, 3));

    QList<Arrete_interieur*>* Lai2 = new QList<Arrete_interieur*>();
    Lai2->append(new Arrete_interieur(s9, s16, 1));
    Lai2->append(new Arrete_interieur(s11, s14, 2));
    Lai2->append(new Arrete_interieur(s12, s13, 3));

    QList<Arrete_interieur*>* Lai3 = new QList<Arrete_interieur*>();
    Lai3->append(new Arrete_interieur(s10, s15, 1));
    Lai3->append(new Arrete_interieur(s12, s13, 2));
    Lai3->append(new Arrete_interieur(s9, s16, 3));

    QList<Arrete_interieur*>* Lai4 = new QList<Arrete_interieur*>();
    Lai4->append(new Arrete_interieur(s10, s15, 1));
    Lai4->append(new Arrete_interieur(s11, s14, 2));
    Lai4->append(new Arrete_interieur(s9, s16, 3));

    this->cube[0]->Ajouter_Arete_Int_Cext(Lai, Lai2, Lai3, Lai4);

    //Cube ext
    this->cube[1] = new Cube(2, s9, s10, s11, s12, s13, s14, s15, s16);

    Lai = new QList<Arrete_interieur*>();
    Lai->append(new Arrete_interieur(s2, s7, 1));
    Lai->append(new Arrete_interieur(s4, s5, 2));
    Lai->append(new Arrete_interieur(s3, s6, 3));

    Lai2 = new QList<Arrete_interieur*>();
    Lai2->append(new Arrete_interieur(s1, s8, 1));
    Lai2->append(new Arrete_interieur(s3, s6, 2));
    Lai2->append(new Arrete_interieur(s4, s5, 3));

    Lai3 = new QList<Arrete_interieur*>();
    Lai3->append(new Arrete_interieur(s2, s7, 1));
    Lai3->append(new Arrete_interieur(s1, s8, 2));
    Lai3->append(new Arrete_interieur(s4, s5, 3));

    Lai4 = new QList<Arrete_interieur*>();
    Lai4->append(new Arrete_interieur(s1, s8, 1));
    Lai4->append(new Arrete_interieur(s3, s6, 2));
    Lai4->append(new Arrete_interieur(s2, s7, 3));

    this->cube[1]->Ajouter_Arete_Int_Cext(Lai, Lai2, Lai3, Lai4);

    this->cube[1]->Ajouter_triangle_Int(1, s4, s7, s6);
    this->cube[1]->Ajouter_triangle_Int(1, s3, s5, s2);
    this->cube[1]->Ajouter_triangle_Int(2, s3, s8, s5);
    this->cube[1]->Ajouter_triangle_Int(2, s1, s6, s4);
    this->cube[1]->Ajouter_triangle_Int(3, s4, s7, s1);
    this->cube[1]->Ajouter_triangle_Int(3, s2, s5, s8);
    this->cube[1]->Ajouter_triangle_Int(4, s3, s8, s2);
    this->cube[1]->Ajouter_triangle_Int(4, s1, s6, s7);


    //Cube dr
    this->cube[2] = new Cube(3, s2, s10, s4, s12, s6, s14, s8, s16);
    //Cube g
    this->cube[3] = new Cube(4, s9, s1, s11, s3, s13, s5, s15, s7);
    //Cube dev
    this->cube[4] = new Cube(5, s9, s10, s11, s12, s1, s2, s3, s4);
    //Cube der
    this->cube[5] = new Cube(6, s5, s6, s7, s8, s13, s14, s15, s16);
    //Cube ht
    this->cube[6] = new Cube(7, s3, s4, s11, s12, s7, s8, s15, s16);
    //Cube bas
    this->cube[7] = new Cube(8, s9, s10, s1, s2, s13, s14, s5, s6);


    //Definition des cubes associés
    int ca1[] = {1,4,5,8};
    s1->Set_Cube_associe(ca1);
    int ca2[] = {1,3,5,8};
    s2->Set_Cube_associe(ca2);
    int ca3[] = {1,4,5,7};
    s3->Set_Cube_associe(ca3);
    int ca4[] = {1,3,5,7};
    s4->Set_Cube_associe(ca4);
    int ca5[] = {1,4,6,8};
    s5->Set_Cube_associe(ca5);
    int ca6[] = {1,3,6,8};
    s6->Set_Cube_associe(ca6);
    int ca7[] = {1,4,6,7};
    s7->Set_Cube_associe(ca7);
    int ca8[] = {1,3,6,7};
    s8->Set_Cube_associe(ca8);
    int ca9[] = {2,4,5,8};
    s9->Set_Cube_associe(ca9);
    int ca10[] = {2,3,5,8};
    s10->Set_Cube_associe(ca10);
    int ca11[] = {2,4,5,7};
    s11->Set_Cube_associe(ca11);
    int ca12[] = {2,3,5,7};
    s12->Set_Cube_associe(ca12);
    int ca13[] = {2,4,6,8};
    s13->Set_Cube_associe(ca13);
    int ca14[] = {2,3,6,8};
    s14->Set_Cube_associe(ca14);
    int ca15[] = {2,4,6,7};
    s15->Set_Cube_associe(ca15);
    int ca16[] = {2,3,6,7};
    s16->Set_Cube_associe(ca16);

    //Ajout des arêtes d'intérieures
    //de l'hypercube
    this->LArrete_int.append(new Arrete_interieur(s5, s12, 1));
    this->LArrete_int.at(0)->Ajoute_Triangle_Int(s3, s8, s2);
    this->LArrete_int.at(0)->Ajoute_Triangle_Int(s1, s6, s7);

    Lai = new QList<Arrete_interieur*>();
    Lai->append(new Arrete_interieur(s1, s8, 1));
    Lai->append(new Arrete_interieur(s2, s7, 2));
    Lai->append(new Arrete_interieur(s3, s6, 3));
    //Lai->append(new Arrete_interieur(s4, s5, 4));
    Lai->append(new Arrete_interieur(s9, s16, 6));
    Lai->append(new Arrete_interieur(s10, s15, 7));
    Lai->append(new Arrete_interieur(s11, s14, 8));
    this->LArrete_int.at(0)->Ajouter_Arete_int_cext(Lai);

    //Face adjacente
    /*this->LArrete_int.at(0)->Lier_Sommet_Face_Adjacente(s9);
    this->LArrete_int.at(0)->Lier_Sommet_Face_Adjacente(s10);
    this->LArrete_int.at(0)->Lier_Sommet_Face_Adjacente(s11);

    this->LArrete_int.at(0)->Lier_Sommet_Face_Adjacente(s14);
    this->LArrete_int.at(0)->Lier_Sommet_Face_Adjacente(s16);*/
    this->LArrete_int.at(0)->Lier_Sommet_Faceci1(s6);
    this->LArrete_int.at(0)->Lier_Sommet_Faceci1(s7);
    this->LArrete_int.at(0)->Lier_Sommet_Faceci1(s8);
    this->LArrete_int.at(0)->Lier_Sommet_Faceci2(s1);
    this->LArrete_int.at(0)->Lier_Sommet_Faceci2(s3);
    this->LArrete_int.at(0)->Lier_Sommet_Faceci2(s7);
    this->LArrete_int.at(0)->Lier_Sommet_Faceci3(s1);
    this->LArrete_int.at(0)->Lier_Sommet_Faceci3(s2);
    this->LArrete_int.at(0)->Lier_Sommet_Faceci3(s6);

    this->LArrete_int.at(0)->Lier_Sommet_Facece1(s9);
    this->LArrete_int.at(0)->Lier_Sommet_Facece1(s10);
    this->LArrete_int.at(0)->Lier_Sommet_Facece1(s11);
    this->LArrete_int.at(0)->Lier_Sommet_Facece2(s10);
    this->LArrete_int.at(0)->Lier_Sommet_Facece2(s14);
    this->LArrete_int.at(0)->Lier_Sommet_Facece2(s16);
    this->LArrete_int.at(0)->Lier_Sommet_Facece3(s11);
    this->LArrete_int.at(0)->Lier_Sommet_Facece3(s15);
    this->LArrete_int.at(0)->Lier_Sommet_Facece3(s16);


    this->LArrete_int.append(new Arrete_interieur(s1, s16, 2));
    this->LArrete_int.at(1)->Ajoute_Triangle_Int(s4, s7, s6);
    this->LArrete_int.at(1)->Ajoute_Triangle_Int(s3, s5, s2);

    Lai = new QList<Arrete_interieur*>();
    Lai->append(new Arrete_interieur(s4, s5, 1));
    Lai->append(new Arrete_interieur(s2, s7, 2));
    Lai->append(new Arrete_interieur(s3, s6, 3));
    //Lai->append(new Arrete_interieur(s1, s8, 4));
    Lai->append(new Arrete_interieur(s10, s15, 5));
    Lai->append(new Arrete_interieur(s11, s14, 6));
    Lai->append(new Arrete_interieur(s12, s13, 7));
    this->LArrete_int.at(1)->Ajouter_Arete_int_cext(Lai);

    //Face adjacente
    /*this->LArrete_int.at(1)->Lier_Sommet_Face_Adjacente(s13);
    this->LArrete_int.at(1)->Lier_Sommet_Face_Adjacente(s14);
    this->LArrete_int.at(1)->Lier_Sommet_Face_Adjacente(s15);

    this->LArrete_int.at(1)->Lier_Sommet_Face_Adjacente(s10);
    this->LArrete_int.at(1)->Lier_Sommet_Face_Adjacente(s12);*/

    this->LArrete_int.at(1)->Lier_Sommet_Faceci1(s2);
    this->LArrete_int.at(1)->Lier_Sommet_Faceci1(s3);
    this->LArrete_int.at(1)->Lier_Sommet_Faceci1(s4);
    this->LArrete_int.at(1)->Lier_Sommet_Faceci2(s3);
    this->LArrete_int.at(1)->Lier_Sommet_Faceci2(s5);
    this->LArrete_int.at(1)->Lier_Sommet_Faceci2(s7);
    this->LArrete_int.at(1)->Lier_Sommet_Faceci3(s2);
    this->LArrete_int.at(1)->Lier_Sommet_Faceci3(s5);
    this->LArrete_int.at(1)->Lier_Sommet_Faceci3(s6);

    this->LArrete_int.at(1)->Lier_Sommet_Facece1(s13);
    this->LArrete_int.at(1)->Lier_Sommet_Facece1(s14);
    this->LArrete_int.at(1)->Lier_Sommet_Facece1(s15);
    this->LArrete_int.at(1)->Lier_Sommet_Facece2(s10);
    this->LArrete_int.at(1)->Lier_Sommet_Facece2(s12);
    this->LArrete_int.at(1)->Lier_Sommet_Facece2(s14);
    this->LArrete_int.at(1)->Lier_Sommet_Facece3(s11);
    this->LArrete_int.at(1)->Lier_Sommet_Facece3(s12);
    this->LArrete_int.at(1)->Lier_Sommet_Facece3(s15);


    this->LArrete_int.append(new Arrete_interieur(s2, s15, 3));
    this->LArrete_int.at(2)->Ajoute_Triangle_Int(s3, s8, s5);
    this->LArrete_int.at(2)->Ajoute_Triangle_Int(s1, s6, s4);

    Lai = new QList<Arrete_interieur*>();
    Lai->append(new Arrete_interieur(s4, s5, 1));
    Lai->append(new Arrete_interieur(s1, s8, 2));
    Lai->append(new Arrete_interieur(s3, s6, 3));
    //Lai->append(new Arrete_interieur(s2, s7, 4));
    Lai->append(new Arrete_interieur(s9, s16, 5));
    Lai->append(new Arrete_interieur(s11, s14, 6));
    Lai->append(new Arrete_interieur(s12, s13, 7));
    this->LArrete_int.at(2)->Ajouter_Arete_int_cext(Lai);

    //Face adjacente
    /*this->LArrete_int.at(2)->Lier_Sommet_Face_Adjacente(s13);
    this->LArrete_int.at(2)->Lier_Sommet_Face_Adjacente(s14);

    this->LArrete_int.at(2)->Lier_Sommet_Face_Adjacente(s16);
    this->LArrete_int.at(2)->Lier_Sommet_Face_Adjacente(s9);
    this->LArrete_int.at(2)->Lier_Sommet_Face_Adjacente(s11);*/

    this->LArrete_int.at(2)->Lier_Sommet_Faceci1(s1);
    this->LArrete_int.at(2)->Lier_Sommet_Faceci1(s3);
    this->LArrete_int.at(2)->Lier_Sommet_Faceci1(s4);
    this->LArrete_int.at(2)->Lier_Sommet_Faceci2(s4);
    this->LArrete_int.at(2)->Lier_Sommet_Faceci2(s6);
    this->LArrete_int.at(2)->Lier_Sommet_Faceci2(s8);
    this->LArrete_int.at(2)->Lier_Sommet_Faceci3(s1);
    this->LArrete_int.at(2)->Lier_Sommet_Faceci3(s5);
    this->LArrete_int.at(2)->Lier_Sommet_Faceci3(s6);

    this->LArrete_int.at(2)->Lier_Sommet_Facece1(s9);
    this->LArrete_int.at(2)->Lier_Sommet_Facece1(s11);
    this->LArrete_int.at(2)->Lier_Sommet_Facece1(s13);
    this->LArrete_int.at(2)->Lier_Sommet_Facece2(s13);
    this->LArrete_int.at(2)->Lier_Sommet_Facece2(s14);
    this->LArrete_int.at(2)->Lier_Sommet_Facece2(s16);
    this->LArrete_int.at(2)->Lier_Sommet_Facece3(s11);
    this->LArrete_int.at(2)->Lier_Sommet_Facece3(s12);
    this->LArrete_int.at(2)->Lier_Sommet_Facece3(s16);


    this->LArrete_int.append(new Arrete_interieur(s6, s11, 4));
    this->LArrete_int.at(3)->Ajoute_Triangle_Int(s4, s7, s1);
    this->LArrete_int.at(3)->Ajoute_Triangle_Int(s2, s5, s8);

    Lai = new QList<Arrete_interieur*>();
    Lai->append(new Arrete_interieur(s4, s5, 1));
    Lai->append(new Arrete_interieur(s1, s8, 2));
    Lai->append(new Arrete_interieur(s2, s7, 3));
    //Lai->append(new Arrete_interieur(s3, s6, 4));
    Lai->append(new Arrete_interieur(s9, s16, 5));
    Lai->append(new Arrete_interieur(s10, s15, 6));
    Lai->append(new Arrete_interieur(s12, s13, 7));
    this->LArrete_int.at(3)->Ajouter_Arete_int_cext(Lai);

    //Face adjacente
    /*this->LArrete_int.at(3)->Lier_Sommet_Face_Adjacente(s9);
    this->LArrete_int.at(3)->Lier_Sommet_Face_Adjacente(s10);

    this->LArrete_int.at(3)->Lier_Sommet_Face_Adjacente(s12);
    this->LArrete_int.at(3)->Lier_Sommet_Face_Adjacente(s13);
    this->LArrete_int.at(3)->Lier_Sommet_Face_Adjacente(s15);*/

    this->LArrete_int.at(3)->Lier_Sommet_Faceci1(s2);
    this->LArrete_int.at(3)->Lier_Sommet_Faceci1(s4);
    this->LArrete_int.at(3)->Lier_Sommet_Faceci1(s8);
    this->LArrete_int.at(3)->Lier_Sommet_Faceci2(s5);
    this->LArrete_int.at(3)->Lier_Sommet_Faceci2(s7);
    this->LArrete_int.at(3)->Lier_Sommet_Faceci2(s8);
    this->LArrete_int.at(3)->Lier_Sommet_Faceci3(s1);
    this->LArrete_int.at(3)->Lier_Sommet_Faceci3(s2);
    this->LArrete_int.at(3)->Lier_Sommet_Faceci3(s5);

    this->LArrete_int.at(3)->Lier_Sommet_Facece1(s9);
    this->LArrete_int.at(3)->Lier_Sommet_Facece1(s13);
    this->LArrete_int.at(3)->Lier_Sommet_Facece1(s15);
    this->LArrete_int.at(3)->Lier_Sommet_Facece2(s9);
    this->LArrete_int.at(3)->Lier_Sommet_Facece2(s10);
    this->LArrete_int.at(3)->Lier_Sommet_Facece2(s12);
    this->LArrete_int.at(3)->Lier_Sommet_Facece3(s12);
    this->LArrete_int.at(3)->Lier_Sommet_Facece3(s14);
    this->LArrete_int.at(3)->Lier_Sommet_Facece3(s16);


    this->LArrete_int.append(new Arrete_interieur(s3, s14, 5));
    this->LArrete_int.at(4)->Ajoute_Triangle_Int(s4, s7, s1);
    this->LArrete_int.at(4)->Ajoute_Triangle_Int(s2, s5, s8);

    Lai = new QList<Arrete_interieur*>();
    Lai->append(new Arrete_interieur(s4, s5, 1));
    Lai->append(new Arrete_interieur(s1, s8, 2));
    Lai->append(new Arrete_interieur(s2, s7, 3));
    //Lai->append(new Arrete_interieur(s3, s6, 4));
    Lai->append(new Arrete_interieur(s9, s16, 5));
    Lai->append(new Arrete_interieur(s10, s15, 6));
    Lai->append(new Arrete_interieur(s12, s13, 7));
    this->LArrete_int.at(4)->Ajouter_Arete_int_cext(Lai);

    //Face adjacente
    /*this->LArrete_int.at(4)->Lier_Sommet_Face_Adjacente(s13);

    this->LArrete_int.at(4)->Lier_Sommet_Face_Adjacente(s15);
    this->LArrete_int.at(4)->Lier_Sommet_Face_Adjacente(s16);
    this->LArrete_int.at(4)->Lier_Sommet_Face_Adjacente(s10);
    this->LArrete_int.at(4)->Lier_Sommet_Face_Adjacente(s12);*/

    this->LArrete_int.at(4)->Lier_Sommet_Faceci1(s1);
    this->LArrete_int.at(4)->Lier_Sommet_Faceci1(s5);
    this->LArrete_int.at(4)->Lier_Sommet_Faceci1(s7);
    this->LArrete_int.at(4)->Lier_Sommet_Faceci2(s1);
    this->LArrete_int.at(4)->Lier_Sommet_Faceci2(s2);
    this->LArrete_int.at(4)->Lier_Sommet_Faceci2(s4);
    this->LArrete_int.at(4)->Lier_Sommet_Faceci3(s4);
    this->LArrete_int.at(4)->Lier_Sommet_Faceci3(s7);
    this->LArrete_int.at(4)->Lier_Sommet_Faceci3(s8);

    this->LArrete_int.at(4)->Lier_Sommet_Facece1(s10);
    this->LArrete_int.at(4)->Lier_Sommet_Facece1(s12);
    this->LArrete_int.at(4)->Lier_Sommet_Facece1(s16);
    this->LArrete_int.at(4)->Lier_Sommet_Facece2(s13);
    this->LArrete_int.at(4)->Lier_Sommet_Facece2(s15);
    this->LArrete_int.at(4)->Lier_Sommet_Facece2(s16);
    this->LArrete_int.at(4)->Lier_Sommet_Facece3(s9);
    this->LArrete_int.at(4)->Lier_Sommet_Facece3(s10);
    this->LArrete_int.at(4)->Lier_Sommet_Facece3(s13);


    this->LArrete_int.append(new Arrete_interieur(s8, s9, 6));
    this->LArrete_int.at(5)->Ajoute_Triangle_Int(s4, s7, s6);
    this->LArrete_int.at(5)->Ajoute_Triangle_Int(s2, s5, s3);

    Lai = new QList<Arrete_interieur*>();
    Lai->append(new Arrete_interieur(s4, s5, 1));
    Lai->append(new Arrete_interieur(s3, s6, 2));
    Lai->append(new Arrete_interieur(s2, s7, 3));
    //Lai->append(new Arrete_interieur(s1, s8, 4));
    Lai->append(new Arrete_interieur(s10, s15, 5));
    Lai->append(new Arrete_interieur(s11, s14, 6));
    Lai->append(new Arrete_interieur(s12, s13, 7));
    this->LArrete_int.at(5)->Ajouter_Arete_int_cext(Lai);

    //Face adjacente

    /*this->LArrete_int.at(5)->Lier_Sommet_Face_Adjacente(s10);
    this->LArrete_int.at(5)->Lier_Sommet_Face_Adjacente(s11);
    this->LArrete_int.at(5)->Lier_Sommet_Face_Adjacente(s12);
    this->LArrete_int.at(5)->Lier_Sommet_Face_Adjacente(s13);
    this->LArrete_int.at(5)->Lier_Sommet_Face_Adjacente(s15);*/

    this->LArrete_int.at(5)->Lier_Sommet_Faceci1(s5);
    this->LArrete_int.at(5)->Lier_Sommet_Faceci1(s6);
    this->LArrete_int.at(5)->Lier_Sommet_Faceci1(s7);
    this->LArrete_int.at(5)->Lier_Sommet_Faceci2(s2);
    this->LArrete_int.at(5)->Lier_Sommet_Faceci2(s4);
    this->LArrete_int.at(5)->Lier_Sommet_Faceci2(s6);
    this->LArrete_int.at(5)->Lier_Sommet_Faceci3(s3);
    this->LArrete_int.at(5)->Lier_Sommet_Faceci3(s4);
    this->LArrete_int.at(5)->Lier_Sommet_Faceci3(s7);

    this->LArrete_int.at(5)->Lier_Sommet_Facece1(s10);
    this->LArrete_int.at(5)->Lier_Sommet_Facece1(s11);
    this->LArrete_int.at(5)->Lier_Sommet_Facece1(s12);
    this->LArrete_int.at(5)->Lier_Sommet_Facece2(s11);
    this->LArrete_int.at(5)->Lier_Sommet_Facece2(s13);
    this->LArrete_int.at(5)->Lier_Sommet_Facece2(s15);
    this->LArrete_int.at(5)->Lier_Sommet_Facece3(s10);
    this->LArrete_int.at(5)->Lier_Sommet_Facece3(s13);
    this->LArrete_int.at(5)->Lier_Sommet_Facece3(s14);


    this->LArrete_int.append(new Arrete_interieur(s4, s13, 7));
    this->LArrete_int.at(6)->Ajoute_Triangle_Int(s3, s8, s2);
    this->LArrete_int.at(6)->Ajoute_Triangle_Int(s1, s6, s7);

    Lai = new QList<Arrete_interieur*>();
    Lai->append(new Arrete_interieur(s1, s8, 1));
    Lai->append(new Arrete_interieur(s3, s6, 2));
    Lai->append(new Arrete_interieur(s2, s7, 3));
    //Lai->append(new Arrete_interieur(s4, s5, 4));
    Lai->append(new Arrete_interieur(s9, s16, 5));
    Lai->append(new Arrete_interieur(s10, s15, 6));
    Lai->append(new Arrete_interieur(s11, s14, 7));
    this->LArrete_int.at(6)->Ajouter_Arete_int_cext(Lai);

    //Face adjacente

    /*this->LArrete_int.at(6)->Lier_Sommet_Face_Adjacente(s14);
    this->LArrete_int.at(6)->Lier_Sommet_Face_Adjacente(s15);
    this->LArrete_int.at(6)->Lier_Sommet_Face_Adjacente(s16);
    this->LArrete_int.at(6)->Lier_Sommet_Face_Adjacente(s9);
    this->LArrete_int.at(6)->Lier_Sommet_Face_Adjacente(s11);*/

    this->LArrete_int.at(6)->Lier_Sommet_Faceci1(s1);
    this->LArrete_int.at(6)->Lier_Sommet_Faceci1(s2);
    this->LArrete_int.at(6)->Lier_Sommet_Faceci1(s3);
    this->LArrete_int.at(6)->Lier_Sommet_Faceci2(s2);
    this->LArrete_int.at(6)->Lier_Sommet_Faceci2(s6);
    this->LArrete_int.at(6)->Lier_Sommet_Faceci2(s8);
    this->LArrete_int.at(6)->Lier_Sommet_Faceci3(s3);
    this->LArrete_int.at(6)->Lier_Sommet_Faceci3(s7);
    this->LArrete_int.at(6)->Lier_Sommet_Faceci3(s8);

    this->LArrete_int.at(6)->Lier_Sommet_Facece1(s9);
    this->LArrete_int.at(6)->Lier_Sommet_Facece1(s11);
    this->LArrete_int.at(6)->Lier_Sommet_Facece1(s15);
    this->LArrete_int.at(6)->Lier_Sommet_Facece2(s14);
    this->LArrete_int.at(6)->Lier_Sommet_Facece2(s15);
    this->LArrete_int.at(6)->Lier_Sommet_Facece2(s16);
    this->LArrete_int.at(6)->Lier_Sommet_Facece3(s9);
    this->LArrete_int.at(6)->Lier_Sommet_Facece3(s10);
    this->LArrete_int.at(6)->Lier_Sommet_Facece3(s14);


    this->LArrete_int.append(new Arrete_interieur(s7, s10, 8));
    this->LArrete_int.at(7)->Ajoute_Triangle_Int(s3, s8, s5);
    this->LArrete_int.at(7)->Ajoute_Triangle_Int(s1, s6, s4);

    Lai = new QList<Arrete_interieur*>();
    Lai->append(new Arrete_interieur(s1, s8, 1));
    Lai->append(new Arrete_interieur(s3, s6, 2));
    Lai->append(new Arrete_interieur(s4, s5, 3));
    //Lai->append(new Arrete_interieur(s2, s7, 4));
    Lai->append(new Arrete_interieur(s9, s16, 5));
    Lai->append(new Arrete_interieur(s11, s14, 6));
    Lai->append(new Arrete_interieur(s12, s13, 7));
    this->LArrete_int.at(7)->Ajouter_Arete_int_cext(Lai);

    //Face adjacente
    /*this->LArrete_int.at(7)->Lier_Sommet_Face_Adjacente(s9);

    this->LArrete_int.at(7)->Lier_Sommet_Face_Adjacente(s11);
    this->LArrete_int.at(7)->Lier_Sommet_Face_Adjacente(s12);
    this->LArrete_int.at(7)->Lier_Sommet_Face_Adjacente(s14);
    this->LArrete_int.at(7)->Lier_Sommet_Face_Adjacente(s16);*/

    this->LArrete_int.at(7)->Lier_Sommet_Faceci1(s5);
    this->LArrete_int.at(7)->Lier_Sommet_Faceci1(s6);
    this->LArrete_int.at(7)->Lier_Sommet_Faceci1(s8);
    this->LArrete_int.at(7)->Lier_Sommet_Faceci2(s1);
    this->LArrete_int.at(7)->Lier_Sommet_Faceci2(s3);
    this->LArrete_int.at(7)->Lier_Sommet_Faceci2(s5);
    this->LArrete_int.at(7)->Lier_Sommet_Faceci3(s3);
    this->LArrete_int.at(7)->Lier_Sommet_Faceci3(s4);
    this->LArrete_int.at(7)->Lier_Sommet_Faceci3(s8);

    this->LArrete_int.at(7)->Lier_Sommet_Facece1(s9);
    this->LArrete_int.at(7)->Lier_Sommet_Facece1(s11);
    this->LArrete_int.at(7)->Lier_Sommet_Facece1(s12);
    this->LArrete_int.at(7)->Lier_Sommet_Facece2(s12);
    this->LArrete_int.at(7)->Lier_Sommet_Facece2(s14);
    this->LArrete_int.at(7)->Lier_Sommet_Facece2(s16);
    this->LArrete_int.at(7)->Lier_Sommet_Facece3(s9);
    this->LArrete_int.at(7)->Lier_Sommet_Facece3(s13);
    this->LArrete_int.at(7)->Lier_Sommet_Facece3(s14);


    //Creation des faces diagonales de l'hypercube
    this->LFace_D.append(new Face(s1, s2, s15, s16));
    this->LFace_D.append(new Face(s5, s6, s11, s12));
    this->LFace_D.append(new Face(s1, s5, s12, s16));
    this->LFace_D.append(new Face(s2, s6, s11, s15));
    this->LFace_D.append(new Face(s3, s4, s13, s14));
    this->LFace_D.append(new Face(s3, s7, s10, s14));
    this->LFace_D.append(new Face(s4, s8, s9, s13));
    this->LFace_D.append(new Face(s7, s8, s9, s10));

    this->LFace_D.append(new Face(s5, s7, s10, s12));
    this->LFace_D.append(new Face(s6, s8, s9, s11));
    this->LFace_D.append(new Face(s13, s15, s2, s4));
    this->LFace_D.append(new Face(s14, s16, s1, s3));

    this->LFace_D.append(new Face(s1, s10, s7, s16));
    this->LFace_D.append(new Face(s9, s2, s15, s8));
    this->LFace_D.append(new Face(s11, s4, s13, s6));
    this->LFace_D.append(new Face(s3, s12, s5, s14));

    this->LFace_D.append(new Face(s5, s9, s8, s12));
    this->LFace_D.append(new Face(s13, s1, s16, s4));
    this->LFace_D.append(new Face(s11, s7, s6, s10));
    this->LFace_D.append(new Face(s15, s3, s14, s2));

    this->LFace_D.append(new Face(s9, s1, s8, s16));
    this->LFace_D.append(new Face(s10, s2, s7, s15));
    this->LFace_D.append(new Face(s11, s3, s6, s14));
    this->LFace_D.append(new Face(s12, s4, s5, s13));

    //0 sommet actif
    this->nb_som_act = 0;


}

QList<Arrete_interieur*>* Hypercube::Get_Arrete_interieur()
{
    return &LArrete_int;
}

#ifdef QT_HYP_CMODE
void Hypercube::Affiche_Hypercube()
{
    int i;

    for(i = 0;i < 8;i++)
    {
        this->cube[i]->Affiche_Cube();
        std::cout << "\n\n";
    }

}

#endif

void Hypercube::Set_Sommet_Actif(int num)
{
    if((num < 1) || (num > 16))
        throw new ExceptionNumberSommet(num);
    else
    {
        if(!this->som_hyp[num-1]->Get_actif())
        {
            this->som_hyp[num-1]->Set_actif(true);
            this->nb_som_act++;
        }

    }

}

void Hypercube::Active_All_Sommet()
{
    int i = 0;

    for(i = 0;i < 16;i++)
    {
        this->som_hyp[i]->Set_actif(true);

    }

    this->nb_som_act = 16;

}

void Hypercube::Desactive_All_Sommet()
{
    int i = 0;

    for(i = 0;i < 16;i++)
    {
        this->som_hyp[i]->Set_actif(false);

    }

    this->nb_som_act = 0;

}

Sommet* Hypercube::Get_Sommet_Hyper(int i)
{
    if((i < 1) || (i > 16))
        throw new ExceptionNumberSommet(i);
    else
        return this->som_hyp[i-1];

}

int Hypercube::Get_NB_Sommet_actif()
{
    return this->nb_som_act;

}

Cube* Hypercube::Get_Cube(int num)
{
    if((num < 1) && (num > 8))
        new ExceptionNumberCube(num);
    else
        return this->cube[num-1];
}

Arrete_interieur* Hypercube::Get_Arrete_interieur(int num)
{
    if((num < 1) && (num > 8))
        throw new ExceptionNumberArreteIntHyp(num);
    else
        return this->LArrete_int.at(num-1);

}


bool Hypercube::Possede_Face_Diag_Active()
{
    int i, n;
    n = this->LFace_D.count();

    for(i = 0;i < n;i++)
    {
        if((this->LFace_D.at(i)->Est_Active() == true) &&
           (this->LFace_D.at(i)->Est_Lier() == true)
          )
            return true;
    }

    return false;
}


Hypercube::~Hypercube()
{
    int i;

    for(i = 0;i < 16;i++)
    {
        this->som_hyp[i]->~Sommet();
    }

    for(i = 0;i < 8;i++)
    {
        this->cube[i]->~Cube();
    }



}


// Fin classe Hypercube
