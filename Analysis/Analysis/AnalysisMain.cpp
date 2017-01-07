#include "AnalysisMain.h"

AnalysisMain::AnalysisMain(int m, int d)
{
    this->method = m;
    this->dimension = d;
}

//creation of objects
void AnalysisMain::startUp()
{
    sharedList = new List();
    fileManager = new FileIO(sharedList, method, dimension);
    dataAnalysis = new Analysis(sharedList, dimension);

    getFileName();
}

void AnalysisMain::getFileName()
{
    fileManager->setFileName();

    readFile();
}

void AnalysisMain::readFile()
{
    fileManager->readFile();
}

void AnalysisMain::startAnalysis()
{
    dataAnalysis->appMain();
}

void AnalysisMain::destroyObjects()
{
    delete sharedList;
    delete fileManager;
    delete dataAnalysis;
}
