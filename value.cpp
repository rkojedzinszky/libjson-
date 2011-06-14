#include <value.hpp>

#include <iscalar.hpp>
#include <ibool.hpp>
#include <iinteger.hpp>
#include <istring.hpp>
#include <iarray.hpp>
#include <ihash.hpp>

namespace JSON
{

Value::Value(IValue *v) : value(v)
{
}

Value::Value() : value(new IValue())
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
		value = valueType(s->clone());
	}

	return *this;
}

// scalars
bool Value::isNull() const throw ()
{
	return value->isNull();
}

Value::operator bool() const throw (std::bad_cast)
{
	return value->operator bool();
}

// boolean
Value::Value(bool v)
{
	operator=(v);
}

Value &Value::operator=(bool v)
{
	value = valueType(new IBool(v));

	return *this;
}

// integer
Value::Value(int v)
{
	operator=(v);
}

Value &Value::operator=(int v)
{
	value = valueType(new IInteger(v));

	return *this;
}

Value::operator int() const throw(std::bad_cast)
{
	return value->operator int();
}

// string
Value::Value(const std::string &s)
{
	operator=(s);
}

Value::Value(const char *s)
{
	operator=(s);
}

Value &Value::operator=(const std::string &s)
{
	value = valueType(new IString(s));

	return *this;
}

Value &Value::operator=(const char *s)
{
	return operator=(std::string(s));
}

Value::operator std::string() const throw (std::bad_cast)
{
	return value->operator std::string();
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

Value Hash()
{
	return Value(new IHash());
}

}; // namespace JSON
