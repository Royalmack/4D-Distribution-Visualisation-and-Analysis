#ifndef VECTOR3F_H
#define VECTOR3F_H
#include "stdfx.h"

class Vector3f
{

private:

    double x;
    double y;
    double z;

public:
    Vector3f();

    void setX(double);
    void setY(double);
    void setZ(double);
    void normaliseVector();

    double getX();
    double getY();
    double getZ();
};

#endif // VECTOR3F_H
