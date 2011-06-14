#include <util.hpp>

namespace JSON
{

void stringtojsonstream(const std::string &s, std::ostream &o)
{
	o << "\"";

	for (std::string::const_iterator I = s.begin(); I != s.end(); I++) {
		switch(*I) {
		case '\"':
			o << "\\\"";
			break;
		case '\\':
			o << "\\\\";
			break;
		case '\b':
			o << "\\b";
			break;
		case '\f':
			o << "\\f";
			break;
		case '\n':
			o << "\\n";
			break;
		case '\r':
			o << "\\r";
			break;
		case '\t':
			o << "\\t";
			break;
		default:
			o << *I;
			break;
		}
	}

	o << "\"";
}

};
