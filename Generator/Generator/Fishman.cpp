#include "Fishman.h"

//2D Distribution
std::vector<Vector3f> FishMan::fishMan2D()
{
    //seed engine and create normal distribution
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> d(0.0, 1.0);

    double X[2];
    Vector3f tempVec;

    int j;

    //create X for number of dimensions dimensions.
    for(j = 0; j < fishManList.size(); j++)
    {
        int i = 0;
        float w = 0;

        while(i <= 1)
        {
            X[i] = d(generator);

            w = w + pow(X[i], 2);

            i++;
        }

        w = sqrt(w);    //Final w value
        i = 1;

        tempVec.setX((1*X[0])/w);   //sets for vectors and quaternions
        tempVec.setY((1*X[1])/w);

        fishManList[j] = tempVec;
    }

    //Normalise list
    for(int i = 0; i < fishManList.size(); i++)
    {
        fishManList[i].normaliseVector();
    }

    return fishManList;
}

std::vector<Vector3f> FishMan::fishMan3D()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> d(0.0, 1.0);

    double X[3];
    Vector3f tempVec;

    int j;

    for(j = 0; j < fishManList.size(); j++)
    {
        int i = 0;
        float w = 0;

        while(i <= 2)
        {
            X[i] = d(generator);

            w = w + pow(X[i], 2);

            i++;
        }

        w = sqrt(w);
        i = 1;

        tempVec.setX((1*X[0])/w);
        tempVec.setY((1*X[1])/w);
        tempVec.setZ((1*X[2])/w);

        fishManList[j] = tempVec;
    }

    for(int i = 0; i < fishManList.size(); i++)
    {
        fishManList[i].normaliseVector();
    }

    return fishManList;
}

std::vector<Quaternion> FishMan::fishMan4D()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> d(0.0, 1.0);

    double X[4];
    Quaternion qTemp;

    int j;

    for(j = 0; j < fishManList.size(); j++)
    {
        int i = 0;
        float w = 0;

        while(i <= 3)
        {
            X[i] = d(generator);

            w = w + pow(X[i], 2);

            i++;
        }

        w = sqrt(w);
        i = 1;

        qTemp.setS((1*X[0])/w);
        qTemp.setI((1*X[1])/w);
        qTemp.setJ((1*X[2])/w);
        qTemp.setK((1*X[3])/w);
        qList.push_back(qTemp);
    }

    for(int i = 0; i < qList.size(); i++)
    {
        qList[i].normaliseQuaternion();
    }

    return qList;
}
