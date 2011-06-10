#ifndef BASE_HPP
#define BASE_HPP

#include <stdexcept>

#include "value.hpp"

class ValueBase {
	public:
		int refcnt;
		ValueBase() : refcnt(0) { };
		virtual ~ValueBase();

		virtual const std::string &str() const throw (std::exception);
		virtual bool isNull() const throw (std::bad_cast);
		virtual Value &operator[](int idx) throw (std::bad_cast);
		virtual Value &operator[](const std::string &f) throw (std::bad_cast);
};

#endif
