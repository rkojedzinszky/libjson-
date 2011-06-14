#ifndef JSON_ISCALAR_HPP
#define JSON_ISCALAR_HPP

#include <json/ivalue.hpp>

namespace JSON
{

class IScalar : public IValue
{
public:
	// scalars
	bool isNull() const;

	// common to array & hash
	size_t size() const;

	// serialization
	virtual void toStream(std::ostream &o) const = 0;
	virtual void fromStream(std::istream &i) = 0;

	// clone
	virtual IScalar *clone() const = 0;
};

}; // namespace JSON

#endif
