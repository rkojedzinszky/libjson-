#ifndef JSON_INUMERIC_HPP
#define JSON_INUMERIC_HPP

#include <sstream>
#include <stdexcept>

#include <json/iscalar.hpp>

namespace JSON
{

class INumeric : public IScalar
{
private:
	double value;

	template <typename F, typename T>
	static bool numbers_equal(volatile F &f, T t);

	template <typename T>
	T get() const;

public:
	INumeric(double v);
	template <typename T>
	INumeric(T v);
	int getInt() const;
	unsigned getUInt() const;
	long long getLong() const;
	unsigned long long getULong() const;
	double getDouble() const;

	// converter functions
	bool asBool() const;
	int asInt() const;
	unsigned asUInt() const;
	long long asLong() const;
	unsigned long long asULong() const;
	double asDouble() const;
	std::string asString() const;

	bool operator==(const IValue &r) const;
	bool operator<(const IValue &r) const;
	bool operator<=(const IValue &r) const;

	void toStream(std::ostream &o) const;
	void fromStream(std::istream &i);
};

template <typename F, typename T>
inline bool INumeric::numbers_equal(volatile F &f, T t)
{
	return static_cast<T>(f) == t;
}

inline INumeric::INumeric(double v) : value(v)
{
}

template <typename T>
INumeric::INumeric(T v) : value(static_cast<double>(v))
{
	if (!numbers_equal(value, v)) {
		std::ostringstream o;
		o.precision(20);
		o << __PRETTY_FUNCTION__ << ": " << v << " cannot be stored without loss";
		throw std::domain_error(o.str());
	}
}

}; // namespace JSON

#endif
