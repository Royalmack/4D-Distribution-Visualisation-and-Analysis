#ifndef RANDOMDISTRIBUTION_H
#define RANDOMDISTRIBUTION_H
#include "Quaternion.h"

#include "GenManager.h"

class RandomDistribution
{
    //Data lists
    private:
        std::vector<Vector3f> randomList;
        std::vector<Quaternion> qList;

    public:
        RandomDistribution(int n) : randomList(n)
        {
        }

        //Methods of distribution
        std::vector<Vector3f> random1D();
        std::vector<Vector3f> random2D();
        std::vector<Vector3f> random3D();
        std::vector<Quaternion> random4D();
};

#endif // RANDOMDISTRIBUTION_H
