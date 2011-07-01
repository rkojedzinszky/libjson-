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

	// converter functions
	bool asBool() const;
	int asInt() const;
	long long asLong() const;
	double asDouble() const;
	std::string asString() const;

	bool operator==(const IValue &r) const;
	bool operator<(const IValue &r) const;
	bool operator<=(const IValue &r) const;

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);
};

inline IString::IString(const std::string &s) : value(s)
{
}

}; // namespace JSON

#endif
