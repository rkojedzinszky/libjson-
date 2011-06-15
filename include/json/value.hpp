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
	Value &operator=(bool v);
	operator bool() const;

	// numeric
	Value(double v);
	Value &operator=(double v);
	Value(int v);
	Value &operator=(int v);
	operator double() const;

	// string
	Value(const std::string &s);
	Value(const char *s);
	Value &operator=(const std::string &s);
	Value &operator=(const char *s);
	operator const std::string&() const;

	// array
	Value &operator[](int idx);

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

inline bool Value::isNull() const
{
	return value->isNull();
}

inline Value::Value(bool v) : value(new IBool(v))
{
}

inline Value &Value::operator=(bool v)
{
	value = new IBool(v);

	return *this;
}

inline Value::operator bool() const
{
	return value->operator bool();
}

inline Value::Value(double v) : value(new INumeric(v))
{
}

inline Value &Value::operator=(double v)
{
	value = new INumeric(v);

	return *this;
}

inline Value::Value(int v) : value(new INumeric(v))
{
}

inline Value &Value::operator=(int v)
{
	value = new INumeric(v);

	return *this;
}

inline Value::operator double() const
{
	return value->operator double();
}

inline Value::Value(const std::string &s) : value(new IString(s))
{
}

inline Value::Value(const char *s) : value(new IString(s))
{
}

inline Value &Value::operator=(const std::string &s)
{
	value = new IString(s);

	return *this;
}

inline Value &Value::operator=(const char *s)
{
	value = new IString(s);

	return *this;
}

inline Value::operator const std::string&() const
{
	return value->operator const std::string&();
}

inline Value &Value::operator[](int idx)
{
	return value->operator[](idx);
}

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
