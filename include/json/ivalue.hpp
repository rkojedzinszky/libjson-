#ifndef JSON_IVALUE_HPP
#define JSON_IVALUE_HPP

#include <map>
#include <deque>
#include <string>
#include <ostream>

#include <json/refcounted.hpp>

namespace JSON
{

class Value;

class IValue : public refcounted
{
public:
	typedef std::deque<Value> Array;
	typedef std::map<std::string, Value> Object;

	// scalars
	virtual bool isNull() const;

	// boolean
	virtual bool getBool() const;

	// numeric
	virtual int getInt() const;
	virtual long long getLong() const;
	virtual double getDouble() const;

	// string
	virtual const std::string &getString() const;

	// converter functions
	virtual bool asBool() const;
	virtual int asInt() const;
	virtual long long asLong() const;
	virtual double asDouble() const;
	virtual std::string asString() const;

	// array
	virtual Array &array();

	// object
	virtual Object &object();

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
