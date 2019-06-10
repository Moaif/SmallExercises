#pragma once
#include <string>

class Rational
{
public:
	Rational(int numerator = 0, int denominator = 1) :numerator(numerator),denominator(denominator){};

	int GetNumerator() const{return numerator;};
	int GetDenominator() const{return denominator;};
	std::string ToString() const{return std::to_string(numerator) + " : " + std::to_string(denominator);};
private:
	int numerator;
	int denominator;
};

Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);