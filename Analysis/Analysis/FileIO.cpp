#include "FileIO.h"

FileIO::FileIO(List *l, int m, int d)
{
    listLink = l;
    this->method = m;
    this->dimensions = d;
    fileName = fileDefault;
}

//Setting file name based on parameters
void FileIO::setFileName()
{
    std::string endText;

    switch(method)
    {
        case 1:
            switch(dimensions)
            {
                case 1:
                    endText = "random1D.txt";
                break;

                case 2:
                    endText = "random2D.txt";
                break;

                case 3:
                    endText = "random3D.txt";
                break;

                case 4:
                    endText = "random4D.txt";
                break;
            }
        break;

        case 2:
            switch(dimensions)
            {
                case 1:
                    endText = "boxMuller1D.txt";
                break;

                case 2:
                    endText = "boxMuller2D.txt";
                break;

                case 3:
                    endText = "boxMuller3D.txt";
                break;

                case 4:
                    endText = "boxMuller4D.txt";
                break;
            }
        break;

        case 3:
            switch(dimensions)
            {
                case 1:
                    endText = "fishMan1D.txt";
                break;

                case 2:
                    endText = "fishMan2D.txt";
                break;

                case 3:
                    endText = "fishMan3D.txt";
                break;

                case 4:
                    endText = "fishMan4D.txt";
                break;
            }
        break;
    }

    fileName = fileName + endText;
}

//Reading in values from file and storing them to vectors or quaternions.
void FileIO::readFile()
{
    std::ifstream vectorFile;

    const char *file = fileName.c_str();
    vectorFile.open(file, std::ios::in);

    Vector3f tmp;
    Quaternion qTemp;
    double tmpX;
    double tmpY;
    double tmpZ;
    double tmpW;

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

        case 4:
            while(!vectorFile.eof())
            {
                vectorFile >> tmpW;
                vectorFile >> tmpX;
                vectorFile >> tmpY;
                vectorFile >> tmpZ;

                qTemp.setS(tmpW);
                qTemp.setI(tmpX);
                qTemp.setJ(tmpY);
                qTemp.setK(tmpZ);

                listLink->qList.push_back(qTemp);
            }
        break;
    }
}
