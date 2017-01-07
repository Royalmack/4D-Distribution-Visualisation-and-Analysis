#ifndef VISUALISATIONMAIN_H
#define VISUALISATIONMAIN_H
#include "List.h"
#include "FileIO.h"
#include "Visualiser.h"
#include "global.h"

class VisualisationMain
{
private:

    int argc;
    char **argv;
    int method;
    int dimensions;

    List *vectorData;
    FileIO *fileManager;


public:

    VisualisationMain(int, char**, int, int);

    void main();
};

#endif // VISUALISATIONMAIN_H
