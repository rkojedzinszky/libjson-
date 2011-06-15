#include <json/value.hpp>

namespace JSON
{

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

	value = v;

	value->fromStream(i);

	return *this;
}

}; // namespace JSON
