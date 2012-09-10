#ifndef JSON_IFIXED_HPP
#define JSON_IFIXED_HPP

#include <sstream>
#include <stdexcept>
#include <typeinfo>

#include <json/inumeric.hpp>

namespace JSON
{

class IFixed : public INumeric
{
private:
	long long value;

public:
	IFixed(long long v);
	int getInt() const;
	unsigned getUInt() const;
	long long getLong() const;
	unsigned long long getULong() const;
	double getDouble() const;

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
};

inline IFixed::IFixed(long long v) : value(v)
{
}

}; // namespace JSON

#endif
