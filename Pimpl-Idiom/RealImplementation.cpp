#include "RealImplementation.h"
#include <string>

RealImplementation::RealImplementation(const std::string& text, float value)
{
	m_Object = RandomObject(text, value);
}

void RealImplementation::AddText(const std::string& string)
{
	m_Object.m_Text = m_Object.m_Text + string;
}

void RealImplementation::ClearText()
{
	m_Object.m_Text.clear();
}

float RealImplementation::operator*(float op)
{
	return m_Object.m_Value * op;
}

float RealImplementation::operator-(float op)
{
	return m_Object.m_Value - op;
}

float RealImplementation::operator+(float op)
{
	return m_Object.m_Value + op;
}

float RealImplementation::operator/(float op)
{
	return m_Object.m_Value / op;
}

float RealImplementation::operator=(float value)
{
	return m_Object.m_Value= value;
}

std::string RealImplementation::ToString() const
{
	return m_Object.m_Text + std::to_string(static_cast<int>(m_Object.m_Value));
}
