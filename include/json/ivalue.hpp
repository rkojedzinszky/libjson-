#ifndef JSON_IVALUE_HPP
#define JSON_IVALUE_HPP

#include <string>
#include <typeinfo>
#include <ostream>

#include <json/refcounted.hpp>

namespace JSON
{

class Value;

class IValue : public refcounted
{
public:
	// scalars
	virtual bool isNull() const;

	// boolean
	virtual operator bool() const;

	// numeric
	virtual operator double() const;

	// string
	virtual operator const std::string&() const;

	// array
	virtual void resize(size_t sz);
	virtual Value &operator[](int idx);
	virtual Value &at(int idx);
	virtual Value &front();
	virtual Value &back();
	virtual void push_front(const Value &v);
	virtual void push_back(const Value &v);
	virtual Value pop_front();
	virtual Value pop_back();

	// object
	virtual Value &operator[](const std::string &f);

	// common to array & object
	virtual size_t size() const;

	// operators
	virtual bool operator==(const IValue &r) const;
	virtual bool operator<(const IValue &r) const;
	virtual bool operator<=(const IValue &r) const;

	// serialization
	virtual void toStream(std::ostream &o) const;
	virtual void fromStream(std::istream &i);
};

}; // namespace JSON

#endif
