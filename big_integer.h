#pragma once

#include <vector>
#include <string>
#include <ostream>
#include <iomanip>
#include <sstream>
#include <cstdint>

class big_integer {
	static const int BASE = 1'000'000'000;

	std::vector<int> _digits;

	bool _is_negative;

	void _remove_leading_zeros();
	void _shift_right();

public:
	class divide_by_zero: public std::exception {
	};

	big_integer();
	big_integer(const big_integer&);
	big_integer (std::string);
	big_integer(signed char);
	big_integer(unsigned char);
	big_integer(signed short);
	big_integer(unsigned short);
	big_integer(signed int);
	big_integer(unsigned int);
	big_integer(signed long);
	big_integer(unsigned long);
	big_integer(signed long long);
	big_integer(unsigned long long);

	friend std::ostream& operator <<(std::ostream&, const big_integer&);
	operator std::string() const;
	const big_integer operator +() const;
	const big_integer operator -() const;
	const big_integer operator ++();
	const big_integer operator ++(int);
	const big_integer operator --();
	const big_integer operator --(int);
	friend bool operator ==(const big_integer&, const big_integer&);
	friend bool operator <(const big_integer&, const big_integer&);
	friend bool operator !=(const big_integer&, const big_integer&);
	friend bool operator <=(const big_integer&, const big_integer&);
	friend bool operator >(const big_integer&, const big_integer&);
	friend bool operator >=(const big_integer&, const big_integer&);
	friend const big_integer operator +(big_integer, const big_integer&);
	big_integer& operator +=(const big_integer&);
	friend const big_integer operator -(big_integer, const big_integer&);
	big_integer& operator -=(const big_integer&);
	friend const big_integer operator *(const big_integer&, const big_integer&);
	big_integer& operator *=(const big_integer&);
	friend const big_integer operator /(const big_integer&, const big_integer&);
	big_integer& operator /=(const big_integer&);
	friend const big_integer operator %(const big_integer&, const big_integer&);
	big_integer& operator %=(const big_integer&);

	bool odd() const;
	bool even() const;
	const big_integer pow(big_integer) const;

	std::string toBinary() const;
};
