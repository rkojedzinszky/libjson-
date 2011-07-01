#ifndef JSON_VALUE_HPP
#define JSON_VALUE_HPP

#include <ostream>
#include <stdexcept>
#include <boost/intrusive_ptr.hpp>

#include <json/ibool.hpp>
#include <json/inumeric.hpp>
#include <json/istring.hpp>

namespace JSON
{

class ParserError : public std::runtime_error {
	public:
		ParserError(char token);
		ParserError(const std::string &message);
};

class ParserEndOfStreamError : public ParserError {
	public:
		ParserEndOfStreamError();
};

class Value
{
public:
	typedef IValue::Array Array;
	typedef IValue::Object Object;

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
	Value(double v);
	Value &setDouble(double v);
	double getDouble() const;
	Value &operator=(double v);
	operator double() const;

	// string
	Value(const std::string &s);
	Value &setString(const std::string &s);
	const std::string &getString() const;
	Value &operator=(const std::string &s);
	operator const std::string&() const;
	Value(const char *s);
	Value &setString(const char *s);
	Value &operator=(const char *s);

	// converter functions
	bool asBool() const;
	int asInt() const;
	long long asLong() const;
	double asDouble() const;
	std::string asString() const;

	// array
	void resize(size_t sz);
	Value &operator[](int idx);
	Value &at(int idx);
	Value &front();
	Value &back();
	Value &push_front(const Value &v);
	Value &push_back(const Value &v);
	Value pop_front();
	Value pop_back();
	Array &array();

	// object
	Value &operator[](const std::string &f);
	Value &operator[](const char *f);
	Value keys() const;
	size_t erase(const std::string &f);
	size_t erase(const char *f);
	Object &object();

	// common to array & object
	size_t size() const;

	// operators
	bool operator==(const Value &r) const;
	bool operator<(const Value &r) const;
	bool operator<=(const Value &r) const;

	bool operator==(const bool v) const;
	bool operator<(const bool v) const;
	bool operator<=(const bool v) const;
	bool operator==(const int v) const;
	bool operator<(const int v) const;
	bool operator<=(const int v) const;
	bool operator==(const long long v) const;
	bool operator<(const long long v) const;
	bool operator<=(const long long v) const;
	bool operator==(const double v) const;
	bool operator<(const double v) const;
	bool operator<=(const double v) const;
	bool operator==(const std::string &v) const;
	bool operator<(const std::string &v) const;
	bool operator<=(const std::string &v) const;
	bool operator==(const char *v) const;
	bool operator<(const char *v) const;
	bool operator<=(const char *v) const;

	template <typename T> bool operator!=(const T v) const;
	template <typename T> bool operator>(const T v) const;
	template <typename T> bool operator>=(const T v) const;

	// serialization
	void toStream(std::ostream &o) const;
	Value &fromStream(std::istream &i);

	friend Value Array();
	friend Value Object();

private:
	typedef boost::intrusive_ptr<IValue> valueType;
	valueType value;

protected:
	Value(IValue *v);

	static IValue *newArray();
	static IValue *newObject();

};

inline ParserError::ParserError(char token) : std::runtime_error(std::string("JSON Parser error: unexpected token: ") + token)
{
}

inline ParserError::ParserError(const std::string &message) : std::runtime_error(std::string("JSON Parser error: ") + message)
{
}

inline ParserEndOfStreamError::ParserEndOfStreamError() : ParserError("eof detected on stream")
{
}

inline Value::Value(IValue *v) : value(v)
{
}

inline Value::Value() : value(new IValue())
{
}

inline Value::Value(const Value &v) : value(v.value)
{
}

inline Value &Value::operator=(const Value &v)
{
	value = v.value;
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
inline Value::Value(int v) : value(new INumeric(static_cast<double>(v)))
{
}

inline Value &Value::setInt(int v)
{
	value = new INumeric(static_cast<double>(v));

	return *this;
}

inline int Value::getInt() const
{
	return value->getInt();
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
	value = new INumeric(v);

	return *this;
}

inline long long Value::getLong() const
{
	return value->getLong();
}

inline Value &Value::operator=(long long v)
{
	return setLong(v);
}

inline Value::operator long long() const
{
	return getLong();
}

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

// converter functions
inline bool Value::asBool() const
{
	return value->asBool();
}

inline int Value::asInt() const
{
	return value->asInt();
}

inline long long Value::asLong() const
{
	return value->asLong();
}

inline double Value::asDouble() const
{
	return value->asDouble();
}

inline std::string Value::asString() const
{
	return value->asString();
}

// array
inline void Value::resize(size_t sz)
{
	value->resize(sz);
}

inline Value &Value::operator[](int idx)
{
	return value->operator[](idx);
}

inline Value &Value::at(int idx)
{
	return value->at(idx);
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

inline Value::Array &Value::array()
{
	return value->array();
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

inline Value Value::keys() const
{
	return value->keys();
}

inline size_t Value::erase(const std::string &f)
{
	return value->erase(f);
}

inline size_t Value::erase(const char *f)
{
	return value->erase(std::string(f));
}

inline Value::Object &Value::object()
{
	return value->object();
}


inline size_t Value::size() const
{
	return value->size();
}

inline bool Value::operator==(const Value &r) const
{
	return value->operator==(*r.value);
}

inline bool Value::operator<(const Value &r) const
{
	return value->operator<(*r.value);
}

inline bool Value::operator<=(const Value &r) const
{
	return value->operator<=(*r.value);
}

#define VALUE_COMPARE(type, func) \
	inline bool Value::operator==(const type v) const \
	{ \
		return value->func() == v; \
	} \
	inline bool Value::operator<(const type v) const \
	{ \
		return value->func() < v; \
	} \
	inline bool Value::operator<=(const type v) const \
	{ \
		return value->func() <= v; \
	}

VALUE_COMPARE(bool, getBool)
VALUE_COMPARE(int, getInt)
VALUE_COMPARE(long long, getLong)
VALUE_COMPARE(double, getDouble)
VALUE_COMPARE(std::string &, getString)
VALUE_COMPARE(char *, getString)

#undef VALUE_COMPARE

template <typename T>
inline bool Value::operator!=(const T v) const
{
	return !(*this == v);
}

template <typename T>
inline bool Value::operator>(const T v) const
{
	return !(*this <= v);
}

template <typename T>
inline bool Value::operator>=(const T v) const
{
	return !(*this < v);
}

inline void Value::toStream(std::ostream &o) const
{
	value->toStream(o);
}

inline Value Array()
{
	return Value::newArray();
}

inline Value Object()
{
	return Value::newObject();
}

}; // namespace JSON

static inline std::ostream &operator<<(std::ostream &o, JSON::Value &v)
{
	v.toStream(o);
	return o;
}

#endif
