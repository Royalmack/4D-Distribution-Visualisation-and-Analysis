#ifndef FISHMAN_H
#define FISHMAN_H
#include "Vector3f.h"
#include "Quaternion.h"

class FishMan
{

    //Data Lists
private:
    std::vector<Vector3f> fishManList;
    std::vector<Quaternion> qList;

public:
    FishMan(int n) : fishManList(n)
    {
       ;
    }

    //Methods of distribution
    std::vector<Vector3f> fishMan2D();
    std::vector<Vector3f> fishMan3D();
    std::vector<Quaternion> fishMan4D();
};

#endif // FISHMAN_H
