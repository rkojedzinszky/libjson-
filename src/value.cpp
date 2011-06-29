#include <json/value.hpp>
#include <json/util.hpp>

#include <json/ibool.hpp>
#include <json/inumeric.hpp>
#include <json/istring.hpp>
#include <json/iarray.hpp>
#include <json/iobject.hpp>

namespace JSON
{

// boolean
Value::Value(bool v) : value(new IBool(v))
{
}

Value &Value::setBool(bool v)
{
	value = new IBool(v);

	return *this;
}

// numeric
Value::Value(int v) : value(new INumeric(static_cast<double>(v)))
{
}

Value &Value::setInt(int v)
{
	value = new INumeric(static_cast<double>(v));

	return *this;
}

Value::Value(long long v) : value(new INumeric(v))
{
}

Value &Value::setLong(long long v)
{
	value = new INumeric(v);

	return *this;
}

Value::Value(double v) : value(new INumeric(v))
{
}

Value &Value::setDouble(double v)
{
	value = new INumeric(v);

	return *this;
}

// string
Value::Value(const std::string &s) : value(new IString(s))
{
}

Value &Value::setString(const std::string &s)
{
	value = new IString(s);

	return *this;
}

Value::Value(const char *s) : value(new IString(s))
{
}

Value &Value::setString(const char *s)
{
	value = new IString(s);

	return *this;
}

Value &Value::fromStream(std::istream &i)
{
	i >> std::ws;

	switch (speek(i)) {
	case '\"':
		value = new IString();
		break;
	case '-':
	case '+':
	case '0' ... '9':
		value = new INumeric();
		break;
	case '[':
		value = new IArray();
		break;
	case '{':
		value = new IObject();
		break;
	case 't':
	case 'f':
		value = new IBool();
		break;
	case 'n':
		value = new IValue();
		break;
	default:
		throw ParserError(i.peek());
		break;
	}

	value->fromStream(i);

	return *this;
}

Value Array()
{
	return Value(new IArray());
}

Value Object()
{
	return Value(new IObject());
}

}; // namespace JSON
