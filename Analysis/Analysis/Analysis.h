#ifndef ANALYSIS_H
#define ANALYSIS_H
#include "FileIO.h"
#include <gsl/gsl_statistics.h>
class packing;

class Analysis
{
    private:

    int dimensions;
    double mean;
    double variance;
    double skew;
    double kurtosis;

    //Lists for GSL
    const double *oneDList;
    const double *twoDList;
    const double *threeDList;
    const double *fourDList;

    public:      
        Analysis(List*, int);
        List *dataList;
        packing *pack;

        void appMain();
        void checkDimensions();

        //gather values from list into double lists so they can be tested inside GSL
        void pack1D();
        void pack2D();
        void pack3D();
        void pack4D();

        void analysis1D();
        void analysis2D();
        void analysis3D();
        void analysis4D();
};

#endif // APPLICATION_H
