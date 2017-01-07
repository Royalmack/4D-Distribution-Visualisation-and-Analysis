#include "packing.h"

//Returns vector or quaternion lists back as double arrays.
double* packing::return1DList()
{
    double *temp = new double[dataList->vecList.size()];


    for(int i = 0; i < dataList->vecList.size(); i++)
    {
       temp[i] = dataList->vecList[i].getX();
    }

    return temp;
}

double* packing::return2DList()
{
    double *temp = new double[dataList->vecList.size() * 2];

    for(int i = 0; i < dataList->vecList.size(); i++)
    {
        temp[i*2] = dataList->vecList[i].getX();
        temp[(i*2)+1] = dataList->vecList[i].getY();
    }

    return temp;
}

double* packing::return3DList()
{
    double *temp = new double[dataList->vecList.size() * 3];

    for(int i = 0; i < dataList->vecList.size(); i++)
    {
        temp[i*3] = dataList->vecList[i].getX();
        temp[(i*3)+1] = dataList->vecList[i].getY();
        temp[(i*3)+2] = dataList->vecList[i].getZ();

    }

    return temp;
}

double* packing::return4DList()
{
    double *temp = new double[dataList->qList.size() * 4];

    for(int i = 0; i < dataList->qList.size(); i++)
    {
        dataList->qList[i].setS(temp[i*4]);
        dataList->qList[i].setI(temp[(i*4)+1]);
        dataList->qList[i].setJ(temp[(i*4)+2]);
        dataList->qList[i].setK(temp[(i*4)+3]);
    }

    return temp;
}
