#pragma once
#include <string>

class RandomObject
{
public:
	RandomObject(){};
	RandomObject(const std::string& text, float value):m_Text(text),m_Value(value){};
public:
	std::string m_Text;
	float m_Value;
};