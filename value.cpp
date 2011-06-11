#include <json.hpp>

namespace JSON
{

Value::Value() : value(new IScalar())
{
}

Value::Value(const Value &v)
{
	operator=(v);
}

Value &Value::operator=(const Value &v)
{
	IScalar *s = dynamic_cast<IScalar *>(v.value.get());
	if (s == NULL) {
		value = v.value;
	} else {
		value = valueType(new IScalar(*s));
	}

	return *this;
}

Value::Value(IArray *a) : value(a)
{
}

// scalar
Value::Value(const std::string &s)
{
	operator=(s);
}

Value &Value::operator=(const std::string &s)
{
	value = valueType(new IScalar(s));

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

// hash
Value &Value::operator[](const std::string &f) throw (std::bad_cast)
{
	return value->operator[](f);
}

// common to array & hash
size_t Value::size() const throw (std::bad_cast)
{
	return value->size();
}

// instantiators
Value Array()
{
	return Value(new IArray());
}

}; // namespace JSON
