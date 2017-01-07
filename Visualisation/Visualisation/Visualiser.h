#ifndef VISUALISER_H
#define VISUALISER_H
#include "List.h"


class Visualiser
{
    int argc;
    char** argv;



public:
    List *list;

    Visualiser(int, char**, List*);

    void startUp();
    void init();
};

#endif // VISUALISER_H
