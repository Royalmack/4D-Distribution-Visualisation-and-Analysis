#include "VisualisationMain.h"


VisualisationMain::VisualisationMain(int gc, char** gv, int method, int dimensions)
{
    this->argc = gc;
    this->argv = gv;
    this->method = method;
    this->dimensions = dimensions;
}

void VisualisationMain::main()
{
    //start the creation of objects and their links to list
    vectorData = new List();

    //Create file object with reference to list
    fileManager = new FileIO(vectorData, method, dimensions);

    //Create visual object used to draw to screen passing in argc, argv and a reference to list
    visual = new Visualiser(argc, argv, vectorData);

    //Set file name and read in vector data
    fileManager->setFileName();
    fileManager->readFile();

    //Visual component start up
    visual->startUp();
}
