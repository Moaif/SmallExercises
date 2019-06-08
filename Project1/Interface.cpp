#include "Interface.h"
#include "RealImplementation.h"

Interface::Interface(const std::string& text, float value):pimpl(std::make_unique<RealImplementation>(text, value))
{
}

Interface::~Interface()
{
}

Interface::Interface(Interface&& interface):pimpl(std::move(interface.pimpl))
{
}

Interface& Interface::operator=(Interface&& interface)
{
	if(this != &interface)
	{
		pimpl = std::move(interface.pimpl);
	}
	return *this;
}

void Interface::AddText(const std::string& string)
{
	if(pimpl)
	{
		pimpl->AddText(string);
	}
}

void Interface::ClearText()
{
	if(pimpl)
	{
		pimpl->ClearText();
	}
}

float Interface::operator*(float op)
{
	if(pimpl)
	{
		return pimpl->operator*(op);
	}
	return -1;
}

float Interface::operator-(float op)
{
	if(pimpl)
	{
		return pimpl->operator-(op);
	}
	return -1;
}

float Interface::operator+(float op)
{
	if(pimpl)
	{
		return pimpl->operator+(op);
	}
	return -1;
}

float Interface::operator/(float op)
{
	if(pimpl)
	{
		return pimpl->operator/(op);
	}
	return -1;
}

float Interface::operator=(float value)
{
	if(pimpl)
	{
		return pimpl->operator=(value);
	}
	return 0;
}

std::string Interface::ToString() const
{
	if(pimpl)
	{
		return pimpl->ToString();
	}
	return "null pimpl";
}
