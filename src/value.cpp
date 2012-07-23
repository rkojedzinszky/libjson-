#include <json/value.hpp>
#include <json/util.hpp>
#include <json/iarray.hpp>
#include <json/iobject.hpp>

namespace JSON
{

Value &Value::fromStream(std::istream &i)
{
	i >> std::ws;

	switch (speek(i)) {
	case '\"':
		value = IString::fromStream(i);
		break;
	case '-':
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
		value = INumeric::fromStream(i);
		break;
	case '[':
		value = IArray::fromStream(i);
		break;
	case '{':
		value = IObject::fromStream(i);
		break;
	case 't':
	case 'f':
		value = IBool::fromStream(i);
		break;
	case 'n':
		value = IValue::fromStream(i);
		break;
	default:
		throw ParserError(i.peek());
		break;
	}

	return *this;
}

IValue *Value::newArray(size_t n)
{
	return new IArray(n);
}

IValue *Value::newObject()
{
	return new IObject();
}


}; // namespace JSON
