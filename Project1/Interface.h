#pragma once
#include <memory>
#include <string>

class RealImplementation;

class Interface
{
public:
	Interface(const std::string& text = "",float value = 0);
	~Interface();
	Interface(Interface&& interface);
	Interface& operator=(Interface&& interface);


	void AddText(const std::string& string);
	void ClearText();
	float operator*(float op);
	float operator-(float op);
	float operator+(float op);
	float operator/(float op);
	float operator=(float value);

	std::string ToString() const;

private:
	Interface(const Interface& interface){};
	Interface& operator=(const Interface& interface){};
private:
	std::unique_ptr<RealImplementation> pimpl;
};