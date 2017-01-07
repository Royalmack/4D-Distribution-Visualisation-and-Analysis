#ifndef PACKING_H
#define PACKING_H
#include "Analysis.h"
#include <iostream>

//Has access to all of Analysis data
class packing : public Analysis
{

private:

public:    

    packing(List *l, int d) : Analysis(l, d)
    {
    }

    double* return1DList();
    double* return2DList();
    double* return3DList();
    double* return4DList();
};

#endif // PACKING_H
