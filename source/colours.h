//    Copyright (c) 2015 Alin Marin Elena <alin@elena.space>
//    The MIT License http://opensource.org/licenses/MIT
#ifndef COLOURS_H
#define COLOURS_H

#include <string>
namespace colours {
std::string const esc="\033[";
std::string const end=esc+"0m";
std::string const endB=esc+"1m";
std::string const red=esc+"31m";
std::string const green=esc+"32m";
std::string const yellow=esc+"33m";
std::string const blue=esc+"34m";
std::string const purple=esc+"35m";
std::string const cyan=esc+"36m";
std::string const white=esc+"37m";
}
#endif // COLOURS_H
// kate: indent-mode cstyle; space-indent on; indent-width 4;
