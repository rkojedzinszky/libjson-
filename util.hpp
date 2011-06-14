#ifndef JSON_UTIL_HPP
#define JSON_UTIL_HPP

#include <ostream>
#include <string>

namespace JSON
{

void stringtojsonstream(const std::string &s, std::ostream &o);
void jsonstringtostring(std::string &s, std::istream &i);

};

#endif
