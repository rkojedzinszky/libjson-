#include <util.hpp>
#include <value.hpp>
#include <sstream>

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

void jsonstringtostring(std::string &s, std::istream &i)
{
	char c;
	std::ostringstream o;

	c = i.get();
	if (c != '\"') {
		std::ostringstream o;
		o << c;
		throw ParserError(o.str());
	}

	for (;!i.eof() && ((c = i.get()) != '\"');) {
		if (c == '\\') {
			c = i.get();
			switch(c) {
			case '\"':
				o << '\"';
				break;
			case '\\':
				o << '\\';
				break;
			case 'b':
				o << '\b';
				break;
			case 'f':
				o << '\f';
				break;
			case 'n':
				o << '\n';
				break;
			case 'r':
				o << '\r';
				break;
			case 't':
				o << '\t';
				break;
			default:
				o << c;
				break;
			}
		} else {
			o << c;
		}
	}

	s = o.str();
}

};
