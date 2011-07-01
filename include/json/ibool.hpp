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

	// converter functions
	bool asBool() const;
	int asInt() const;
	long long asLong() const;

	bool operator==(const IValue &r) const;

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);
};

inline IBool::IBool(bool v) : value(v)
{
}

}; // namespace JSON

#endif

