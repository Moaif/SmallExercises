#pragma once


template<typename T>
struct isPointer
{
	static const bool value = false;
};

template<typename T>
struct isPointer<T*>
{
	static const bool value = true;
};

template<typename T>
struct innerType_Traits
{
	typedef typename T::inner_Type inner_Type;
};