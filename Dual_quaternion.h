#ifndef DUAL_QUATERNION_H
#define DUAL_QUATERNION_H

#include "Vec_4D.h"
#include <math.h>

class dual_quaternion
{
    //Constructeur
public:
    dual_quaternion(Vec_4D *v);

    //Variable privé
private:
    Vec_4D *d_quat;

    //Methode public
public:
    Vec_4D* Get_Vec4D();
    static void Mat_Rotation_DQuat(double theta, Vec_4D *a, double M[16]);
    static void Mult_MatRot_Vec_4D(double M[16], Vec_4D *v, Vec_4D *vs);



};

#endif // DUAL_QUATERNION_H
