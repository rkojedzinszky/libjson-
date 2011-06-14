#ifndef JSON_IVALUE_HPP
#define JSON_IVALUE_HPP

#include <string>
#include <typeinfo>
#include <ostream>

namespace JSON
{

class Value;

class IValue
{
public:
	int refcnt;
	IValue() : refcnt(0) { };
	virtual ~IValue();

	// scalars
	virtual bool isNull() const;

	// boolean
	virtual operator bool() const;

	// int
	virtual operator int() const;

	// string
	virtual operator const std::string&() const;

	// array
	virtual Value &operator[](int idx);

	// hash
	virtual Value &operator[](const std::string &f);

	// common to array & hash
	virtual size_t size() const;

	// operators
	virtual bool operator==(const IValue &r) const;
	virtual bool operator<(const IValue &r) const;
	virtual bool operator<=(const IValue &r) const;

	// serialization
	virtual void toStream(std::ostream &o) const;
};

}; // namespace JSON

#endif
