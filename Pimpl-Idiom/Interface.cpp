#include "Interface.h"
#include "RealImplementation.h"

Interface::Interface(const std::string& text, float value):m_Pimpl(std::make_unique<RealImplementation>(text, value))
{
}

Interface::~Interface()
{
}

Interface::Interface(Interface&& interface):m_Pimpl(std::move(interface.m_Pimpl))
{
}

Interface& Interface::operator=(Interface&& interface)
{
	if(this != &interface)
	{
		m_Pimpl = std::move(interface.m_Pimpl);
	}
	return *this;
}

void Interface::AddText(const std::string& string)
{
	if(m_Pimpl)
	{
		m_Pimpl->AddText(string);
	}
}

void Interface::ClearText()
{
	if(m_Pimpl)
	{
		m_Pimpl->ClearText();
	}
}

float Interface::operator*(float op)
{
	if(m_Pimpl)
	{
		return m_Pimpl->operator*(op);
	}
	return -1;
}

float Interface::operator-(float op)
{
	if(m_Pimpl)
	{
		return m_Pimpl->operator-(op);
	}
	return -1;
}

float Interface::operator+(float op)
{
	if(m_Pimpl)
	{
		return m_Pimpl->operator+(op);
	}
	return -1;
}

float Interface::operator/(float op)
{
	if(m_Pimpl)
	{
		return m_Pimpl->operator/(op);
	}
	return -1;
}

float Interface::operator=(float value)
{
	if(m_Pimpl)
	{
		return m_Pimpl->operator=(value);
	}
	return 0;
}

std::string Interface::ToString() const
{
	if(m_Pimpl)
	{
		return m_Pimpl->ToString();
	}
	return "null pimpl";
}
