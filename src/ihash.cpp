#include <json/value.hpp>
#include <json/util.hpp>
#include <sstream>

namespace JSON
{

Value &IHash::operator[](const std::string &f) throw ()
{
	return hash[f];
}

size_t IHash::size() const throw ()
{
	return hash.size();
}

void IHash::toStream(std::ostream &o) const
{
	o << "{";

	for (std::map<std::string, Value>::const_iterator I = hash.begin(); I != hash.end(); I++) {
		if (I != hash.begin()) {
			o << ",";
		}

		stringtojsonstream(I->first, o);
		o << ":";
		(I->second).toStream(o);
	}

	o << "}";
}

void IHash::fromStream(std::istream &i)
{
	hash.clear();
	char c;

	c = i.get();
	if (c != '{') {
		std::ostringstream o;
		o << c;
		throw ParserError(o.str());
	}

	for (;;) {
		std::string k;
		JSON::Value v;

		i >> std::ws;
		jsonstringtostring(k, i);
		i >> std::ws >> c;
		if (c != ':') {
			std::ostringstream o;
			o << c;
			throw ParserError(o.str());
		}

		v.fromStream(i);
		hash[k] = v;

		i >> std::ws;

		if (i.peek() != ',')
			break;
		i.get();
	}

	c = i.get();
	if (c != '}') {
		std::ostringstream o;
		o << c;
		throw ParserError(o.str());
	}
}

}; // namespace JSON
