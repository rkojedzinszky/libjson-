#ifndef JSON_VALUE_HPP
#define JSON_VALUE_HPP

#include <vector>
#include <deque>
#include <list>
#include <map>

#include <ostream>
#include <stdexcept>

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

class bad_cast : public std::bad_cast {
};

/// The main JSON container

/// This can hold data types as specified in JSON:
/// - null value
/// - boolean
/// - number
/// - string
/// - array
/// - object (hash)
class Value
{
public:
	typedef IValue::Type Type;

	Type type() const;

	typedef IValue::Array Array;
	typedef IValue::Object Object;

	/// @name NULL value
	//@{

	/// Constructs a null value
	Value();

	//@}

	/// Initializes with the value of v (not deep copy)
	Value(const Value &v);

	/// Copies the value of v (not deep copy)
	Value &operator=(const Value &v);

	/** Tests whether a value is NULL
	 * Returns TRUE for NULL, false for any other values */
	bool isNull() const;

	///@name Boolean values
	//@{

	/// Construct from bool
	Value(bool v);

	/// Set as bool
	Value &setBool(bool v);

	/** Returns boolean value
	 * \exception std::bad_cast
	 */
	bool getBool() const;

	/// Assign value
	Value &operator=(bool v);

	/** Cast to bool
	 * \exception std::bad_cast
	 */
	operator bool() const;

	//@}

	/// @name Numeric values
	//@{

	/// Construct from int
	Value(int v);

	/// Set from int
	Value &setInt(int v);

	/** Return int value
	 * \exception std::bad_cast
	 * \exception std::domain_error
	 */
	int getInt() const;

	/// Assign an int
	Value &operator=(int v);

	/** Cast to int
	 * \exception std::bad_cast
	 * \exception std::domain_error
	 */
	operator int() const;

	/// Construct from unsigned
	Value(unsigned v);

	/// Set from unsigned
	Value &setUInt(unsigned v);

	/** Return unsigned value
	 * \exception std::bad_cast
	 * \exception std::domain_error
	 */
	unsigned getUInt() const;

	/// Assign an unsigned
	Value &operator=(unsigned v);

	/** Cast to unsigned
	 * \exception std::bad_cast
	 * \exception std::domain_error
	 */
	operator unsigned() const;

	/// Construct from long
	Value(long v);

	/// Assign a long
	Value &operator=(long v);

	/// Construct from unsigned long
	Value(unsigned long v);

	/// Assign an unsigned long
	Value &operator=(unsigned long v);

	/// Construct from long long
	Value(long long v);

	/// Set from long long
	Value &setLong(long long v);

	/** Return long long value
	 * \exception std::bad_cast
	 * \exception std::domain_error
	 */
	long long getLong() const;

	/// Assign a long long
	Value &operator=(long long v);

	/** Cast to long long
	 * \exception std::bad_cast
	 * \exception std::domain_error
	 */
	operator long long() const;

	/// Construct from unsigned long long
	Value(unsigned long long v);

	/// Set from unsigned long long
	Value &setULong(unsigned long long v);

	/** Return unsigned long long value
	 * \exception std::bad_cast
	 * \exception std::domain_error
	 */
	unsigned long long getULong() const;

	/// Assign an unsigned long long
	Value &operator=(unsigned long long v);

	/** Cast to unsigned long long
	 * \exception std::bad_cast
	 * \exception std::domain_error
	 */
	operator unsigned long long() const;

	/// Construct from double
	Value(double v);

	/// Set from double
	Value &setDouble(double v);

	/** Return double Value
	 * \exception std::bad_cast
	 * \exception std::domain_error
	 */
	double getDouble() const;

	/// Assig a double
	Value &operator=(double v);

	/** Cast to double
	 * \exception std::bad_cast
	 */
	operator double() const;

	//@}

	/// @name String values
	//@{

	/// Construct from std::string
	Value(const std::string &s);

	/// Set from std::string
	Value &setString(const std::string &s);

	/** Return std::string value
	 * \exception std::bad_cast
	 */
	const std::string &getString() const;

	/// Assign an std::string
	Value &operator=(const std::string &s);

	/** Cast to std::string
	 * \exception std::bad_cast
	 */
	operator const std::string&() const;

	/// Construct from const char *
	Value(const char *s);

	/// Set from const char *
	Value &setString(const char *s);

	/// Assig a const char *
	Value &operator=(const char *s);

	//@}

	/// @name Type conversion functions
	//@{
	bool asBool() const;
	int asInt() const;
	unsigned asUInt() const;
	long long asLong() const;
	unsigned long long asULong() const;
	double asDouble() const;
	std::string asString() const;
	//@}

	/// @name Array values
	//@{
	/// Construct from std::vector
	template <typename T>
	Value(const std::vector<T> &v);
	/// Construct from std::deque
	template <typename T>
	Value(const std::deque<T> &v);
	/// Construct from std::list
	template <typename T>
	Value(const std::list<T> &v);
	/// Assign an std::vector
	template <typename T>
	Value &operator=(const std::vector<T> &v);
	/// Assign an std::deque
	template <typename T>
	Value &operator=(const std::deque<T> &v);
	/// Assign an std::list
	template <typename T>
	Value &operator=(const std::list<T> &v);

	/// Return real STL Array container
	Array &array() const;
	void resize(size_t sz) const;
	Value &operator[](int idx) const;
	Value &at(int idx) const;
	Value &front() const;
	Value &back() const;
	const Value &push_front(const Value &v) const;
	const Value &push_back(const Value &v) const;
	Value pop_front() const;
	Value pop_back() const;
	//@}

	/// @name Object Value
	//@{
	/// Construct from std::map<string, T>
	template <typename T>
	Value(const std::map<std::string, T> &v);
	/// Assign an std::map<string, T>
	template <typename T>
	Value &operator=(const std::map<std::string, T> &v);

	/// Return real STL Object container
	Object &object() const;
	Value &operator[](const std::string &f) const;
	Value &operator[](const char *f) const;
	size_t erase(const std::string &f) const;
	size_t erase(const char *f) const;
	//@}

	/// Returns the size od an Array or Object
	size_t size() const;

	/// @name Comparison operators
	//@{
	bool operator==(const Value &r) const;
	bool operator<(const Value &r) const;
	bool operator<=(const Value &r) const;

	bool operator==(const bool v) const;
	bool operator<(const bool v) const;
	bool operator<=(const bool v) const;
	bool operator==(const int v) const;
	bool operator<(const int v) const;
	bool operator<=(const int v) const;
	bool operator==(const unsigned v) const;
	bool operator<(const unsigned v) const;
	bool operator<=(const unsigned v) const;
	bool operator==(const long long v) const;
	bool operator<(const long long v) const;
	bool operator<=(const long long v) const;
	bool operator==(const unsigned long long v) const;
	bool operator<(const unsigned long long v) const;
	bool operator<=(const unsigned long long v) const;
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
	//@}

	/// @name Serialization functions
	//@{
	/// Serialize to std::ostream
	void toStream(std::ostream &o) const;
	/// Deserialize from std::istream
	Value &fromStream(std::istream &i);
	//@}

	friend Value Array(size_t n);
	friend Value Object();

private:
	typedef refcounted_ptr<IValue> valueType;
	valueType value;

protected:
	Value(IValue *v);

	static IValue *newArray(size_t n);
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

inline Value::Type Value::type() const
{
	return value->type();
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
	return value->type() == IValue::JSON_NULL;
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

inline Value::Value(int v) : value(new INumeric(v))/*{{{*/
{
}

inline Value &Value::setInt(int v)
{
	value = new INumeric(v);

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
}/*}}}*/

inline Value::Value(unsigned v) : value(new INumeric(v))/*{{{*/
{
}

inline Value &Value::setUInt(unsigned v)
{
	value = new INumeric(v);

	return *this;
}

inline unsigned Value::getUInt() const
{
	return value->getUInt();
}

inline Value &Value::operator=(unsigned v)
{
	return setUInt(v);
}

inline Value::operator unsigned() const
{
	return getUInt();
}/*}}}*/

inline Value::Value(long v): value(new INumeric(v))/*{{{*/
{
}

inline Value &Value::operator=(long v)
{
	value = new INumeric(v);

	return *this;
}/*}}}*/

inline Value::Value(unsigned long v): value(new INumeric(v))/*{{{*/
{
}

inline Value &Value::operator=(unsigned long v)
{
	value = new INumeric(v);

	return *this;
}/*}}}*/

inline Value::Value(long long v) : value(new INumeric(v))/*{{{*/
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
}/*}}}*/

inline Value::Value(unsigned long long v) : value(new INumeric(v))/*{{{*/
{
}

inline Value &Value::setULong(unsigned long long v)
{
	value = new INumeric(v);

	return *this;
}

inline unsigned long long Value::getULong() const
{
	return value->getULong();
}

inline Value &Value::operator=(unsigned long long v)
{
	return setULong(v);
}

inline Value::operator unsigned long long() const
{
	return getULong();
}/*}}}*/

inline Value::Value(double v) : value(new INumeric(v))/*{{{*/
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
}/*}}}*/

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

inline unsigned Value::asUInt() const
{
	return value->asUInt();
}

inline long long Value::asLong() const
{
	return value->asLong();
}

inline unsigned long long Value::asULong() const
{
	return value->asULong();
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
template <typename T>
inline Value::Value(const std::vector<T> &v) : value(newArray(v.size()))
{
	std::copy(v.begin(), v.end(), array().begin());
}
template <typename T>
inline Value::Value(const std::deque<T> &v) : value(newArray(v.size()))
{
	std::copy(v.begin(), v.end(), array().begin());
}
template <typename T>
inline Value::Value(const std::list<T> &v) : value(newArray(v.size()))
{
	std::copy(v.begin(), v.end(), array().begin());
}

template <typename T>
inline Value &Value::operator=(const std::vector<T> &v)
{
	value = newArray(v.size());
	std::copy(v.begin(), v.end(), array().begin());

	return *this;
}

template <typename T>
inline Value &Value::operator=(const std::deque<T> &v)
{
	value = newArray(v.size());
	std::copy(v.begin(), v.end(), array().begin());

	return *this;
}

template <typename T>
inline Value &Value::operator=(const std::list<T> &v)
{
	value = newArray(v.size());
	std::copy(v.begin(), v.end(), array().begin());

	return *this;
}

inline Value::Array &Value::array() const
{
	return value->array();
}

inline void Value::resize(size_t sz) const
{
	array().resize(sz);
}

inline Value &Value::operator[](int idx) const
{
	return array()[idx];
}

inline Value &Value::at(int idx) const
{
	return array().at(idx);
}

inline Value &Value::front() const
{
	return array().front();
}

inline Value &Value::back() const
{
	return array().back();
}

inline const Value &Value::push_front(const Value &v) const
{
	array().push_front(v);

	return *this;
}

inline const Value &Value::push_back(const Value &v) const
{
	array().push_back(v);

	return *this;
}

inline Value Value::pop_front() const
{
	Value r = front();
	array().pop_front();
	return r;
}

inline Value Value::pop_back() const
{
	Value r = back();
	array().pop_back();
	return r;
}

// object
template <typename T>
inline Value::Value(const std::map<std::string, T> &v) : value(newObject())
{
	Object &o = object();

	for (typename std::map<std::string, T>::const_iterator I = v.begin(); I != v.end(); ++I) {
		o.insert(std::make_pair(I->first, I->second));
	}
}

template <typename T>
inline Value &Value::operator=(const std::map<std::string, T> &v)
{
	value = newObject();
	Object &o = object();

	for (typename std::map<std::string, T>::const_iterator I = v.begin(); I != v.end(); ++I) {
		o.insert(std::make_pair(I->first, I->second));
	}

	return *this;
}

inline Value::Object &Value::object() const
{
	return value->object();
}

inline Value &Value::operator[](const std::string &f) const
{
	return object()[f];
}

inline Value &Value::operator[](const char *f) const
{
	return object()[std::string(f)];
}

inline size_t Value::erase(const std::string &f) const
{
	return object().erase(f);
}

inline size_t Value::erase(const char *f) const
{
	return object().erase(std::string(f));
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
VALUE_COMPARE(unsigned, getUInt)
VALUE_COMPARE(long long, getLong)
VALUE_COMPARE(unsigned long long, getULong)
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

inline Value Array(size_t n = 0)
{
	return Value::newArray(n);
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
