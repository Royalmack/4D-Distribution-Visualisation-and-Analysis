#include <Vector3f.h>
#include <iostream>
#include "List.h"
#include "Fileio.h"
#include "Quaternion.h"

//int main()
//{
////    //Unit tests for Vector
////    Vector3f *testVector = new Vector3f();

////    //Expected value of Vector to be 0,0,0
////    //Testing the gets to display expected results
////    std::cout << testVector->getX() << ", ";
////    std::cout << testVector->getY() << ", ";
////    std::cout << testVector->getZ() << std::endl;

////    //Testing sets of Vector
////    testVector->setX(1);
////    testVector->setY(2);
////    testVector->setZ(3);

////    //Display expected results of 1, 2, 3
////    std::cout << testVector->getX() << ", ";
////    std::cout << testVector->getY() << ", ";
////    std::cout << testVector->getZ() << std::endl;

////    //testing set with a negative numbers
////    testVector->setX(-1);
////    testVector->setY(-2);
////    testVector->setZ(-3);

////    //Display expected results of -1, -2, -3
////    std::cout << testVector->getX() << ", ";
////    std::cout << testVector->getY() << ", ";
////    std::cout << testVector->getZ() << std::endl;


//   // //////////////////////////////////////////////////////////////////////////////////////////

//    //Integration Tests

////    int size = 10;
////    int method = 3;
////    int dimensions = 1;
////    List *testList;
////    FileIO *testFile;

////    //List creation with placed checks to limit negative possibilities
////    if(size < 1)
////    {
////        std::cout << "Invalid size" << std::endl;
////    }
////    else
////    {
////        testList= new List(size);
////    }

////    //FileIO Tests to check name generation works
////    if((method > 0 || method < 4) && (dimensions > 0 || dimensions < 4))
////    {
////        testFile = new FileIO(testList, method, dimensions);
////        testFile->setFileName();
////    }

//    // //////////////////////////////////////////////////////////////////////////

//    //Quaternion Unit Tests
//    Quaternion *testQ = new Quaternion();

//    //testing sets
//    testQ->setS(1);
//    testQ->setI(2);
//    testQ->setJ(3);
//    testQ->setK(4);

//    std::cout << testQ->getS() << ", ";
//    std::cout << testQ->getI() << ", ";
//    std::cout << testQ->getJ() << ", ";
//    std::cout << testQ->getK() << std::endl;

//    // //////////////////////////////////////////////////////////////////////////


//   return 0;
//}
