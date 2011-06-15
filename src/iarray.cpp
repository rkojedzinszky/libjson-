#include <json/value.hpp>
#include <ostream>
#include <sstream>

namespace JSON
{

Value &IArray::operator[](int idx) throw ()
{
	if (idx >= value.size()) {
		value.resize(idx+1);
	}

	return value[idx];
}

size_t IArray::size() const throw()
{
	return value.size();
}

void IArray::toStream(std::ostream &o) const
{
	o << "[";

	std::vector<Value>::const_iterator I(value.begin());
	std::vector<Value>::const_iterator E(value.end());

	if (I != E) {
		I->toStream(o);
		++I;
	}

	for (; I != E; ++I) {
		o << ",";
		I->toStream(o);
	}

	o << "]";
}

void IArray::fromStream(std::istream &i)
{
	value.clear();
	char c;

	c = i.get();
	if (c != '[') {
		std::ostringstream o;
		o << c;
		throw ParserError(o.str());
	}

	for (;;) {
		JSON::Value v;

		v.fromStream(i);
		value.push_back(v);

		i >> std::ws;
		if (i.peek() != ',')
			break;
		i.get();
	}

	c = i.get();
	if (c != ']') {
		std::ostringstream o;
		o << c;
		throw ParserError(o.str());
	}
}

}; // namespace JSON
