#include "Dual_quaternion.h"


dual_quaternion::dual_quaternion(Vec_4D *v)
{
    this->d_quat = v;
}

Vec_4D* dual_quaternion::Get_Vec4D()
{
    return d_quat;
}

void dual_quaternion::Mat_Rotation_DQuat(double theta, Vec_4D *a, double M[16])
{

    double angle;
    Vec_4D r(0,0,0,0);
    double rw, rx, ry, rz, rw2, rx2, ry2, rz2;

    angle = cos(theta/2.0) + sin(theta/2.0);
    rw = r.t = 1.0;
    rx = r.x = a->x * angle;
    ry = r.y = a->y * angle;
    rz = r.z = a->z * angle;

    rw2 = rw*rw;
    rx2 = rx*rx;
    ry2 = ry*ry;
    rz2 = rz*rz;

    M[0] = rw2 + rx2 - ry2 - rz2;
    M[1] = (2.0 * rx * ry) + (2.0 * rw * rz);
    M[2] = (2.0 * rx * rz) - (2.0 * rw * ry);
    M[3] = 0.0;
    M[4] = (2.0 * rx * ry) - (2.0 * rw * rz);
    M[5] = rw2 - rx2 + ry2 - rz2;
    M[6] = (2.0 * ry * rz) + (2.0 * rw + rx);
    M[7] = 0.0;
    M[8] = (2.0 * rx * rz) + (2.0 * rw * ry);
    M[9] = (2.0 * ry * rz) + (2.0 * rw * rx);
    M[10]= rw2 - rx2 - ry2 + rz2;
    M[11]= 0.0;
    M[12]= 0.0;
    M[13]= 0.0;
    M[14]= 0.0;
    M[15]= 1.0;




}


void dual_quaternion::Mult_MatRot_Vec_4D(double M[], Vec_4D *v, Vec_4D *vs)
{

    vs->x = v->x * M[0] + v->y * M[1] + v->z * M[2] + v->t * M[3];
    vs->y = v->x * M[4] + v->y * M[5] + v->z * M[6] + v->t * M[7];
    vs->z = v->x * M[8] + v->y * M[9] + v->z * M[10] + v->t * M[11];
    vs->t = v->x * M[12] + v->y * M[13] + v->z * M[14] + v->t * M[15];



}












