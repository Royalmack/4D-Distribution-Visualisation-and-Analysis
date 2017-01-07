#pragma once
#include<stdio.h>
//#include "Vector4f"
//#include "Basis.h"

#define DELTA 0.0001

class Quaternion
{
    private:

        double s, i, j, k;

	public:

		Quaternion(void);
        ~Quaternion(void);

        void setS(double s);
        void setI(double i);
        void setJ(double j);
        void setK(double k);

        double getS();
        double getI();
        double getJ();
        double getK();

        void normaliseQuaternion();
        Quaternion* multiplyQuaternion(Quaternion *q1, Quaternion *q2);

};

