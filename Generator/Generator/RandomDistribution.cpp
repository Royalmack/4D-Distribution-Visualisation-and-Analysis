#include "RandomDistribution.h"


std::vector<Vector3f> RandomDistribution::random1D()
{
    Vector3f tempVec;

    double randomValue;

    //create random values and store.
    for(int i = 0; i < randomList.size(); i++)
    {
        randomValue = (randMax - randMin) * ((((double)rand()) / (double) RAND_MAX)) + randMin;

        tempVec.setX(randomValue);

        randomList[i] = tempVec;
    }

    //Normalise list
    for(int i = 0; i < randomList.size(); i++)
    {
        randomList[i].normaliseVector();
    }

    return randomList;
}

std::vector<Vector3f> RandomDistribution::random2D()
{
    Vector3f tempVec;
    double randomValue;

    for(int i = 0; i < randomList.size(); i++)
    {
        randomValue = (randMax - randMin) * ((((double)rand()) / (double) RAND_MAX)) + randMin;
        tempVec.setX(randomValue);

        randomValue = (randMax - randMin) * ((((double)rand()) / (double) RAND_MAX)) + randMin;
        tempVec.setY(randomValue);

        randomList[i] = tempVec;
    }

    for(int i = 0; i < randomList.size(); i++)
    {
        randomList[i].normaliseVector();
    }


    return randomList;
}

std::vector<Vector3f> RandomDistribution::random3D()
{
    Vector3f tempVec;
    double randomValue;

    for(int i = 0; i < randomList.size(); i++)
    {
        randomValue = (randMax - randMin) * ((((double)rand()) / (double) RAND_MAX)) + randMin;
        tempVec.setX(randomValue);

        randomValue = (randMax - randMin) * ((((double)rand()) / (double) RAND_MAX)) + randMin;
        tempVec.setY(randomValue);

        randomValue = (randMax - randMin) * ((((double)rand()) / (double) RAND_MAX)) + randMin;
        tempVec.setZ(randomValue);

        randomList[i]= tempVec;
    }

    for(int i = 0; i < randomList.size(); i++)
    {
        randomList[i].normaliseVector();
    }

    return randomList;
}

std::vector<Quaternion> RandomDistribution::random4D()
{
    Quaternion qTemp;
    double randomValue;

    for(int i = 0; i < randomList.size(); i++)
    {

        randomValue = (randMax - randMin) * ((((double)rand()) / (double) RAND_MAX)) + randMin;
        qTemp.setS(randomValue);

        randomValue = (randMax - randMin) * ((((double)rand()) / (double) RAND_MAX)) + randMin;
        qTemp.setI(randomValue);

        randomValue = (randMax - randMin) * ((((double)rand()) / (double) RAND_MAX)) + randMin;
        qTemp.setJ(randomValue);

        randomValue = (randMax - randMin) * ((((double)rand()) / (double) RAND_MAX)) + randMin;
        qTemp.setK(randomValue);

        qList.push_back(qTemp);
    }

    for(int i = 0; i < qList.size(); i++)
    {
        qList[i].normaliseQuaternion();
    }

    return qList;
}
