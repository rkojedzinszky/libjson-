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
	INumeric(double v = 0);
	operator double() const;

	bool operator==(const IValue &r) const;
	bool operator<(const IValue &r) const;
	bool operator<=(const IValue &r) const;

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);

	IScalar *clone() const;
};

}; // namespace JSON

#endif
