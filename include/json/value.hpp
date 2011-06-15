#ifndef JSON_VALUE_HPP
#define JSON_VALUE_HPP

#include <boost/intrusive_ptr.hpp>
#include <ostream>
#include <stdexcept>

#include <json/ivalue.hpp>

namespace JSON
{

class ParserError : public std::runtime_error {
	public:
		ParserError(const std::string &token) : std::runtime_error(std::string("JSON Parser error: unexpected token: ") + token) {
		}
};

void intrusive_ptr_add_ref(IValue *v);
void intrusive_ptr_release(IValue *v);

class Value
{
private:
	typedef boost::intrusive_ptr<IValue> valueType;
	valueType value;

protected:
	Value(IValue *v) : value(v) {
	}

public:
	Value() : value(new IValue()) {
	}

	Value(const Value &v) {
		operator=(v);
	}

	Value &operator=(const Value &v);

	// scalars
	bool isNull() const {
		return value->isNull();
	}

	// boolean
	Value(bool v) {
		operator=(v);
	}
	Value &operator=(bool v);
	operator bool() const {
		return value->operator bool();
	}

	// numeric
	Value(double v) {
		operator=(v);
	}
	Value &operator=(double v);
	Value(int v) {
		operator=((double)v);
	}
	Value &operator=(int v) {
		return operator=((double)v);
	}
	operator double() const {
		return value->operator double();
	}

	// string
	Value(const std::string &s) {
		operator=(s);
	}
	Value(const char *s) {
		operator=(s);
	}
	Value &operator=(const std::string &s);
	Value &operator=(const char *s) {
		return operator=(std::string(s));
	}
	operator const std::string&() const {
		return value->operator const std::string&();
	}

	// array
	Value &operator[](int idx) {
		return value->operator[](idx);
	}

	// hash
	Value &operator[](const std::string &f) {
		return value->operator[](f);
	}
	Value &operator[](const char *f) {
		return operator[](std::string(f));
	}

	// common to array & hash
	size_t size() const {
		return value->size();
	}

	// operators
	bool operator==(const Value &r) const {
		return value->operator==(*r.value);
	}
	bool operator!=(const Value &r) const {
		return !operator==(r);
	}
	bool operator<(const Value &r) const {
		return value->operator<(*r.value);
	}
	bool operator>(const Value &r) const {
		return r.operator<(*this);
	}
	bool operator<=(const Value &r) const {
		return value->operator<=(*r.value);
	}
	bool operator>=(const Value &r) const {
		return r.operator<=(*this);
	}

	friend Value Array();
	friend Value Hash();

	// serialization
	void toStream(std::ostream &o) const {
		value->toStream(o);
	}
	Value &fromStream(std::istream &i);
};

Value Array();
Value Hash();

}; // namespace JSON

static inline std::ostream &operator<<(std::ostream &o, JSON::Value &v)
{
	v.toStream(o);
	return o;
}

#endif
