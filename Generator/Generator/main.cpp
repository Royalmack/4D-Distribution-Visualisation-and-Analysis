#include "boost/program_options.hpp"
#include <iostream>
#include <string>
#include "Generatormain.h"

namespace
{
  const size_t ERROR_IN_COMMAND_LINE = 1;
  const size_t SUCCESS = 0;
  const size_t ERROR_UNHANDLED_EXCEPTION = 2;

} // namespace

int main(int argc, char** argv)
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    int method = -1;
    int dataSize = -1;
    int dimensions = -1;

  try
  {
    namespace bpo = boost::program_options;
    bpo::options_description desc("Options");
    desc.add_options()
      ("help", "Print help messages")
      ("method", bpo::value<int>(&method)->required(), "Chosen Distribution Method [1-3]")
      ("points",bpo::value<int>(&dataSize)->required(), "Amount of points [1-*]")
      ("dimensions", bpo::value<int>(&dimensions)->required(), "Number of Dimensions [1-4]");

    bpo::variables_map lc;
    try
    {
      bpo::store(bpo::parse_command_line(argc, argv, desc),
                lc); // can throw

      if ( lc.count("help")  )
      {
        std::cout << "Configuration options" << std::endl
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

    //Check passed arguments for ranges
    //methods between 1 and 3
    if(method < 0 || method > 3)
    {
        std::cout << "Error in method selection.  Values ranging from 1 and 3 only" << std::endl;

        return -1;
    }

    if(dataSize <= 1)
    {
        std::cout << "Invalid range.  Please enter more than 1 point" << std::endl;
    }

    //Check Dimensions
    if(dimensions > 4 || dimensions < 1)
    {
        std::cout << "Error in dimensions.  Valid range 1-4" << std::endl;

        return -1;
    }

    //Create application main
    GeneratorMain *ApplicationMain = new GeneratorMain(method, dimensions, dataSize);
    ApplicationMain->startUp();

    //Delete Object
    delete ApplicationMain;

    std::cout << "Generation of points complete." << std::endl;

    return 0;
}
