#ifndef JSON_ISTRING_HPP
#define JSON_ISTRING_HPP

#include <iscalar.hpp>

namespace JSON
{

class IString : public IScalar
{
private:
	std::string value;

public:
	IString(const std::string &s = "");
	operator const std::string&() const;

	bool operator==(const IValue &r) const;
	bool operator<(const IValue &r) const;
	bool operator<=(const IValue &r) const;

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);

	IScalar *clone() const;
};

}; // namespace JSON

#endif
