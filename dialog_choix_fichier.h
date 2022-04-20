#ifndef DIALOG_CHOIX_FICHIER_H
#define DIALOG_CHOIX_FICHIER_H

#include <QWidget>
#include <QDialog>
#include <ui_dialog_choix_fichier.h>
#include "Thread_Creer_Config.h"
#include <QProgressBar>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
class Thread_Creer_Config;
QT_END_NAMESPACE

namespace Ui {

}

class Dialog_Choix_Fichier : public QDialog, public Ui::Dialog_Choix_Fichier
{
     Q_OBJECT

    //Constructeur public
public:
    Dialog_Choix_Fichier();

    //Variable prive
private:
    Thread_Creer_Config *th_creer_conf;

public:
    QProgressBar* Get_Progress_Bar();


private slots:
    void on_ChoixbuttonBox_rejected();
    void on_Creer_config_bout_clicked();
};

#endif // DIALOG_CHOIX_FICHIER_H
