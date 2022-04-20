#ifndef VEC_4D_H
#define VEC_4D_H



class Vec_4D
{
    //Constructeur
    public:
        Vec_4D(){};
        Vec_4D(double x, double y, double z, double t);

    //methode public
    public:
        void Init_Vec_4D(double x, double y, double z, double t);

    //variable public
    public:
        double x;
        double y;
        double z;
        double t;


};

#endif // VEC_4D_H
