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

IObject * IObject::fromStream(std::istream &i)
{
	IObject * r = new IObject();
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

		std::string k = jsonstringtostring(i);
		JSON::Value v;

		i >> std::ws;

		c = sget(i);
		if (c != ':') {
			throw ParserError(c);
		}

		v.fromStream(i);
		r->value[k] = v;

		i >> std::ws;

		if (speek(i) == ',') {
			i.get();
		}
	}

	return r;
}

}; // namespace JSON
