#include <json/value.hpp>
#include <json/util.hpp>
#include <json/iarray.hpp>
#include <json/iobject.hpp>

namespace JSON
{

const Value Value::null_;

Value& Value::fromStream(std::istream& i)
{
	i >> std::ws;

	switch (speek(i)) {
	case '\"':
		value = new IString();
		break;
	case '-':
	case '+':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		value = new INumeric(0);
		break;
	case '[':
		value = new IArray(0);
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

IValue* Value::newArray(size_t n)
{
	return new IArray(n);
}

IValue* Value::newObject()
{
	return new IObject();
}


}; // namespace JSON
