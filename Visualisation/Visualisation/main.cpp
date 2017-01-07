#include <iostream>
#include <boost/program_options.hpp>
#include "VisualisationMain.h"

Visualiser *visual;

namespace
{
    const size_t ERROR_IN_COMMAND_LINE = 1;
    const size_t SUCCESS = 0;
    const size_t ERROR_UNHANDLED_EXCEPTION = 2;
}

int main(int argc, char **argv)
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
                  lc); // can throw

        if ( lc.count("help")  )
        {
          std::cout << "Configuration settings:" << std::endl
                    << desc << std::endl;
          return SUCCESS;
        }

        bpo::notify(lc); // throws on error, Placed after help.

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

    if(method < 1 || method > 3)
    {
        return ERROR_IN_COMMAND_LINE;
    }

    if(dimensions < 2 || dimensions > 3)
    {
        std::cout << "Error in Dimension Selection" << std::endl;
        return ERROR_IN_COMMAND_LINE;
    }
    else
    {
        VisualisationMain *visualMain = new VisualisationMain(argc, argv, method, dimensions);
        visualMain->main();
    }

    return 0;
}



