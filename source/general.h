//    Copyright (c) 2015 Alin Marin Elena <alin@elena.space>
//    The MIT License http://opensource.org/licenses/MIT
#ifndef GENERAL_H
#define GENERAL_H
const int SUCCESS = 0;
const int ERROR_CLI = 1;
const int ERROR_CFILE = 2;
const int ERROR_NO_IDEA = 42;
struct generalInput {
  unsigned int nsteps;
  std::string version="0.0.1.β0";
  std::string method;
  std::string configFile;
};
#endif // GENERAL_H
