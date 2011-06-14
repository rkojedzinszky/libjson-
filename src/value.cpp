#include <value.hpp>

#include <iscalar.hpp>
#include <ibool.hpp>
#include <inumeric.hpp>
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

// numeric
Value::Value(double v)
{
	operator=(v);
}

Value &Value::operator=(double v)
{
	value = valueType(new INumeric(v));

	return *this;
}

Value::Value(int v)
{
	operator=(static_cast<double>(v));
}

Value &Value::operator=(int v)
{
	return operator=(static_cast<double>(v));
}

Value::operator double() const
{
	return value->operator double();
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

Value &Value::fromStream(std::istream &i)
{
	i >> std::ws;

	IValue *v;

	switch (i.peek()) {
	case '\"':
		v = new IString();
		break;
	case '-':
	case '+':
	case '0' ... '9':
		v = new INumeric();
		break;
	case '[':
		v = new IArray();
		break;
	case '{':
		v = new IHash();
		break;
	case 't':
	case 'f':
		v = new IBool();
		break;
	case 'n':
		v = new IValue();
		break;
	default:
		std::string token;
		token = (char)i.peek();
		throw ParserError(token);
		break;
	}

	value = valueType(v);

	value->fromStream(i);

	return *this;
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
