
#include <QtGui>
#include <QtOpenGL>

#include <math.h>

#include "gl_widget.h"




GLWidget::GLWidget(QWidget *parent)
 : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    //Creation de la trackball
    this->trackball = new TrackBall(this->width(), this->height());
    this->Hyper = new Hypercube_aff();
    this->Hyper->Set_GLWIDGET(this);

    //this->Hyper->Set_Affichage(this);
    this->Creer_Menu();
    this->ts_sommet = false;
    this->Aff_env = false;
    this->Aff_hyp = true;
    this->Aff_tri = false;
    this->Aff_arete = true;
    this->creer_envexe = false;

    this->axe_dquat = new Vec_4D(1.0, 1.0, 1.0, 0.0);
    this->theta_dq = 0.0;

    //this->qtime_dq = new QTimer(this);
    //connect(qtime_dq, SIGNAL(timeout()), this, SLOT(updateGL()));
    //qtime_dq->start(25);

}

void GLWidget::Creer_Menu()
{
    this->MenuBar = new QMenuBar(this);
    fileMenu = this->MenuBar->addMenu(tr("&File"));
    this->SommetMenu = this->MenuBar->addMenu(tr("&Sommet"));
    this->Affichage_menu = this->MenuBar->addMenu(tr("&Affichage"));
    this->menu_version = this->MenuBar->addMenu(tr("&Version"));

    this->Nouveau_hyp = new QAction( tr("&Nouveau"), this);
    this->Nouveau_hyp->setShortcuts(QKeySequence::New);
    this->Nouveau_hyp->setStatusTip(tr("Nouveau hypercube"));
    connect(Nouveau_hyp, SIGNAL(triggered()), this, SLOT(Nouveau_Hyp()));

    this->Ouvrir_hyp = new QAction( tr("Ouvrir Fichier"), this);
    this->Ouvrir_hyp->setShortcut(QKeySequence::Open);
    this->Ouvrir_hyp->setStatusTip(tr("Ouvrir fichier"));
    connect(Ouvrir_hyp, SIGNAL(triggered()), this, SLOT(Ouvrir_Fichier()));

    this->Sauvegarder_sous_hyp = new QAction( tr("Sauvegarder Fichier"), this);
    this->Sauvegarder_sous_hyp->setShortcut(QKeySequence::Save);
    this->Sauvegarder_sous_hyp->setStatusTip(tr("Sauvegarder fichier"));
    connect(Sauvegarder_sous_hyp, SIGNAL(triggered()), this, SLOT(Sauvegarder_Fichier()));

    QAction *separator = new QAction(this);
    separator->setSeparator(true);

    QAction *separator2 = new QAction(this);
    separator2->setSeparator(true);

    this->Creer_env_act = new QAction( tr("&Créer Enveloppe"), this);
    this->Creer_env_act->setStatusTip(tr("Créer Enveloppe"));
    connect(Creer_env_act, SIGNAL(triggered()), this, SLOT(Creer_Env_convexe()));

    this->All_config = new QAction( tr("&Créer Toutes configurations"), this);
    this->All_config->setStatusTip(tr("Créer Toutes configurations"));
    connect(All_config, SIGNAL(triggered()), this, SLOT(Creer_All_Config()));

    this->Quitter_hyp = new QAction(tr("&Quitter"), this);
    this->Quitter_hyp->setShortcuts(QKeySequence::Close);
    this->Quitter_hyp->setStatusTip(tr("Quitter"));
    connect(Quitter_hyp, SIGNAL(triggered()), this, SLOT(Quitter()));

    fileMenu->addAction(this->Nouveau_hyp);
    fileMenu->addAction(this->Ouvrir_hyp);
    fileMenu->addAction(this->Sauvegarder_sous_hyp);
    fileMenu->addAction(separator);
    fileMenu->addAction(this->Creer_env_act);
    fileMenu->addAction(this->All_config);
    fileMenu->addAction(separator2);
    fileMenu->addAction(this->Quitter_hyp);

    this->Sommet_act[0] = new QAction( tr("Sommet &1"), this);
    this->Sommet_act[1] = new QAction( tr("Sommet &2"), this);
    this->Sommet_act[2] = new QAction( tr("Sommet &3"), this);
    this->Sommet_act[3] = new QAction( tr("Sommet &4"), this);
    this->Sommet_act[4] = new QAction( tr("Sommet &5"), this);
    this->Sommet_act[5] = new QAction( tr("Sommet &6"), this);
    this->Sommet_act[6] = new QAction( tr("Sommet &7"), this);
    this->Sommet_act[7] = new QAction( tr("Sommet &8"), this);

    this->Sommet_act[8] = new QAction( tr("Sommet &9"), this);
    this->Sommet_act[9] = new QAction( tr("Sommet &10"), this);
    this->Sommet_act[10] = new QAction( tr("Sommet &11"), this);
    this->Sommet_act[11] = new QAction( tr("Sommet &12"), this);
    this->Sommet_act[12] = new QAction( tr("Sommet &13"), this);
    this->Sommet_act[13] = new QAction( tr("Sommet &14"), this);
    this->Sommet_act[14] = new QAction( tr("Sommet &15"), this);
    this->Sommet_act[15] = new QAction( tr("Sommet &16"), this);

    for(int i = 0;i < 16;i++)
    {
        this->Sommet_act[i]->setCheckable(true);
    }

    this->Ts_Sommet_act = new QAction( tr("Tous sommets"), this);

    this->SommetMenu->addAction(this->Ts_Sommet_act);
    this->SommetMenu->addAction(separator);

    this->SommetMenu->addAction(this->Sommet_act[0]);
    this->SommetMenu->addAction(this->Sommet_act[1]);
    this->SommetMenu->addAction(this->Sommet_act[2]);
    this->SommetMenu->addAction(this->Sommet_act[3]);
    this->SommetMenu->addAction(this->Sommet_act[4]);
    this->SommetMenu->addAction(this->Sommet_act[5]);
    this->SommetMenu->addAction(this->Sommet_act[6]);
    this->SommetMenu->addAction(this->Sommet_act[7]);

    this->SommetMenu->addAction(this->Sommet_act[8]);
    this->SommetMenu->addAction(this->Sommet_act[9]);
    this->SommetMenu->addAction(this->Sommet_act[10]);
    this->SommetMenu->addAction(this->Sommet_act[11]);
    this->SommetMenu->addAction(this->Sommet_act[12]);
    this->SommetMenu->addAction(this->Sommet_act[13]);
    this->SommetMenu->addAction(this->Sommet_act[14]);
    this->SommetMenu->addAction(this->Sommet_act[15]);



    connect(this->Sommet_act[0], SIGNAL(triggered()), this, SLOT(Click_Sommet1()));
    connect(this->Sommet_act[1], SIGNAL(triggered()), this, SLOT(Click_Sommet2()));
    connect(this->Sommet_act[2], SIGNAL(triggered()), this, SLOT(Click_Sommet3()));
    connect(this->Sommet_act[3], SIGNAL(triggered()), this, SLOT(Click_Sommet4()));
    connect(this->Sommet_act[4], SIGNAL(triggered()), this, SLOT(Click_Sommet5()));
    connect(this->Sommet_act[5], SIGNAL(triggered()), this, SLOT(Click_Sommet6()));
    connect(this->Sommet_act[6], SIGNAL(triggered()), this, SLOT(Click_Sommet7()));
    connect(this->Sommet_act[7], SIGNAL(triggered()), this, SLOT(Click_Sommet8()));

    connect(this->Sommet_act[8], SIGNAL(triggered()), this, SLOT(Click_Sommet9()));
    connect(this->Sommet_act[9], SIGNAL(triggered()), this, SLOT(Click_Sommet10()));
    connect(this->Sommet_act[10], SIGNAL(triggered()), this, SLOT(Click_Sommet11()));
    connect(this->Sommet_act[11], SIGNAL(triggered()), this, SLOT(Click_Sommet12()));
    connect(this->Sommet_act[12], SIGNAL(triggered()), this, SLOT(Click_Sommet13()));
    connect(this->Sommet_act[13], SIGNAL(triggered()), this, SLOT(Click_Sommet14()));
    connect(this->Sommet_act[14], SIGNAL(triggered()), this, SLOT(Click_Sommet15()));
    connect(this->Sommet_act[15], SIGNAL(triggered()), this, SLOT(Click_Sommet16()));

    connect(this->Ts_Sommet_act, SIGNAL(triggered()), this, SLOT(Click_Ts_Sommet()));


    this->Aff_hyp_act = new QAction( tr("Afficher Hypercube"), this);
    this->Aff_env_a_act = new QAction( tr("Afficher arête enveloppe"), this);
    this->Aff_env_t_act = new QAction( tr("Afficher triangle enveloppe"), this);
    this->Affichage_menu->addAction(this->Aff_hyp_act);
    this->Affichage_menu->addAction(this->Aff_env_a_act);
    this->Affichage_menu->addAction(this->Aff_env_t_act);

    connect(this->Aff_hyp_act, SIGNAL(triggered()), this, SLOT(Afficher_hyper()));
    connect(this->Aff_env_a_act, SIGNAL(triggered()), this, SLOT(Afficher_arete()));
    connect(this->Aff_env_t_act, SIGNAL(triggered()), this, SLOT(Afficher_tri()));

    this->version = new QAction( tr("&Version"), this);
    this->version->setStatusTip(tr("Version"));
    connect(version, SIGNAL(triggered()), this, SLOT(Aff_version()));

    this->menu_version->addAction(this->version);


}

void GLWidget::Afficher_hyper()
{
    if(this->Aff_hyp == true)
        this->Aff_hyp = false;
    else
        this->Aff_hyp = true;

    this->updateGL();

}

void GLWidget::Afficher_arete()
{
    if(this->Aff_arete == true)
    {
        this->Aff_arete = false;
    }
    else
        this->Aff_arete = true;

    this->updateGL();

}

void GLWidget::Afficher_tri()
{
    if(this->Aff_tri == true)
    {
        this->Aff_tri = false;
    }
    else
        this->Aff_tri = true;

    this->updateGL();

}

void GLWidget::Creer_Env_convexe()
{
    int i;

    this->Hyper_env = new Hypercube();

    for(i = 1;i <= 16;i++)
    {
        if(this->Hyper->Get_Sommet(i)->Get_Etat() == true)
        {
            this->Hyper_env->Set_Sommet_Actif(i);
        }

    }

    this->Env_conv = new Env_convexe(&Hyper_env);
    this->Env_conv->Creer_Env_convexe();
    this->Env_conv->Sauvegarder_Env_convexe("convexe.txt");
    this->Hyper->Charger_Enveloppe_conv(Env_conv, Hyper_env, "convexe.txt");
    this->Aff_hyp = true;
    this->Aff_env = true;
    this->creer_envexe = true;
    this->updateGL();

}


void GLWidget::Creer_All_Config()
{
    /*
    int i, j, g;
    QString nom_fichier;
    int nb;


    for(i = 1;i < 65535;i++)
    {
        nb = 0;
        Hypercube *h = new Hypercube();
        h->Desactive_All_Sommet();
        //std::cout << i << std::endl;
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
            QVariant f(i);
            Env_convexe *e = new Env_convexe(&h);
            e->Creer_Env_convexe();
            e->Sauvegarder_Env_convexe(f.toString().append(".txt"));

        }

        //std::cout  << std::endl;

    }

    */

    this->diag_choix_fichier = new Dialog_Choix_Fichier();
    this->diag_choix_fichier->setModal(false);
    this->diag_choix_fichier->show();

}


void GLWidget::Ouvrir_Fichier()
{
    int i;

    this->Hyper_env = new Hypercube();

    for(i = 1;i <= 16;i++)
    {
        if(this->Hyper->Get_Sommet(i)->Get_Etat() == true)
        {
            this->Hyper->Get_Sommet(i)->Eteindre();
            this->Sommet_act[i-1]->setChecked(false);
        }

    }


    QStringList files = QFileDialog::getOpenFileNames(
                            this,
                            "Choisir un fichier ",
                            "./",
                            "Convexe (*.txt *.con *.vex)");

    this->Env_conv = new Env_convexe(&Hyper_env);
    this->Hyper->Charger_Enveloppe_conv(Env_conv, Hyper_env, files.at(0));
    this->Aff_hyp = true;
    this->Aff_env = true;
    this->creer_envexe = true;

    for(i = 1;i <= 16;i++)
    {
        if(this->Hyper->Get_Sommet(i)->Get_Etat() == true)
        {
            this->Sommet_act[i-1]->setChecked(true);
        }

    }

    this->updateGL();

}

void GLWidget::Sauvegarder_Fichier()
{
    int i;

    if(this->creer_envexe == true)
    {
        QString files = QFileDialog::getSaveFileName(
                                this,
                                "Choisir un fichier ",
                                "./",
                                "Convexe (*.txt *.con *.vex)");

        this->Env_conv->Sauvegarder_Env_convexe(files);
        //this->Aff_hyp = true;
        //this->Aff_env = true;
        this->updateGL();

    }

}


void GLWidget::Click_Ts_Sommet()
{
    int i;

    if(this->ts_sommet == false)
    {
        for(i = 1;i <= 16;i++)
        {
            this->Hyper->Allumer_Sommet(i);
            this->Sommet_act[i-1]->setChecked(true);
        }
        this->ts_sommet = true;
    }
    else
    {
        for(i = 1;i <= 16;i++)
        {
            this->Hyper->Eteindre_Sommet(i);
            this->Sommet_act[i-1]->setChecked(false);
        }

        this->ts_sommet = false;

    }

    this->updateGL();

}

void GLWidget::Click_Sommet1()
{
    if(this->Hyper->Get_Sommet(1)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(1);
    else
        this->Hyper->Eteindre_Sommet(1);

    this->updateGL();

}

void GLWidget::Click_Sommet2()
{
    if(this->Hyper->Get_Sommet(2)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(2);
    else
        this->Hyper->Eteindre_Sommet(2);

    this->updateGL();

}

void GLWidget::Click_Sommet3()
{
    if(this->Hyper->Get_Sommet(3)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(3);
    else
        this->Hyper->Eteindre_Sommet(3);

    this->updateGL();

}

void GLWidget::Click_Sommet4()
{
    if(this->Hyper->Get_Sommet(4)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(4);
    else
        this->Hyper->Eteindre_Sommet(4);

    this->updateGL();

}

void GLWidget::Click_Sommet5()
{
    if(this->Hyper->Get_Sommet(5)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(5);
    else
        this->Hyper->Eteindre_Sommet(5);

    this->updateGL();

}

void GLWidget::Click_Sommet6()
{
    if(this->Hyper->Get_Sommet(6)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(6);
    else
        this->Hyper->Eteindre_Sommet(6);

    this->updateGL();

}

void GLWidget::Click_Sommet7()
{
    if(this->Hyper->Get_Sommet(7)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(7);
    else
        this->Hyper->Eteindre_Sommet(7);

    this->updateGL();

}

void GLWidget::Click_Sommet8()
{
    if(this->Hyper->Get_Sommet(8)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(8);
    else
        this->Hyper->Eteindre_Sommet(8);

    this->updateGL();

}

void GLWidget::Click_Sommet9()
{
    if(this->Hyper->Get_Sommet(9)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(9);
    else
        this->Hyper->Eteindre_Sommet(9);

    this->updateGL();

}

void GLWidget::Click_Sommet10()
{
    if(this->Hyper->Get_Sommet(10)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(10);
    else
        this->Hyper->Eteindre_Sommet(10);

    this->updateGL();

}

void GLWidget::Click_Sommet11()
{
    if(this->Hyper->Get_Sommet(11)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(11);
    else
        this->Hyper->Eteindre_Sommet(11);

    this->updateGL();

}

void GLWidget::Click_Sommet12()
{
    if(this->Hyper->Get_Sommet(12)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(12);
    else
        this->Hyper->Eteindre_Sommet(12);

    this->updateGL();

}

void GLWidget::Click_Sommet13()
{
    if(this->Hyper->Get_Sommet(13)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(13);
    else
        this->Hyper->Eteindre_Sommet(13);

    this->updateGL();

}

void GLWidget::Click_Sommet14()
{
    if(this->Hyper->Get_Sommet(14)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(14);
    else
        this->Hyper->Eteindre_Sommet(14);

    this->updateGL();

}

void GLWidget::Click_Sommet15()
{
    if(this->Hyper->Get_Sommet(15)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(15);
    else
        this->Hyper->Eteindre_Sommet(15);

    this->updateGL();

}

void GLWidget::Click_Sommet16()
{
    if(this->Hyper->Get_Sommet(16)->Get_Etat() == false)
        this->Hyper->Allumer_Sommet(16);
    else
        this->Hyper->Eteindre_Sommet(16);

    this->updateGL();

}



void GLWidget::Nouveau_Hyp()
{
    delete Hyper;
    this->trackball = new TrackBall(this->width(), this->height());
    this->Hyper = new Hypercube_aff();
    this->creer_envexe = false;

    for(i = 0;i < 16;i++)
    {
        this->Sommet_act[i]->setChecked(false);
    }

    this->updateGL();

}

void GLWidget::Quitter()
{
    this->parentWidget()->close();
}

void GLWidget::Aff_version()
{
    this->dversion = new Version();
    this->dversion->setModal(true);
    this->dversion->show();

}

GLWidget::~GLWidget()
{
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}



void GLWidget::setXRotation(int angle)
{


}

void GLWidget::setYRotation(int angle)
{

}

void GLWidget::setZRotation(int angle)
{

}

void GLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //Initialise Lumiere
    static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

}

void GLWidget::paintGL()
{
    int i;
    Vec_4D bary, *v, vs;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //glMatrixMode(GL_MODELVIEW);
    ///glLoadIdentity();
    //gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


    // Fonction de melange pour transparence dependant de la valeur source alpha(Nouveau)
    glBlendFunc(GL_ONE,GL_ONE_MINUS_DST_COLOR);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);


    glPushMatrix();



    //Utilise Trackball - si active
    if(this->trackball->start_track)
        glMultMatrixd(this->trackball->TrackBall_GetMRot());


    /*glPushMatrix();

        //this->theta_dq++;
        //glScalef(2.0f, 2.0f, 2.0f);
        dual_quaternion::Mat_Rotation_DQuat(this->theta_dq, this->axe_dquat, this->M);

        //if(this->theta_dq < 360.0)
        glMultMatrixd(this->M);

        qDebug() << cos((theta_dq*M_PI/180.0)/2.0) + sin((theta_dq*M_PI/180.0)/2.0)<< endl;

        this->theta_dq+=0.1;
        if(this->theta_dq >= 99999999.0)
            this->theta_dq = 0;*/


    /*glBegin(GL_QUADS);

    glColor4f(1.0f, .0f, .0f, 0.25f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glColor4f(1.0f, .0f, .0f, 0.5f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    glEnd();*/



    if(this->Aff_hyp == true)
    {
        this->Hyper->Afficher_Hypercube(true);


        QFont serifFont("Helvetica [Cronyx]", 10, QFont::Bold);

        for(i = 1;i <= 16;i++)
        {
            Sommet_hyp_aff *s = this->Hyper->Get_Sommet(i);
            QVariant text(s->Get_Num());

            if(s->Get_Etat() == false)
                glColor4f(0.f, 0.0f, 0.0f, 1.0f);
            else
                glColor4f(1.0f, 0.0f, 0.0f, 1.0f);

            if(((s->Get_Num()&1)) == 1)
                this->renderText(s->Get_Coord()->x - 0.25f, s->Get_Coord()->y, s->Get_Coord()->z, text.toString(), serifFont);
            else
                this->renderText(s->Get_Coord()->x + 0.25f, s->Get_Coord()->y, s->Get_Coord()->z, text.toString(), serifFont);


        }

    }

    if(this->Aff_env == true)
        this->Hyper->Afficher_Enveloppe_conv(this->Aff_tri, this->Aff_arete);





    //glPopMatrix();

    glPopMatrix();

    glFlush();



}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)width/(GLfloat)height, 0.1, 128.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    this->trackball = new TrackBall(width, height);


}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        //Evenement Click Trackball
        this->trackball->TrackBall_Click(event->pos().x(), event->pos().y());
        event->accept();
        this->updateGL();
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        //Evenement Move Trackball
        this->trackball->TrackBall_Move(event->pos().x(), event->pos().y());
        event->accept();
        this->updateGL();

     } else {
        this->trackball->TrackBall_Release(event->pos().x(), event->pos().y());
     }

}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        //Evenement Release Trackball
        this->trackball->TrackBall_Release(event->pos().x(), event->pos().y());
        event->accept();
    }

}
