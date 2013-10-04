#include <sstream>

#include <json/value.hpp>
#include <json/iobject.hpp>
#include <json/util.hpp>

namespace JSON
{

IValue::Type IObject::type() const
{
	return JSON_OBJECT;
}

IObject* IObject::clone() const
{
	IObject* ret = new IObject();

	for (std::map<std::string, Value>::const_iterator I = value.begin(); I != value.end(); ++I) {
		ret->value.insert(std::make_pair(I->first, I->second.clone()));
	}

	return ret;
}

IValue::Object &IObject::object()
{
	return value;
}

size_t IObject::size() const
{
	return value.size();
}

void IObject::toStream(std::ostream &o) const
{
	o << '{';

	std::map<std::string, Value>::const_iterator I(value.begin());
	std::map<std::string, Value>::const_iterator E(value.end());

	if (I != E) {
		stringtojsonstream(I->first, o);
		o << ':';
		(I->second).toStream(o);
		++I;
	}

	for (; I != E; ++I) {
		o << ',';

		stringtojsonstream(I->first, o);
		o << ':';
		(I->second).toStream(o);
	}

	o << '}';
}

void IObject::fromStream(std::istream &i)
{
	value.clear();
	int c;

	c = sget(i);
	if (c != '{') {
		throw ParserError(c);
	}

	for (;;) {
		i >> std::ws;

		if (speek(i) == '}') {
			i.get();
			break;
		}

		std::string k;
		JSON::Value v;

		jsonstringtostring(k, i);
		i >> std::ws;

		c = sget(i);
		if (c != ':') {
			throw ParserError(c);
		}

		v.fromStream(i);
		value[k] = v;

		i >> std::ws;

		if (speek(i) == ',') {
			i.get();
		}
	}
}

}; // namespace JSON
