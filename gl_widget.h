#ifndef GL_WIDGET_H
#define GL_WIDGET_H

#include <QGLWidget>
#include <QtGui>
#include <QtOpenGL>
#include "Trackball.h"
#include "Hypercube_aff.h"
#include "Widget_New_Hyp.h"
#include "Env_convexe/hypercube.h"
#include "Env_convexe/Env_convexe.h"
#include "Dual_quaternion.h"
#include <QTimer>
#include <QFileDialog>
#include "dialog_choix_fichier.h"
#include "version.h"
#include <QVariant>

class QtLogo;
class QMenu;
class QAction;
class Hypercube_aff;
class Widget_New_Hyp;

class GLWidget : public QGLWidget
{
    Q_OBJECT

    //Methode
public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    //Variable prive
private:
    TrackBall *trackball, *trot;
    int i;
    Hypercube_aff *Hyper;
    QMenu *fileMenu;
    QMenuBar *MenuBar;
    QAction *Nouveau_hyp;
    QAction *Ouvrir_hyp;
    QAction *Sauvegarder_sous_hyp;
    QAction *Sauv_hyp;
    QAction *All_config;
    QAction *Quitter_hyp;
    Widget_New_Hyp *fen_new;

    QMenu *SommetMenu;
    QAction *Sommet_act[16];
    QAction *Ts_Sommet_act;
    bool ts_sommet;

    QAction *Creer_env_act;

    Hypercube *Hyper_env;
    Env_convexe *Env_conv;

    QMenu *Affichage_menu;
    QAction *Aff_env_a_act;
    QAction *Aff_env_t_act;
    QAction *Aff_hyp_act;

    bool Aff_env;
    bool Aff_hyp;
    bool Aff_tri;
    bool Aff_arete;

    //Dual quaternion
    dual_quaternion *dquat;
    double theta_dq;
    double M[16];
    Vec_4D *axe_dquat;

    //Timer
    QTimer *qtime_dq;

    Sommet_hyp_aff *sommet[16];

    //Creer env convexe
    bool creer_envexe;

    Dialog_Choix_Fichier *diag_choix_fichier;

    QMenu *menu_version;
    QAction *version;

    Version *dversion;


    //Methode prive
private:
    void Creer_Menu();

    //Slots
public slots:
    void Nouveau_Hyp();
    void Quitter();

    void Click_Sommet1();
    void Click_Sommet2();
    void Click_Sommet3();
    void Click_Sommet4();
    void Click_Sommet5();
    void Click_Sommet6();
    void Click_Sommet7();
    void Click_Sommet8();

    void Click_Sommet9();
    void Click_Sommet10();
    void Click_Sommet11();
    void Click_Sommet12();
    void Click_Sommet13();
    void Click_Sommet14();
    void Click_Sommet15();
    void Click_Sommet16();

    void Click_Ts_Sommet();

    void Creer_Env_convexe();

    void Afficher_hyper();
    void Afficher_arete();
    void Afficher_tri();

    void Ouvrir_Fichier();
    void Sauvegarder_Fichier();
    void Creer_All_Config();
    void Aff_version();


public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


};

#endif // GL_WIDGET_H
