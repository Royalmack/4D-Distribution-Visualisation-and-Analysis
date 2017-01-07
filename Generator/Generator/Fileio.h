#ifndef FILEIO_H
#define FILEIO_H
#include "stdfx.h"
#include "List.h"

class FileIO
{

private:
    char* fileName;   
    int method;
    int dimensions;

public:

    FileIO(List *, int m, int d);
    List *vecList;   

    void setFileName();
    void printToFile();
};

#endif // FILEIO_H
