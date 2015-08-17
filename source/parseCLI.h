//    Copyright (c) 2015 Alin Marin Elena <alin@elena.space>
//    The MIT License http://opensource.org/licenses/MIT
#ifndef PARSECLI_H
#define PARSECLI_H
#include <boost/program_options.hpp>
#include <string>
#include "general.h"
boost::program_options::variables_map parseCLiandConfig(int ac, char** av, generalInput *inps);
void printOptions(boost::program_options::variables_map *clioMap, std::string *dbgf);
#endif //PARSECLI_H
