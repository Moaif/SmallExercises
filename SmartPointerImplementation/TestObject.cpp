#include "TestObject.h"
#include <iostream>

TestObject::TestObject()
{}

TestObject::TestObject(int value):value(value)
{}

void TestObject::DoSomething()
{
	std::cout << "Doing something" << std::endl;
}

void TestObject::DoSomethingConst() const
{
	std::cout << "Doing something const" << std::endl;
}

int TestObject::GetInt() const
{
	return value;
}
