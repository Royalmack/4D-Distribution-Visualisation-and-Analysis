#ifndef LIST_H
#define LIST_H
#include "Vector3f.h"
#include "Quaternion.h"
#include <vector>


class List
{
    private:

    public:
        List();

        std::vector<Vector3f> vecList;
        std::vector<Quaternion> qList;

};

#endif // LIST_H
