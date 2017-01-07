#ifndef LIST_H
#define LIST_H
#include "Vector3f.h"
#include "Quaternion.h"


class List
{
private:



public:

    //Create default constructor that defines vecList size by passed parameter
    List(int n) : vecList(n)
    {
    }

    std::vector<Quaternion> quaternionList;
    std::vector<Vector3f> vecList;
    std::vector<Vector3f> returnList();
};

#endif // LIST_H
