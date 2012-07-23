#ifndef JSON_ISCALAR_HPP
#define JSON_ISCALAR_HPP

#include <json/ivalue.hpp>

namespace JSON
{

class IScalar : public IValue
{
public:
	// return type info
	Type type() const = 0;

	// serialization
	virtual void toStream(std::ostream &o) const = 0;
};

}; // namespace JSON

#endif
