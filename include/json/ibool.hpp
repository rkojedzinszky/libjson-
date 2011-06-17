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

	bool operator==(const IValue &r) const;

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);

	IScalar *clone() const;
};

}; // namespace JSON

#endif

