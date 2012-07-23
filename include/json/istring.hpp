#ifndef JSON_ISTRING_HPP
#define JSON_ISTRING_HPP

#include <json/iscalar.hpp>

namespace JSON
{

class IString : public IScalar
{
private:
	std::string value;

public:
	IString(const std::string &s = "");
	const std::string &getString() const;

	// return type info
	Type type() const;

	// converter functions
	bool asBool() const;
	int asInt() const;
	unsigned asUInt() const;
	long long asLong() const;
	unsigned long long asULong() const;
	double asDouble() const;
	std::string asString() const;

	bool operator==(const IValue &r) const;
	bool operator<(const IValue &r) const;
	bool operator<=(const IValue &r) const;

	void toStream(std::ostream &o) const;
	static IString * fromStream(std::istream &i);
};

inline IString::IString(const std::string &s) : value(s)
{
}

}; // namespace JSON

#endif
