#include <json/value.hpp>
#include <json/util.hpp>
#include <sstream>

namespace JSON
{

Value &IObject::operator[](const std::string &f)
{
	return object[f];
}

Value IObject::keys() const
{
	Value r = Array();

	std::map<std::string, Value>::const_iterator E(object.end());
	for (std::map<std::string, Value>::const_iterator I = object.begin(); I != E; ++I) {
		r.push_back(I->first);
	}

	return r;
}

size_t IObject::erase(const std::string &f)
{
	return object.erase(f);
}

size_t IObject::size() const
{
	return object.size();
}

void IObject::toStream(std::ostream &o) const
{
	o << "{";

	std::map<std::string, Value>::const_iterator I(object.begin());
	std::map<std::string, Value>::const_iterator E(object.end());

	if (I != E) {
		stringtojsonstream(I->first, o);
		o << ":";
		(I->second).toStream(o);
		++I;
	}

	for (; I != E; ++I) {
		o << ",";

		stringtojsonstream(I->first, o);
		o << ":";
		(I->second).toStream(o);
	}

	o << "}";
}

void IObject::fromStream(std::istream &i)
{
	object.clear();
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
		object[k] = v;

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
