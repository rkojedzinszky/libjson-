#ifndef JSON_IARRAY_HPP
#define JSON_IARRAY_HPP

#include <json/ivalue.hpp>
#include <deque>

namespace JSON
{

class Value;

class IArray : public IValue
{
private:
	std::deque<Value> value;

public:
	Value &operator[](int idx);
	Value &front();
	Value &back();
	void push_front(const Value &v);
	void push_back(const Value &v);
	Value pop_front();
	Value pop_back();
	size_t size() const;

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);
};

}; // namespace JSON

#endif
