#ifndef APPLICATION_H
#define APPLICATION_H
#include "stdfx.h"
#include "List.h"
#include "Fishman.h"
class BoxMuller;

class RandomDistribution;

class GenManager
{

private:

    int method;
    int dataSize;
    int dimensions;

public:

    GenManager(int method, int dataSize, int dimenions, List *l);

    //Objects
    List *vectorList;
    RandomDistribution *RD;
    BoxMuller *BM;
    FishMan *FM;

    void genMain();
    void randomDistribution();
    void boxMuller();
    void fishMan();
};

#endif // APPLICATION_H
