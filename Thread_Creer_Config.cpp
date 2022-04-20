#include "Thread_Creer_Config.h"

Thread_Creer_Config::Thread_Creer_Config(Dialog_Choix_Fichier *qd, QString dir) : QThread(0)
{
    this->qdiag = qd;
    this->dir = dir;
}

void Thread_Creer_Config::run()
{
    int i, j, g;
    int nb;

   dir.append("\\");

    for(i = 1;i < 65535;i++)
    {
        nb = 0;
        Hypercube *h = new Hypercube();
        h->Desactive_All_Sommet();
        for(j = 0;j < 16;j++)
        {
            g = 0;
            g = i & (1 << j);

            if(g > 0)
            {
                nb++;
                h->Set_Sommet_Actif(j+1);
            }



        }

        if(nb > 1)
        {
            QString s;
            s.append(dir);
            QVariant f(i);
            Env_convexe *e = new Env_convexe(&h);
            e->Creer_Env_convexe();
            e->Sauvegarder_Env_convexe(s.append(f.toString().append(".txt")));

        }

        QVariant v(i);
        this->qdiag->Lab_Num_Config->setText(v.toString());
        this->qdiag->progressBar->setValue(i);

    }

    this->qdiag->Creer_config_bout->setEnabled(true);


}
