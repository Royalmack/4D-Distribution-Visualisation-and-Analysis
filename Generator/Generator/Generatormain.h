#ifndef GENERATORMAIN_H
#define GENERATORMAIN_H
#include "List.h"
#include "GenManager.h"
#include "Fileio.h"


class GeneratorMain
{
private:
    int method;
    int dimensions;
    int size;

public:
    GeneratorMain(int, int, int);

    //Objects
    FileIO* fileManager;
    List *managedList;
    GenManager *generator;

    void startUp();
    void startDistribution();
    void setFileName();
    void PrintFile();

    void deleteObjects();

};

#endif // GENERATORMAIN_H
