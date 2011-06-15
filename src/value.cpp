#include <json/value.hpp>

#include <json/iscalar.hpp>
#include <json/ibool.hpp>
#include <json/inumeric.hpp>
#include <json/istring.hpp>
#include <json/iarray.hpp>
#include <json/ihash.hpp>

namespace JSON
{

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

// boolean
Value &Value::operator=(bool v)
{
	value = valueType(new IBool(v));

	return *this;
}

// numeric
Value &Value::operator=(double v)
{
	value = valueType(new INumeric(v));

	return *this;
}

// string
Value &Value::operator=(const std::string &s)
{
	value = valueType(new IString(s));

	return *this;
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
