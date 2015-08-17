//    Copyright (c) 2015 Alin Marin Elena <alin@elena.space>
//    The MIT License http://opensource.org/licenses/MIT
#include <iostream>
#include <string>
#include "colours.h"
#include "customException.h"
#include "parseCLI.h"
#include "general.h"

int main(int argc, char **argv)
{

  generalInput inps;
  inps.version="0.0.1.β0";
  try {
    boost::program_options::variables_map clioMap=parseCLiandConfig(argc,argv,&inps);
    if (clioMap.count("help")) return SUCCESS;
    if (clioMap.count("version")) {
      std::cout<<colours::green<<"version: "<<inps.version<<colours::end<<"\n";
      return SUCCESS;
    }

    std::cout<<colours::green<<"Echo the options used\n"<<colours::end;
    std::string debugFile=inps.configFile+".dbg";
    printOptions(&clioMap,&debugFile);
  }
  catch(customException &e) {
    std::cerr<<colours::red<<"Error: "<< e.what() << colours::end<<"\n";
    return e.id;
  }

  return SUCCESS;
}
