#ifndef JSON_UTIL_HPP
#define JSON_UTIL_HPP

#include <iostream>
#include <string>
#include <json/value.hpp>

namespace JSON
{

void stringtojsonstream(const std::string& s, std::ostream& o);
void jsonstringtostring(std::string& s, std::istream& i);

inline int sget(std::istream& i)
{
	int c = i.get();
	if (c == -1) {
		throw ParserEndOfStreamError();
	}
	return c;
}

inline int speek(std::istream& i)
{
	int c = i.peek();
	if (c == -1) {
		throw ParserEndOfStreamError();
	}
	return c;
}

};

#endif
