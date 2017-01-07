#include "Quaternion.h"
#include <cmath>


Quaternion::Quaternion(void)
{
	s = 0;
	i = 0; 
	j = 0;
	k = 0;
}

Quaternion::~Quaternion(void)
{
}

void Quaternion::setS(double s)
{
    this->s = s;
}

void Quaternion::setI(double i)
{
    this->i = i;
}

void Quaternion::setJ(double j)
{
    this->j = j;
}

void Quaternion::setK(double k)
{
   this->k = k ;
}

double Quaternion::getS()
{
    return this->s;
}

double Quaternion::getI()
{
    return this->i;
}


double Quaternion::getJ()
{
    return this->j;
}


double Quaternion::getK()
{
    return this->k;
}



void Quaternion::normaliseQuaternion()
{
    double length = sqrt((this->s * this->s) + (this->i * this->i) + (this->j * this->j) + (this->k * this->k));

    this->s = this->s / length;
    this->i = this->i / length;
    this->j = this->j / length;
    this->k = this->k / length;
}


Quaternion* Quaternion::multiplyQuaternion(Quaternion *q1, Quaternion *q2)
{
    Quaternion *tempQuaternion = new Quaternion();

    tempQuaternion->s = (q2->s * q1->s - q2->i * q1->i - q2->j * q1->j - q2->k * q1->k);

    tempQuaternion->i = (q2->s * q1->i + q2->i * q1->s - q2->j * q1->k + q2->k * q1->j);

    tempQuaternion->j = (q2->s * q1->j + q2->i * q1->k + q2->j * q1->s - q2->k * q1->i);

    tempQuaternion->k = (q2->s * q1->k - q2->i * q1->j + q2->j * q1->i + q2->k * q1->s);

}
