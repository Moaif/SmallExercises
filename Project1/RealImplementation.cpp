#include "RealImplementation.h"
#include <string>

RealImplementation::RealImplementation(const std::string& text, float value)
{
	object = RandomObject(text, value);
}

void RealImplementation::AddText(const std::string& string)
{
	object.text = object.text + string;
}

void RealImplementation::ClearText()
{
	object.text.clear();
}

float RealImplementation::operator*(float op)
{
	return object.value * op;
}

float RealImplementation::operator-(float op)
{
	return object.value - op;
}

float RealImplementation::operator+(float op)
{
	return object.value + op;
}

float RealImplementation::operator/(float op)
{
	return object.value / op;
}

float RealImplementation::operator=(float value)
{
	return object.value= value;
}

std::string RealImplementation::ToString() const
{
	return object.text + std::to_string(static_cast<int>(object.value));
}
