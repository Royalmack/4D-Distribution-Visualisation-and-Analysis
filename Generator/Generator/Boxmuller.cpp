#include "Boxmuller.h"
#include <math.h>

//2D distribution
std::vector<Vector3f> BoxMuller::box2D()
{
    Vector3f temp;
    double val = 0;
    double z0, z1;

    //Seed random engine
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    //create a uniform distribution
    std::vector<double> uniformList;
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for(int i = 0; i < boxList.size() * 2; i++)
    {
        val = distribution(generator);
        uniformList.push_back(val);
    }

    //Complete calculation to create independent pairs
    for(int i = 0; i < boxList.size(); i++)
    {
        z0 = sqrt(-2.0*log(uniformList[i*2])) * cos((2*M_PI) * uniformList[(i*2)+1]);
        z1 = sqrt(-2.0 * log(uniformList[i*2])) * sin((2 * M_PI) * uniformList[(i*2)+1]);

        temp.setX(z0);
        temp.setY(z1);

        boxList[i] = temp;
    }
\   //Normalise List
    for(int i = 0; i < boxList.size(); i++)
    {
        boxList[i].normaliseVector();
    }

    return boxList;
}

//4D distribution
std::vector<Quaternion> BoxMuller::box4D()
{
    Quaternion qTemp;
    double val = 0;
    double z0, z1, z2, z3;

    //Seed random engine
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    //create a uniform distribution
    std::vector<double> uniformList;
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for(int i = 0; i < boxList.size() * 4; i++)
    {
        val = distribution(generator);
        uniformList.push_back(val);
    }

    //Complete calculation to create independent pairs
    for(int i = 0; i < boxList.size(); i++)
    {
        z0 = sqrt(-2.0 * log(uniformList[i*4])) * cos((2 * M_PI) * uniformList[(i*4)+1]);
        z1 = sqrt(-2.0 * log(uniformList[i*4])) * sin((2 * M_PI) * uniformList[(i*4)+1]);

        z2 = sqrt(-2.0 * log(uniformList[(i*4) + 2])) * cos((2 * M_PI) * uniformList[(i*4)+3]);
        z3 = sqrt(-2.0 * log(uniformList[(i*4) + 2])) * sin((2 * M_PI) * uniformList[(i*4)+3]);


        qTemp.setS(z0);
        qTemp.setI(z1);
        qTemp.setJ(z2);
        qTemp.setK(z3);


        qList.push_back(qTemp);
    }

    //Normalise quaternion list of pairs.
    for(int i = 0; i < qList.size(); i++)
    {
        qList[i].normaliseQuaternion();
    }

    return qList;
}
