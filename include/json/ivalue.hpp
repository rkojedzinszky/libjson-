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
	virtual void resize(size_t sz);
	virtual Value &operator[](int idx);
	virtual Value &at(int idx);
	virtual Value &front();
	virtual Value &back();
	virtual void push_front(const Value &v);
	virtual void push_back(const Value &v);
	virtual Value pop_front();
	virtual Value pop_back();
	virtual Array &array();

	// object
	virtual Value &operator[](const std::string &f);
	virtual Value keys() const;
	virtual size_t erase(const std::string &f);
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
