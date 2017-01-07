#include "Generatormain.h"

GeneratorMain::GeneratorMain(int m, int d, int s)
{
    this->method = m;
    this->dimensions = d;
    this->size = s;
}

void GeneratorMain::startUp()
{
    //Create objects
    managedList = new List(pow(size, dimensions));
    fileManager = new FileIO(managedList, method, dimensions);
    generator = new GenManager(method, size, dimensions, managedList);

    startDistribution();
}

void GeneratorMain::startDistribution()
{
    //Begin the generation methods inside of generator
    generator->genMain();

    //setFileName of newly created Vectors
    setFileName();

    //Print list to file
    PrintFile();
}

void GeneratorMain::setFileName()
{
    fileManager->setFileName();
}

void GeneratorMain::PrintFile()
{
    fileManager->printToFile();
}

void GeneratorMain::deleteObjects()
{
    delete fileManager;
    delete generator;
    delete managedList;
}
