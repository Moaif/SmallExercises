#pragma once
#include "SupportFunctions.h"

template<typename T>
class RationalTemplated
{
public:
	RationalTemplated(T numerator = 0, T denominator = 1):numerator(numerator),denominator(denominator){};
	template<typename U>
	RationalTemplated(const RationalTemplated<U>& a):numerator(a.GetNumerator()),denominator(a.GetDenominator()){};
	template<typename U>
	RationalTemplated<T>& operator=(const RationalTemplated<U>& a)
	{
		numerator = a.GetNumerator();
		denominator = a.GetDenominator();
		return *this;
	}

	T GetNumerator() const{return numerator;};
	T GetDenominator() const{return denominator;};
	std::string ToString() const {return std::to_string(numerator) + " : " + std::to_string(denominator);};

	friend RationalTemplated<T> operator+(const RationalTemplated<T>& a, const RationalTemplated<T>& b)
	{
		return DoSum(a,b);
	};
	friend RationalTemplated<T> operator-(const RationalTemplated<T>& a, const RationalTemplated<T>& b)
	{
		return DoSubstract(a,b);
	};
	friend RationalTemplated<T> operator*(const RationalTemplated<T>& a, const RationalTemplated<T>& b)
	{
		return DoMult(a,b);
	};
	friend RationalTemplated<T> operator/(const RationalTemplated<T>& a, const RationalTemplated<T>& b)
	{
		return DoDiv(a,b);
	};

private:
	T numerator;
	T denominator;
};

template<typename T>
RationalTemplated<T> DoSum(const RationalTemplated<T>& a, const RationalTemplated<T>& b)
{
	int mcmDenominator = mcm(a.GetDenominator(), b.GetDenominator());
	int aNumerator = a.GetNumerator() * (mcmDenominator / a.GetDenominator());
	int bNumerator = b.GetNumerator() * (mcmDenominator / b.GetDenominator());
	return RationalTemplated<T>(aNumerator + bNumerator, mcmDenominator);
};
template<typename T>
RationalTemplated<T> DoSubstract(const RationalTemplated<T>& a, const RationalTemplated<T>& b)
{
	int mcmDenominator = mcm(a.GetDenominator(), b.GetDenominator());
	int aNumerator = a.GetNumerator() * (mcmDenominator / a.GetDenominator());
	int bNumerator = b.GetNumerator() * (mcmDenominator / b.GetDenominator());
	return RationalTemplated<T>(aNumerator - bNumerator, mcmDenominator);
};
template<typename T>
RationalTemplated<T> DoMult(const RationalTemplated<T>& a, const RationalTemplated<T>& b)
{
	return RationalTemplated<T>(a.GetNumerator() * b.GetNumerator(), a.GetDenominator() * b.GetDenominator());
};
template<typename T>
RationalTemplated<T> DoDiv(const RationalTemplated<T>& a, const RationalTemplated<T>& b)
{
	return RationalTemplated<T>(a.GetNumerator() * b.GetDenominator(), a.GetDenominator() * b.GetNumerator());
};