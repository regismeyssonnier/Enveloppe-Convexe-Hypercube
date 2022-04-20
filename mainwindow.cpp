#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   /*

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(gl_widget);
    ui->centralWidget->setLayout(mainLayout);
*/

    this->gl_widget = new GLWidget(parent);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(gl_widget);
    ui->centralwidget->setLayout(mainLayout);


}


MainWindow::~MainWindow()
{

}

void MainWindow::Check_Sommet(QAction *qact)
{
    qact->setChecked(false);
}

void MainWindow::on_actionNouveau_triggered()
{
    this->gl_widget->Nouveau_Hyp();
    this->Check_Sommet(this->ui->actionSommet_1);
    this->Check_Sommet(this->ui->actionSommet_2);
    this->Check_Sommet(this->ui->actionSommet_3);
    this->Check_Sommet(this->ui->actionSommet_4);
    this->Check_Sommet(this->ui->actionSommet_5);
    this->Check_Sommet(this->ui->actionSommet_6);
    this->Check_Sommet(this->ui->actionSommet_7);
    this->Check_Sommet(this->ui->actionSommet_8);
    this->Check_Sommet(this->ui->actionSommet_9);
    this->Check_Sommet(this->ui->actionSommet_10);
    this->Check_Sommet(this->ui->actionSommet_11);
    this->Check_Sommet(this->ui->actionSommet_12);
    this->Check_Sommet(this->ui->actionSommet_13);
    this->Check_Sommet(this->ui->actionSommet_14);
    this->Check_Sommet(this->ui->actionSommet_15);
    this->Check_Sommet(this->ui->actionSommet_16);


}
