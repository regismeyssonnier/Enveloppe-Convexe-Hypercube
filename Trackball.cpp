#include "Trackball.h"

TrackBall::TrackBall(int w, int h)
{
    this->Tw = w;
    this->Th = h;
    this->Tx = 0;
    this->Ty = 0;

    this->Tquat = new QQuaternion();
    this->start_track = false;



}

void TrackBall::TrackBall_MatrixRotation()
{

    double xx      = Tquat->x() * Tquat->x();
    double xy      = Tquat->x() * Tquat->y();
    double xz      = Tquat->x() * Tquat->z();
    double xw      = Tquat->x() * Tquat->scalar();

    double yy      = Tquat->y() * Tquat->y();
    double yz      = Tquat->y() * Tquat->z();
    double yw      = Tquat->y() * Tquat->scalar();

    double zz      = Tquat->z() * Tquat->z();
    double zw      = Tquat->z() * Tquat->scalar();

    Trot[0]  = 1.0 - 2.0 * ( yy + zz );
    Trot[1]  =       2.0 * ( xy - zw );
    Trot[2]  =       2.0 * ( xz + yw );

    Trot[4]  =       2.0 * ( xy + zw );
    Trot[5]  = 1.0 - 2.0 * ( xx + zz );
    Trot[6]  =       2.0 * ( yz - xw );

    Trot[8]  =       2.0 * ( xz - yw );
    Trot[9]  =       2.0 * ( yz + xw );
    Trot[10] = 1.0 - 2.0 * ( xx + yy );

    Trot[3]  = Trot[7] = Trot[11] = Trot[12] = Trot[13] = Trot[14] = 0.0;
    Trot[15] = 1.0;


}

QVector3D* TrackBall::TrackBall_CoordZ(int x, int y)
{
    float vx = (float)(2.0f * x - this->Tw) / (float)this->Tw;
    float vy = (float)(this->Th - 2.0f * y) / (float)this->Th;

    QVector3D *qv = new QVector3D(vx,
                                 vy,
                                 1.0 - (vx*vx) - (vy*vy)
                                 );

    if(qv->z() > 0.0f)
    {
        qv->setZ((float)sqrt(qv->z()));
    }
    else
    {
        qv->setZ(0);
    }

    qv->normalize();

    return qv;



}

void TrackBall::TrackBall_Update(int x, int y)
{
    QVector3D *av, *nv;
    QVector3D axe;
    QQuaternion *quat, *qr;
    double cosx, sinx;

    av = this->TrackBall_CoordZ(this->Tx, this->Ty);
    nv = this->TrackBall_CoordZ(x, y);

    axe = QVector3D::crossProduct(*nv, *av);
    axe.normalize();

    cosx = QVector3D::dotProduct(*av, *nv);
    if(cosx < -1.0)cosx = -1.0;
    else if(cosx > 1.0)cosx = 1.0;
    sinx = sqrt(1.0 - cosx*cosx);

    quat = new QQuaternion(cosx, sinx * axe.x(), sinx * axe.y(), sinx * axe.z());
    quat->normalize();

    qr = new QQuaternion();
    *qr = (*Tquat) * (*quat);

    this->Tquat = qr;

    this->TrackBall_MatrixRotation();

    this->Tx = x;
    this->Ty = y;

    delete av;
    delete nv;
    delete quat;




}



void TrackBall::TrackBall_Click(int x, int y)
{
    this->Tx = x;
    this->Ty = y;
    this->start_track = true;

    this->TrackBall_Update(x, y);


}


void TrackBall::TrackBall_Move(int x, int y)
{
    this->TrackBall_Update(x, y);


}


void TrackBall::TrackBall_Release(int x, int y)
{
    this->TrackBall_Update(x, y);

}


double* TrackBall::TrackBall_GetMRot()
{
    return &Trot[0];

}


TrackBall::~TrackBall()
{
    delete Tquat;

}

