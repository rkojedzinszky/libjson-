#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <stdexcept>
#include "base.hpp"

class nullValue : public std::runtime_error {
	public:
		nullValue();
};

class Scalar : public ValueBase {
	private:
		bool null;
		std::string value;

	public:
		Scalar();
		Scalar(const std::string &s);
		Scalar(const Scalar &s);

		const std::string &str() const throw (nullValue);
		bool isNull() const throw ();
};

#endif
