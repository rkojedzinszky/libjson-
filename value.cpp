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
bool Value::isNull() const
{
	return value->isNull();
}

Value::operator bool() const
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

Value::operator int() const
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

Value::operator const std::string&() const
{
	return value->operator const std::string&();
}

// array
Value &Value::operator[](int idx)
{
	return value->operator[](idx);
}

// hash
Value &Value::operator[](const std::string &f)
{
	return value->operator[](f);
}

Value &Value::operator[](const char *f)
{
	return operator[](std::string(f));
}

// common to array & hash
size_t Value::size() const
{
	return value->size();
}

bool Value::operator==(const Value &r) const
{
	return value->operator==(*r.value);
}

bool Value::operator<(const Value &r) const
{
	return value->operator<(*r.value);
}

bool Value::operator<=(const Value &r) const
{
	return value->operator<=(*r.value);
}

void Value::toStream(std::ostream &o) const
{
	value->toStream(o);
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
