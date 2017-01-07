#include "Vector3f.h"

Vector3f::Vector3f()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

void Vector3f::setX(double x)
{
    this->x = x;
}

void Vector3f::setY(double y)
{
    this->y = y;
}

void Vector3f::setZ(double z)
{
    this->z = z;
}

double Vector3f::getX()
{
    return this->x;
}

double Vector3f::getY()
{
    return this->y;
}

double Vector3f::getZ()
{
    return this->z;
}

void Vector3f::normaliseVector()
{
    double length = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);

    this->x = this->x/length;
    this->y = this->y/length;
    this->z = this->z/length;
}

