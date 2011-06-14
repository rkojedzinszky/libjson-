#ifndef JSON_VALUE_HPP
#define JSON_VALUE_HPP

#include <boost/intrusive_ptr.hpp>
#include <ostream>
#include <stdexcept>

namespace JSON
{

class ParserError : public std::runtime_error {
	public:
		ParserError(const std::string &token) : std::runtime_error(std::string("JSON Parser error: unexpected token: ") + token) {
		}
};

class IValue ;

void intrusive_ptr_add_ref(IValue *v);
void intrusive_ptr_release(IValue *v);

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

	// hash
	Value &operator[](const std::string &f);
	Value &operator[](const char *f);

	// common to array & hash
	size_t size() const;

	// operators
	bool operator==(const Value &r) const;
	bool operator!=(const Value &r) const {
		return !operator==(r);
	}
	bool operator<(const Value &r) const;
	bool operator>(const Value &r) const {
		return r.operator<(*this);
	}
	bool operator<=(const Value &r) const;
	bool operator>=(const Value &r) const {
		return r.operator<=(*this);
	}

	friend Value Array();
	friend Value Hash();

	// serialization
	void toStream(std::ostream &o) const;
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
