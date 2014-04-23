#include <json/util.hpp>
#include <json/value.hpp>
#include <sstream>

namespace JSON
{

void stringtojsonstream(const std::string& s, std::ostream& o)
{
	o << "\"";

	for (std::string::const_iterator I = s.begin(); I != s.end(); ++I) {
		switch (*I) {
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

void jsonstringtostring(std::string& s, std::istream& i)
{
	std::ostringstream o;

	char c = i.get();
	if (c != '\"') {
		throw ParserError(c);
	}

	for (;;) {
		if (i.eof()) {
			throw ParserError("eof detected on stream");
		}
		c = i.get();
		if (c == '\"') {
			break;
		}

		if (c == '\\') {
			c = i.get();
			switch (c) {
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
