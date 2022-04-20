#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "version.h"
#include "gl_widget.h"

QT_BEGIN_NAMESPACE
class MainWindow;
class Version;
QT_END_NAMESPACE

namespace Ui {
    class MainWindow;
    class Version;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Version *version;
    GLWidget *gl_widget;


    //Methode public
public:

    //Methode privé
private:
    void Check_Sommet(QAction *qact);


private slots:
    void on_actionNouveau_triggered();
};


#endif // MAINWINDOW_H
