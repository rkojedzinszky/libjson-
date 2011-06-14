#ifndef JSON_IBOOL_HPP
#define JSON_IBOOL_HPP

#include <iscalar.hpp>

namespace JSON
{

class IBool : public IScalar
{
private:
	bool value;

public:
	IBool(bool v = false);
	operator bool() const;

	bool operator==(const IValue &r) const;

	void toStream(std::ostream &o) const;

	IScalar *clone() const;
};

}; // namespace JSON

#endif

