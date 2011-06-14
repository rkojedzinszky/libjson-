#ifndef JSON_IINTEGER_HPP
#define JSON_IINTEGER_HPP

#include <iscalar.hpp>

namespace JSON
{

class IInteger : public IScalar
{
private:
	int value;

public:
	IInteger(int v = 0);
	operator int() const;

	bool operator==(const IValue &r) const;
	bool operator<(const IValue &r) const;
	bool operator<=(const IValue &r) const;

	void toStream(std::ostream &o) const;

	IScalar *clone() const;
};

}; // namespace JSON

#endif
