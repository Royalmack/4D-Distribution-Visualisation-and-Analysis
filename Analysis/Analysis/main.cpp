#include <iostream>
#include <vector>
#include <boost/program_options.hpp>
//#include "Analysis.h"
//#include "List.h"
//#include "FileIO.h"

#include "AnalysisMain.h"

namespace
{
    const size_t ERROR_IN_COMMAND_LINE = 1;
    const size_t SUCCESS = 0;
    const size_t ERROR_UNHANDLED_EXCEPTION = 2;
}

int main(int argc, char ** argv)
{
    int method = 0;
    int dimensions = 0;

    try
    {
      namespace bpo = boost::program_options;
      bpo::options_description desc("Options");
      desc.add_options()
        ("help", "Print help messages")
        ("method", bpo::value<int>(&method)->required(), "Chosen Distribution Method [1-3]")
        ("dimensions", bpo::value<int>(&dimensions)->required(), "Number of Dimensions [1-4]");

      bpo::variables_map lc;
      try
      {
        bpo::store(bpo::parse_command_line(argc, argv, desc),
                  lc);

        if ( lc.count("help")  )
        {
          std::cout << "Configuration Settings:" << std::endl
                    << desc << std::endl;
          return SUCCESS;
        }

        bpo::notify(lc); // throws on error, so do after help in case

      }
      catch(bpo::error& e)
      {
        std::cerr << "Error: " << e.what() << std::endl << std::endl;
        std::cerr << desc << std::endl;
        return ERROR_IN_COMMAND_LINE;
      }

    }
    catch(std::exception& e)
    {
      std::cerr << "Unhandled Exception: "
                << e.what() << ", application will now exit" << std::endl;
      return ERROR_UNHANDLED_EXCEPTION;

    }

    //check method selection
    if(method < 0 || method > 3)
    {
        std::cout << "Error in method selection. Valid range 1-3" << std::endl;
        return -1;
    }

    //check dimensions
    if(dimensions < 1 || dimensions > 4)
    {
        std::cout << "Error is selection.  Valid range 1-3" << std::endl;
        return -1;
    }

    //Create analysis main object
    AnalysisMain *am = new AnalysisMain(method, dimensions);

    am->startUp();
    am->startAnalysis();

    delete am;

    return 0;
}
