#ifndef FILEIO_H
#define FILEIO_H
#include "List.h"
#include <cstring>
#include <fstream>
#include <string>

//Default file location for generated points
#define fileDefault "/home/smacken/Documents/Generator/build-Generator-Desktop-Debug/"

class FileIO
{
    private:
        std::string fileName;
        List *listLink;
        int method;
        int dimensions;

    public:
        FileIO(List*, int m, int d);
        void setFileName();
        void readFile();
};

#endif // FILEIO_H
