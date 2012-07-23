#include <ostream>
#include <sstream>

#include <json/value.hpp>
#include <json/iarray.hpp>
#include <json/util.hpp>

namespace JSON
{

IValue::Type IArray::type() const
{
	return JSON_ARRAY;
}

IValue::Array &IArray::array()
{
	return value;
}

size_t IArray::size() const
{
	return value.size();
}

void IArray::toStream(std::ostream &o) const
{
	o << '[';

	std::deque<Value>::const_iterator I(value.begin());
	std::deque<Value>::const_iterator E(value.end());

	if (I != E) {
		I->toStream(o);
		++I;
	}

	for (; I != E; ++I) {
		o << ',';
		I->toStream(o);
	}

	o << ']';
}

IArray * IArray::fromStream(std::istream &i)
{
	IArray * r = new IArray(0);
	int c;

	c = sget(i);
	if (c != '[') {
		throw ParserError(c);
	}

	for (;;) {
		i >> std::ws;

		if (speek(i) == ']') {
			i.get();
			break;
		}

		JSON::Value v;
		v.fromStream(i);
		r->value.push_back(v);

		i >> std::ws;

		if (speek(i) == ',') {
			i.get();
		}
	}

	return r;
}

}; // namespace JSON
