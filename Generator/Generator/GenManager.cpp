#include "RandomDistribution.h"
#include "Boxmuller.h"

GenManager::GenManager(int method, int dataSize, int dimensions, List *l)
{
    this->method = method;    
    this->dimensions = dimensions;
    this->dataSize = pow(dataSize, this->dimensions);
    vectorList = l;
}

//select generation method
void GenManager::genMain()
{
    switch(method)
    {
        case 1:
            randomDistribution();
        break;

        case 2:
            boxMuller();
        break;

        case 3:
            fishMan();
        break;

        default:
        break;
    }
}

//Select dimensional method
void GenManager::randomDistribution()
{
    RD = new RandomDistribution(this->dataSize);

    //Check dimensions
    switch(dimensions)
    {
        case 1:
            vectorList->vecList = RD->random1D();
        break;

        case 2:
            vectorList->vecList = RD->random2D();
        break;

        case 3:
            vectorList->vecList = RD->random3D();
        break;

        case 4:
            vectorList->quaternionList = RD->random4D();
        break;

        default:
        break;
    }
}

//check dimensions chosen for BoxMuller
void GenManager::boxMuller()
{
    BM = new BoxMuller(dataSize);

    switch(dimensions)
    {
        case 1:
            std::cout << "Method only works in 2 or 4 dimensions" << std::endl;
        break;

        case 2:
           vectorList->vecList = BM->box2D();
        break;

        case 3:
            std::cout << "Method only works in 2 or 4 dimensions" << std::endl;
        break;

        case 4:
            vectorList->quaternionList = BM->box4D();
        break;

        default:
        break;
    }
}

//Check dimensions for Fishman
void GenManager::fishMan()
{
    FM = new FishMan(this->dataSize);

    switch(dimensions)
    {
        case 1:
            std::cout << "Method only works in 2 or more dimensions" << std::endl;
        break;

        case 2:
            vectorList->vecList = FM->fishMan2D();
        break;

        case 3:
            vectorList->vecList = FM->fishMan3D();
        break;

        case 4:
            vectorList->quaternionList = FM->fishMan4D();
        break;

        default:
        break;
    }
}

