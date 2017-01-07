#include "Analysis.h"
#include "packing.h"

Analysis::Analysis(List *l, int d)
{
    this->dataList = l;
    this->dimensions = d;
}

//Main section of analysis
void Analysis::appMain()
{
    pack = new packing(dataList, dimensions);
    checkDimensions();
}

//Checks dimensions selected
void Analysis::checkDimensions()
{
    switch(dimensions)
    {
        case 1:
            pack1D();
            analysis1D();
        break;

        case 2:
            pack2D();
            analysis2D();
        break;

        case 3:
            pack3D();
            analysis3D();
        break;

        case 4:
            pack4D();
            analysis4D();
        break;
    }
}

//Packs lists into arrays depending on dimensions
void Analysis::pack1D()
{
    oneDList = pack->return1DList();
}

void Analysis::pack2D()
{
    twoDList = pack->return2DList();
}


void Analysis::pack3D()
{
   threeDList = pack->return3DList();
}

void Analysis::pack4D()
{
    fourDList = pack->return4DList();
}


//Analysis of arrays by dimensions.
//Returns mean, variance, skew and kurtosis.
void Analysis::analysis1D()
{
    const size_t stride = 1;
    const size_t size = dataList->vecList.size();
    const double

    mean = gsl_stats_mean(oneDList, stride, size);
    variance = gsl_stats_variance(oneDList, stride, size);
    skew = gsl_stats_skew(oneDList, stride, size);
    kurtosis = gsl_stats_kurtosis(oneDList, stride, size);

    std::cout << "Mean of Values: " << mean << std::endl;
    std::cout << "Variance of Values: " << variance << std::endl;
    std::cout << "Skew of Values: " << skew << std::endl;
    std::cout << "Kurtosis of Values: " << kurtosis << std::endl << std::endl;

}

void Analysis::analysis2D()
{
    const size_t stride = 2;
    const size_t size = dataList->vecList.size() * 2;

    mean = gsl_stats_mean(twoDList, stride, size);
    variance = gsl_stats_variance(twoDList, stride, size);
    skew = gsl_stats_skew(twoDList, stride, size);
    kurtosis = gsl_stats_kurtosis(twoDList, stride, size);

    std::cout << "Mean of Values: " << mean << std::endl;
    std::cout << "Variance of Values: " << variance << std::endl;
    std::cout << "Skew of Values: " << skew << std::endl;
    std::cout << "Kurtosis of Values: " << kurtosis << std::endl << std::endl;
}

void Analysis::analysis3D()
{
    const size_t stride = 3;
    const size_t size = dataList->vecList.size() * 3;

    mean = gsl_stats_mean(threeDList, stride, size);
    variance = gsl_stats_variance(threeDList, stride, size);
    skew = gsl_stats_skew(threeDList, stride, size);
    kurtosis = gsl_stats_kurtosis(threeDList, stride, size);

    std::cout << "Mean of Values: " << mean << std::endl;
    std::cout << "Variance of Values: " << variance << std::endl;
    std::cout << "Skew of Values: " << skew << std::endl;
    std::cout << "Kurtosis of Values: " << kurtosis << std::endl << std::endl;
}

void Analysis::analysis4D()
{
    const size_t stride = 4;
    const size_t size = dataList->qList.size() * 4;

    mean = gsl_stats_mean(fourDList, stride, size);
    variance = gsl_stats_variance(fourDList, stride, size);
    skew = gsl_stats_skew(fourDList, stride, size);
    kurtosis = gsl_stats_kurtosis(fourDList, stride, size);

    std::cout << "Mean of Values: " << mean << std::endl;
    std::cout << "Variance of Values: " << variance << std::endl;
    std::cout << "Skew of Values: " << skew << std::endl;
    std::cout << "Kurtosis of Values: " << kurtosis << std::endl << std::endl;
}
