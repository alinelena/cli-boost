//    Copyright (c) 2015 Alin Marin Elena <alin@elena.space>
//    The MIT License http://opensource.org/licenses/MIT
#include <iostream>
#include <fstream>
#include "colours.h"
#include "customException.h"
#include "parseCLI.h"

boost::program_options::variables_map parseCLiandConfig(int ac, char** av, generalInput *inps)
{
  namespace clio = boost::program_options;
  clio::options_description clionly("Command Line Only Options");
  clionly.add_options()
  ("help,h","Prints help messages")
  ("version,v","Show me the version")
  ("config,c",clio::value<std::string>(&(inps->configFile))->default_value("options.conf"),"Config file from where options can be read");
  clio::options_description clic("Config File Options");
  clic.add_options()
  ("steps,s",clio::value<unsigned int>(&(inps->nsteps))->default_value(42),"Number of steps")
  ("method,m",clio::value< std::string >(&(inps->method))->default_value("TAMC"),"Method to be employed");
  clio::options_description clics("Command Line and Config File Options");
  clics.add(clionly).add(clic);

  clio::variables_map clioMap;
  try {
    clio::store(clio::parse_command_line(ac,av,clics),clioMap);
    clio::notify(clioMap);
  }
  catch(clio::error &e) {
    std::cerr<<colours::red<<"Error: "<< e.what() << colours::end<<"\n";
    std::cout<<colours::green<<"Command line Options:\n"<<colours::end<<clics<<"\n";
    throw customException(ERROR_CLI);
  }
  try {
    if (inps->configFile == "options.conf") {
      std::ifstream icfile(inps->configFile.c_str());
      if(!icfile) {
        std::cout<<colours::yellow<<"Creating empty config file\n"<<colours::end;
        icfile.close();
        std::fstream icfile(inps->configFile.c_str(),std::ios::out);
        icfile.close();
      }
    }
    clio::store(clio::parse_config_file<char>(inps->configFile.c_str(),clic),clioMap);
    clio::notify(clioMap);
  }
  catch(clio::error &e) {
    std::cerr<<colours::red<<"Error: "<< e.what() << colours::end<<"\n";
    std::cout<<colours::green<<"Config FilesOptions:\n"<<colours::end<<clic<<"\n";
    throw customException(ERROR_CFILE);
  }
  if (clioMap.count("help")) {
    std::cout<<colours::green<<"Command line Options:\n"<<colours::end<<clics<<"\n";
  }
  return clioMap;
}

void printOptions(boost::program_options::variables_map *clioMap, std::string *dbgf)
{
  std::fstream dbg(dbgf->c_str(),std::ios::out);
  for (const auto& it : *clioMap) {
    std::cout << it.first.c_str() << " ";
    dbg << it.first.c_str() << " = ";
    auto& value = it.second.value();
    if (auto v = boost::any_cast<unsigned int>(&value)) {
      std::cout << colours::yellow<<*v<<"\n"<<colours::end;
      dbg <<*v<<"\n";
    }
    else if (auto v = boost::any_cast<std::string>(&value)) {
      std::cout << colours::yellow<<*v<<"\n"<<colours::end;
      dbg <<*v<<"\n";
    }
    else {
      std::cout << colours::red<<"No idea about this type\n"<<colours::end;
    }
  }
  dbg.close();
}

