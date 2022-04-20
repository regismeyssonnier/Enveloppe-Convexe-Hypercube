#include "dialog_choix_fichier.h"


Dialog_Choix_Fichier::Dialog_Choix_Fichier()
{

    this->setupUi(this);
    this->th_creer_conf = 0;

}



QProgressBar* Dialog_Choix_Fichier::Get_Progress_Bar()
{
    return this->progressBar;
}

void Dialog_Choix_Fichier::on_Creer_config_bout_clicked()
{
    this->Creer_config_bout->setEnabled(false);
    QString dir = QFileDialog::getExistingDirectory(this, tr("Choisir répertoire de sauvegarde"),
                                                     "./",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);

    if(dir == "")
    {
        this->Creer_config_bout->setEnabled(true);
        return;
    }
    this->th_creer_conf = new Thread_Creer_Config(this, dir);
    this->th_creer_conf->start();

}

void Dialog_Choix_Fichier::on_ChoixbuttonBox_rejected()
{
    if(this->th_creer_conf != 0)
    {
        if(this->th_creer_conf->isRunning() == true)
            this->th_creer_conf->exit(0);

    }

}
