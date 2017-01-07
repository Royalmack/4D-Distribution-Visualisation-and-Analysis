#ifndef BOXMULLER_H
#define BOXMULLER_H
#include <Vector3f.h>
#include "Quaternion.h"


class BoxMuller
{

    //Lists for data
private:
    std::vector<Vector3f> boxList;
    std::vector<Quaternion> qList;

public:
    BoxMuller(int n) : boxList(n)
    {
    }


    //Methods of distribution
    std::vector<Vector3f> box2D();    
    std::vector<Quaternion> box4D();

};

#endif // BOXMULLER_H
