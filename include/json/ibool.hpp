#ifndef JSON_IBOOL_HPP
#define JSON_IBOOL_HPP

#include <json/iscalar.hpp>

namespace JSON
{

class IBool : public IScalar
{
private:
	bool value;

public:
	IBool(bool v = false);
	bool getBool() const;

	// return type info
	Type type() const;

	// clone
	IBool* clone() const;

	// converter functions
	bool asBool() const;
	int asInt() const;
	unsigned asUInt() const;
	long long asLong() const;
	unsigned long long asULong() const;
	std::string asString() const;

	bool operator==(const IValue& r) const;

	void toStream(std::ostream& o) const;
	void fromStream(std::istream& i);
};

inline IBool::IBool(bool v) : value(v)
{
}

}; // namespace JSON

#endif

