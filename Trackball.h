 #ifndef TRACKBALL_H
 #define TRACKBALL_H

#include <QQuaternion>
#include <QVector3D>
#include <cmath>
#include <iostream>

 class TrackBall
 {

 public:
    TrackBall(int w, int h);

    //Variable priv�
 private:
    // Position souris
    int Tx;
    int Ty;
    // Largeur et hauteur fenetre
    int Tw;
    int Th;
    //Quaternion trackball
    QQuaternion *Tquat;
    //Matrice de rotation
    double Trot[16];

   //Variable public
 public:
    //Start Trackball
    bool start_track;


    //Evenement public
 public:
    void TrackBall_Click(int x, int y);
    void TrackBall_Move(int x, int y);
    void TrackBall_Release(int x, int y);


    //M�thode priv�
 private:
    void TrackBall_Update(int x, int y);
    QVector3D* TrackBall_CoordZ(int x, int y);
    void TrackBall_MatrixRotation();

    //M�thode public - Retourne Matrice rotation
 public:
    double* TrackBall_GetMRot();

    //Destructeur
 public:
    ~TrackBall();


 };



#endif // TRACKBALL_H
