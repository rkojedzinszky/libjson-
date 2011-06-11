#ifndef IScalar_HPP
#define IScalar_HPP

#include <stdexcept>
#include <ivalue.hpp>

namespace JSON
{

class nullValue : public std::runtime_error
{
public:
	nullValue();
};

class IScalar : public IValue
{
private:
	bool null;
	std::string value;

public:
	IScalar();
	IScalar(const std::string &s);
	IScalar(const IScalar &s);

	const std::string &str() const throw (nullValue);
	bool isNull() const throw ();
};

}; // namespace JSON

#endif
