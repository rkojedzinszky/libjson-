#ifndef JSON_INUMERIC_HPP
#define JSON_INUMERIC_HPP

#include <json/iscalar.hpp>

namespace JSON
{

class INumeric : public IScalar
{
private:
	double value;

public:
	INumeric(long long v = 0);
	INumeric(double v);
	int getInt() const;
	long long getLong() const;
	double getDouble() const;

	bool operator==(const IValue &r) const;
	bool operator<(const IValue &r) const;
	bool operator<=(const IValue &r) const;

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);

	IScalar *clone() const;
};

}; // namespace JSON

#endif
