#pragma once
#include <string>

class Rational
{
public:
	Rational(int numerator = 0, int denominator = 1) :m_Numerator(numerator),m_Denominator(denominator){};

	int GetNumerator() const{return m_Numerator;};
	int GetDenominator() const{return m_Denominator;};
	std::string ToString() const{return std::to_string(m_Numerator) + " : " + std::to_string(m_Denominator);};
private:
	int m_Numerator;
	int m_Denominator;
};

Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);