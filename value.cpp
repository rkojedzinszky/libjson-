#include "scalar.hpp"
#include "value.hpp"
#include "base.hpp"

Value::Value() : value(new Scalar())
{
}

Value::Value(const Value &v)
{
	operator=(v);
}

Value::Value(const std::string &s)
{
	operator=(s);
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

Value &Value::operator=(const std::string &s)
{
	value = valueType(new Scalar(s));

	return *this;
}

const std::string &Value::str() const throw (std::runtime_error)
{
	return value->str();
}

bool Value::isNull() const throw (std::bad_cast)
{
	return value->isNull();
}

Value &Value::operator[](int idx) throw (std::bad_cast)
{
	return value->operator[](idx);
}

Value &Value::operator[](const std::string &f) throw (std::bad_cast)
{
	return value->operator[](f);
}
