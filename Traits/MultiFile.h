#pragma once
#include <iostream>
#include "Traits.h"

struct type_Basic{};
struct type_NonBasic{};
struct type_Basic_Derived :public type_Basic{};

template<typename T>
void DoSomething(const T& ref)
{
	RealDoSomething(ref, innerType_Traits<T>::inner_Type());
}

//Overloaded functions
template<typename T>
void RealDoSomething(const T& ref, type_Basic type)
{
	//do the specific for this type of object
	std::cout << "basic type overload called" << endl;
};

template<typename T>
void RealDoSomething(const T& ref, type_NonBasic type)
{
	//do the specific for this type of object
	std::cout << "non basic type overload called" << endl;
};

//Without this last overload, C class will enter the type_Basic one as is its best fit
//If un-commented it will enter in this overload

//template<typename T>
//void RealDoSomething(const T& ref, type_Basic_Derived type)
//{
//	//do the specific for this type of object
//	std::cout << "basic derived type overload called" << endl;
//};

class A
{
public:
	typedef type_Basic inner_Type;
};

class B
{
public:
	typedef type_NonBasic inner_Type;
};

class C
{
public:
	typedef type_Basic_Derived inner_Type;
};