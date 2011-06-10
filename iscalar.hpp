#ifndef IScalar_HPP
#define IScalar_HPP

#include <stdexcept>

class nullValue : public std::runtime_error {
	public:
		nullValue();
};

class IScalar : public ValueBase {
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

#endif
