#include "Fileio.h"

FileIO::FileIO(List *l, int m, int d)
{
    vecList = l;
    this->method = m;
    this->dimensions = d;
    fileName = "";
}

//Generate file name based on parameters
void FileIO::setFileName()
{
    switch(this->method)
    {
        case 1:
            switch(this->dimensions)
            {
                case 1:
                    this->fileName = "random1D.txt";
                break;

                case 2:
                    this->fileName = "random2D.txt";
                break;

                case 3:
                    this->fileName = "random3D.txt";
                break;

                case 4:
                    this->fileName = "random4D.txt";
                break;

                default:
                break;
            }
        break;

        case 2:
            switch(this->dimensions)
            {

                case 2:
                       this->fileName = "boxMuller2D.txt";
                break;

                case 4:
                    this->fileName = "boxMuller4D.txt";
                break;

                default:
                    std::cout << "Invalid selection" << std::endl;
                break;
            }
        break;

        case 3:
            switch(this->dimensions)
            {
                case 2:
                       this->fileName = "fishMan2D.txt";
                break;

                case 3:
                    this->fileName = "fishMan3D.txt";
                break;

                case 4:
                    this->fileName = "fishMan4D.txt";
                break;

                default:
                std::cout << "Invalid selection" << std::endl;
                break;
            }
        break;

        default:
        break;
    }
}

//Print list to file
void FileIO::printToFile()
{
    std::ofstream vectorFile;

    vectorFile.open(this->fileName, std::ios::out);

    if(dimensions == 1)
    {
        for(int i = 0; i < vecList->vecList.size(); i++)
        {
            vectorFile << vecList->vecList[i].getX() << std::endl;
        }
    }
    else if(dimensions == 2)
    {
        for(int i = 0; i < vecList->vecList.size(); i++)
        {            
            vectorFile << vecList->vecList[i].getX() << std::endl;
            vectorFile << vecList->vecList[i].getY() << std::endl;

        }     
    }
    else if(dimensions == 3)
    {
        for(int i = 0; i < vecList->vecList.size(); i++)
        {
            vectorFile << vecList->vecList[i].getX() << std::endl;
            vectorFile << vecList->vecList[i].getY() << std::endl;
            vectorFile << vecList->vecList[i].getZ() << std::endl;
        }
    }
    else if(dimensions == 4)
    {
        for(int i = 0; i < vecList->quaternionList.size(); i++)
        {
            vectorFile << vecList->quaternionList[i].getS() << std::endl;
            vectorFile << vecList->quaternionList[i].getI() << std::endl;
            vectorFile << vecList->quaternionList[i].getJ() << std::endl;
            vectorFile << vecList->quaternionList[i].getK() << std::endl;
        }
    }
}



