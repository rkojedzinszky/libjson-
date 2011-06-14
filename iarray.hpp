#ifndef IARRAY_HPP
#define IARRAY_HPP

#include <vector>
#include <value.hpp>
#include <ivalue.hpp>

namespace JSON
{

class IArray : public IValue
{
private:
	std::vector<Value> value;
public:
	Value &operator[](int idx) throw ();
	size_t size() const throw();

	void toStream(std::ostream &o) const;
};

}; // namespace JSON

#endif
