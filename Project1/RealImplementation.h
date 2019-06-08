#pragma once
#include "RandomObject.h"

class RealImplementation
{
public:
	RealImplementation(const std::string& text, float value);

	void AddText(const std::string& string);
	void ClearText();
	float operator*(float op);
	float operator-(float op);
	float operator+(float op);
	float operator/(float op);
	float operator=(float value);

	std::string ToString() const;
private:
	RandomObject object;//this could be done with a reference and solve the problem, but want to do the pimpl Idiom
};