#pragma once
#include <string>

class RandomObject
{
public:
	RandomObject(){};
	RandomObject(const std::string& text, float value):text(text),value(value){};
public:
	std::string text;
	float value;
};