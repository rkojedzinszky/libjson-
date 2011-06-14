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
	operator const std::string&() const throw ();

	bool operator==(const IValue &r) const throw (std::bad_cast);
	bool operator<(const IValue &r) const throw (std::bad_cast);
	bool operator<=(const IValue &r) const throw (std::bad_cast);

	void toStream(std::ostream &o) const;

	IScalar *clone() const;
};

}; // namespace JSON

#endif
