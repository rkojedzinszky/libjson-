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
	virtual bool isNull() const throw ();

	// boolean
	virtual operator bool() const throw (std::bad_cast);

	// int
	virtual operator int() const throw (std::bad_cast);

	// string
	virtual operator const std::string&() const throw (std::bad_cast);

	// array
	virtual Value &operator[](int idx) throw (std::bad_cast);

	// hash
	virtual Value &operator[](const std::string &f) throw (std::bad_cast);

	// common to array & hash
	virtual size_t size() const throw (std::bad_cast);

	// operators
	virtual bool operator==(const IValue &r) const throw (std::bad_cast);
	virtual bool operator<(const IValue &r) const throw (std::bad_cast);
	virtual bool operator<=(const IValue &r) const throw (std::bad_cast);

	// serialization
	virtual void toStream(std::ostream &o) const;
};

}; // namespace JSON

#endif
