#include <json/value.hpp>
#include <json/util.hpp>

namespace JSON
{

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

}; // namespace JSON
