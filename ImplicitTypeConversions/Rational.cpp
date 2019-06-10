#include "Rational.h"
#include "SupportFunctions.h"

Rational operator+(const Rational & a, const Rational & b)
{
	int mcmDenominator = mcm(a.GetDenominator(),b.GetDenominator());
	int aNumerator = a.GetNumerator() * (mcmDenominator/a.GetDenominator());
	int bNumerator = b.GetNumerator() * (mcmDenominator/b.GetDenominator());
	return Rational(aNumerator + bNumerator,mcmDenominator);
}

Rational operator-(const Rational & a, const Rational & b)
{
	int mcmDenominator = mcm(a.GetDenominator(), b.GetDenominator());
	int aNumerator = a.GetNumerator() * (mcmDenominator / a.GetDenominator());
	int bNumerator = b.GetNumerator() * (mcmDenominator / b.GetDenominator());
	return Rational(aNumerator - bNumerator, mcmDenominator);
}

Rational operator*(const Rational & a, const Rational & b)
{
	return Rational(a.GetNumerator() * b.GetNumerator(), a.GetDenominator() * b.GetDenominator());
}

Rational operator/(const Rational & a, const Rational & b)
{
	return Rational(a.GetNumerator() * b.GetDenominator(), a.GetDenominator() * b.GetNumerator());
}
