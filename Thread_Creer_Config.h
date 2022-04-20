#ifndef THREAD_CREER_CONFIG_H
#define THREAD_CREER_CONFIG_H

#include <QThread>
#include "Env_convexe/Env_convexe.h"
#include "Env_convexe/hypercube.h"
#include <QVariant>
#include <QDialog>
#include "dialog_choix_fichier.h"

QT_BEGIN_NAMESPACE
class Dialog_Choix_Fichier;
QT_END_NAMESPACE

class Thread_Creer_Config : public QThread
{
public:
    Thread_Creer_Config(Dialog_Choix_Fichier *qd, QString dir);

    //Methode public
public:
    void run();

    //Variable Prive
private:
    Dialog_Choix_Fichier *qdiag;
    QString dir;

};


#endif // THREAD_CREER_CONFIG_H
