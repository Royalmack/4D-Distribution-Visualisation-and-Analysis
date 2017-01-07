#ifndef ANALYSISMAIN_H
#define ANALYSISMAIN_H

#include "List.h"
#include "FileIO.h"
#include "Analysis.h"


class AnalysisMain
{
    private:
        int method;
        int dimension;

        List *sharedList;
        FileIO *fileManager;
        Analysis *dataAnalysis;

    public:
        AnalysisMain(int, int);

        void startUp();
        void getFileName();
        void readFile();
        void startAnalysis();

        void destroyObjects();
};

#endif // ANALYSISMAIN_H
