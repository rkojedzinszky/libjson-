#include <ostream>
#include <sstream>

#include <json/value.hpp>
#include <json/util.hpp>

namespace JSON
{

void IArray::resize(size_t sz)
{
	value.resize(sz);
}

Value &IArray::operator[](int idx)
{
	return value[idx];
}

Value &IArray::at(int idx)
{
	return value.at(idx);
}

Value &IArray::front()
{
	return value.front();
}

Value &IArray::back()
{
	return value.back();
}

void IArray::push_front(const Value &v)
{
	value.push_front(v);
}

void IArray::push_back(const Value &v)
{
	value.push_back(v);
}

Value IArray::pop_front()
{
	Value v = front();
	value.pop_front();
	return v;
}

Value IArray::pop_back()
{
	Value v = back();
	value.pop_back();
	return v;
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

void IArray::fromStream(std::istream &i)
{
	value.clear();
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
		value.push_back(v);

		i >> std::ws;

		if (speek(i) == ',') {
			i.get();
		}
	}
}

}; // namespace JSON
