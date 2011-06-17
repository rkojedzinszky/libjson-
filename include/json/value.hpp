#ifndef JSON_VALUE_HPP
#define JSON_VALUE_HPP

#include <ostream>
#include <stdexcept>
#include <boost/intrusive_ptr.hpp>

#include <json/ibool.hpp>
#include <json/inumeric.hpp>
#include <json/istring.hpp>
#include <json/iarray.hpp>
#include <json/iobject.hpp>
#include <cmath>
#include <climits>

namespace JSON
{

class ParserError : public std::runtime_error {
	public:
		ParserError(const std::string &token);
};

class Value
{
private:
	typedef boost::intrusive_ptr<IValue> valueType;
	valueType value;

protected:
	Value(IValue *v);

public:
	Value();
	Value(const Value &v);
	Value &operator=(const Value &v);

	// scalars
	bool isNull() const;

	// boolean
	Value(bool v);
	Value &setBool(bool v);
	bool getBool() const;
	Value &operator=(bool v);
	operator bool() const;

	// numeric
	Value(double v);
	Value &setDouble(double v);
	double getDouble() const;
	Value &operator=(double v);
	operator double() const;
	Value(int v);
	Value &setInt(int v);
	int getInt() const;
	Value &operator=(int v);
	operator int() const;
	Value(long long v);
	Value &setLong(long long v);
	long long getLong() const;
	Value &operator=(long long v);
	operator long long() const;

	// string
	Value(const std::string &s);
	Value &setString(const std::string &s);
	const std::string &getString() const;
	Value &operator=(const std::string &s);
	operator const std::string&() const;
	Value(const char *s);
	Value &setString(const char *s);
	Value &operator=(const char *s);

	// array
	Value &operator[](int idx);
	Value &front();
	Value &back();
	Value &push_front(const Value &v);
	Value &push_back(const Value &v);
	Value pop_front();
	Value pop_back();

	// object
	Value &operator[](const std::string &f);
	Value &operator[](const char *f);

	// common to array & object
	size_t size() const;

	// operators
	bool operator==(const Value &r) const;
	bool operator!=(const Value &r) const;
	bool operator<(const Value &r) const;
	bool operator>(const Value &r) const;
	bool operator<=(const Value &r) const;
	bool operator>=(const Value &r) const;

	// serialization
	void toStream(std::ostream &o) const;
	Value &fromStream(std::istream &i);

	friend Value Array();
	friend Value Object();
};

inline ParserError::ParserError(const std::string &token) : std::runtime_error(std::string("JSON Parser error: unexpected token: ") + token)
{
}

inline Value::Value(IValue *v) : value(v)
{
}

inline Value::Value() : value(new IValue())
{
}

inline Value::Value(const Value &v)
{
	operator=(v);
}

inline Value &Value::operator=(const Value &v)
{
	IScalar *s = dynamic_cast<IScalar *>(v.value.get());
	if (s == NULL) {
		value = v.value;
	} else {
		value = s->clone();
	}
	return *this;
}

// scalars
inline bool Value::isNull() const
{
	return value->isNull();
}

// boolean
inline Value::Value(bool v) : value(new IBool(v))
{
}

inline Value &Value::setBool(bool v)
{
	value = new IBool(v);

	return *this;
}

inline bool Value::getBool() const
{
	return value->getBool();
}

inline Value &Value::operator=(bool v)
{
	return setBool(v);
}

inline Value::operator bool() const
{
	return getBool();
}

// numeric
inline Value::Value(double v) : value(new INumeric(v))
{
}

inline Value &Value::setDouble(double v)
{
	value = new INumeric(v);

	return *this;
}

inline double Value::getDouble() const
{
	return value->getDouble();
}

inline Value &Value::operator=(double v)
{
	return setDouble(v);
}

inline Value::operator double() const
{
	return getDouble();
}

inline Value::Value(int v) : value(new INumeric(v))
{
}

inline Value &Value::setInt(int v)
{
	return setDouble(v);
}

inline int Value::getInt() const
{
	double v = getDouble();

	if (floor(v) != v) {
		throw std::domain_error("Value::getInt(): numeric has fractional part");
	}

	if (v < INT_MIN || v > INT_MAX) {
		throw std::domain_error("Value::getInt(): numeric does not fit in integer");
	}

	return v;
}

inline Value &Value::operator=(int v)
{
	return setInt(v);
}

inline Value::operator int() const
{
	return getInt();
}

inline Value::Value(long long v) : value(new INumeric(v))
{
}

inline Value &Value::setLong(long long v)
{
	return setDouble(v);
}

inline long long Value::getLong() const
{
	double v = getDouble();

	if (floor(v) != v) {
		throw std::domain_error("Value::getLong(): numeric has fractional part");
	}

	if (v < LLONG_MIN || v > LLONG_MAX) {
		throw std::domain_error("Value::getLong(): numeric does not fit in long long");
	}

	return v;
}

inline Value &Value::operator=(long long v)
{
	return setLong(v);
}

inline Value::operator long long() const
{
	return getLong();
}

// string
inline Value::Value(const std::string &s) : value(new IString(s))
{
}

inline Value &Value::setString(const std::string &s)
{
	value = new IString(s);

	return *this;
}

inline const std::string &Value::getString() const
{
	return value->getString();
}

inline Value &Value::operator=(const std::string &s)
{
	return setString(s);
}

inline Value::operator const std::string&() const
{
	return getString();
}

inline Value::Value(const char *s) : value(new IString(s))
{
}

inline Value &Value::setString(const char *s)
{
	value = new IString(s);

	return *this;
}

inline Value &Value::operator=(const char *s)
{
	return setString(s);
}

// array
inline Value &Value::operator[](int idx)
{
	return value->operator[](idx);
}

inline Value &Value::front()
{
	return value->front();
}

inline Value &Value::back()
{
	return value->back();
}

inline Value &Value::push_front(const Value &v)
{
	value->push_front(v);

	return *this;
}

inline Value &Value::push_back(const Value &v)
{
	value->push_back(v);

	return *this;
}

inline Value Value::pop_front()
{
	return value->pop_front();
}

inline Value Value::pop_back()
{
	return value->pop_back();
}

// object
inline Value &Value::operator[](const std::string &f)
{
	return value->operator[](f);
}

inline Value &Value::operator[](const char *f)
{
	return value->operator[](std::string(f));
}

inline size_t Value::size() const
{
	return value->size();
}

inline bool Value::operator==(const Value &r) const
{
	return value->operator==(*r.value);
}

inline bool Value::operator!=(const Value &r) const
{
	return !operator==(r);
}

inline bool Value::operator<(const Value &r) const
{
	return value->operator<(*r.value);
}

inline bool Value::operator>(const Value &r) const
{
	return r.operator<(*this);
}

inline bool Value::operator<=(const Value &r) const
{
	return value->operator<=(*r.value);
}

inline bool Value::operator>=(const Value &r) const
{
	return r.operator<=(*this);
}

inline void Value::toStream(std::ostream &o) const
{
	value->toStream(o);
}

inline Value Array()
{
	return Value(new IArray());
}

inline Value Object()
{
	return Value(new IObject());
}

}; // namespace JSON

static inline std::ostream &operator<<(std::ostream &o, JSON::Value &v)
{
	v.toStream(o);
	return o;
}

#endif
