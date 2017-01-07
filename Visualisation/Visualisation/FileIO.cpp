#include "FileIO.h"
#include <iostream>

FileIO::FileIO(List *l, int m, int d)
{
    listLink = l;
    this->method = m;
    this->dimensions = d;
    fileName = fileDefault;
}

//Set file name based on parameters
void FileIO::setFileName()
{
    std::string endText;

    switch(method)
    {
        case 1:
            switch(dimensions)
            {
                case 2:
                    endText = "random2D.txt";
                break;

                case 3:
                    endText = "random3D.txt";
                break;
            }
        break;

        case 2:
            switch(dimensions)
            {
                case 2:
                    endText = "boxMuller2D.txt";
                break;

                case 3:
                    std::cout << " File Does Not Exist" << std::endl;
                break;
            }
        break;

        case 3:
            switch(dimensions)
            {
                case 2:
                    endText = "fishMan2D.txt";
                break;

                case 3:
                    endText = "fishMan3D.txt";
                break;
            }
        break;
    }

    fileName = fileName + endText;
}

//Read in patterns from file to vectors or quaternions.
void FileIO::readFile()
{
    std::ifstream vectorFile;

    const char *file = fileName.c_str();
    vectorFile.open(file, std::ios::in);

    Vector3f tmp;
    double tmpX;
    double tmpY;
    double tmpZ;

    switch(dimensions)
    {
        case 1:
            while(!vectorFile.eof())
            {
                vectorFile >> tmpX;

                tmp.setX(tmpX);

                listLink->vecList.push_back(tmp);
            }
        break;

        case 2:
            while(!vectorFile.eof())
            {
                vectorFile >> tmpX;
                vectorFile >> tmpY;

                tmp.setX(tmpX);
                tmp.setY(tmpY);

                listLink->vecList.push_back(tmp);
            }
        break;

        case 3:
            while(!vectorFile.eof())
            {
                vectorFile >> tmpX;
                vectorFile >> tmpY;
                vectorFile >> tmpZ;

                tmp.setX(tmpX);
                tmp.setY(tmpY);
                tmp.setZ(tmpZ);

                listLink->vecList.push_back(tmp);
            }
        break;
    }

    delete [] file;
}
