#include "scalar.hpp"
#include "array.hpp"
#include "value.hpp"
#include "base.hpp"

Value::Value() : value(new Scalar())
{
}

Value::Value(const Value &v)
{
	operator=(v);
}

Value &Value::operator=(const Value &v)
{
	Scalar *s = dynamic_cast<Scalar*>(v.value.get());
	if (s == NULL) {
		value = v.value;
	} else {
		value = valueType(new Scalar(*s));
	}

	return *this;
}

// scalar
Value::Value(const std::string &s)
{
	operator=(s);
}

Value &Value::operator=(const std::string &s)
{
	value = valueType(new Scalar(s));

	return *this;
}

const std::string &Value::str() const throw (std::exception)
{
	return value->str();
}

bool Value::isNull() const throw (std::bad_cast)
{
	return value->isNull();
}

// array
Value &Value::operator[](int idx) throw (std::bad_cast)
{
	return value->operator[](idx);
}

Value &Value::array()
{
	value = valueType(new Array());

	return *this;
}

// hash
Value &Value::operator[](const std::string &f) throw (std::bad_cast)
{
	return value->operator[](f);
}
