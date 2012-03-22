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
	enum Type {
		JSON_NULL,
		JSON_BOOL,
		JSON_NUMBER,
		JSON_STRING,
		JSON_ARRAY,
		JSON_OBJECT
	};

	// return type info
	virtual Type type() const;

	typedef std::deque<Value> Array;
	typedef std::map<std::string, Value> Object;

	// scalars

	// boolean
	virtual bool getBool() const;

	// numeric
	virtual int getInt() const;
	virtual unsigned getUInt() const;
	virtual long long getLong() const;
	virtual unsigned long long getULong() const;
	virtual double getDouble() const;

	// string
	virtual const std::string &getString() const;

	// converter functions
	virtual bool asBool() const;
	virtual int asInt() const;
	virtual unsigned asUInt() const;
	virtual long long asLong() const;
	virtual unsigned long long asULong() const;
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
