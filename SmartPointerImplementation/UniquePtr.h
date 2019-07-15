#pragma once
#include <string>

template<typename Type>
class UniquePtr
{
public:
	UniquePtr():ptr(nullptr){};
	explicit UniquePtr(Type * value):ptr(value){};

	UniquePtr(UniquePtr<Type>&& toMove)
	{
		if(this != &toMove)
		{
			delete ptr;
			ptr = toMove.ptr;
			toMove.ptr = nullptr;
		}
	};

	~UniquePtr()
	{
		delete ptr;
		ptr = nullptr;
	};

	UniquePtr& operator=(UniquePtr<Type>&& toMove)
	{
		if(this != &toMove)
		{
			delete ptr;
			ptr = toMove.ptr;
			toMove.ptr = nullptr;
		}

		return *this;
	};

	Type& operator*(){return *ptr;};
	const Type& operator*()const{return *ptr;};
	Type* operator->(){return ptr;};
	const Type* operator->()const{return ptr;};
	//operator bool(){return ptr == nullptr;}; this breaks the type conversion, and allow checks that should not be posibles
	bool isNullptr(){return ptr == nullptr;};
	Type* get(){return ptr;};
	const Type* get() const{return ptr;};

private:
	UniquePtr(const UniquePtr<Type>& toCopy){};
	UniquePtr& operator=(const UniquePtr<Type>& toCopy){};

private:
	Type* ptr;
};

//As i dont want the equality operators to construct new UniquePtr, i cant use type conversion, so i had to make all permutations
template<typename Type>
inline bool operator!=(const UniquePtr<Type>& current, const UniquePtr<Type>& other)
{
	return current.get() != other.get();
}
template<typename Type>
inline bool operator==(const UniquePtr<Type>& current, const UniquePtr<Type>& other)
{
	return current.get() == other.get();
}
template<typename Type>
inline bool operator!=(const UniquePtr<Type>& current, const Type* other)
{
	return current.get() != other;
}
template<typename Type>
inline bool operator==(const UniquePtr<Type>& current, const Type* other)
{
	return current.get() == other;
}
template<typename Type>
inline bool operator!=(const Type* other, const UniquePtr<Type>& current)
{
	return current.get() != other;
}
template<typename Type>
inline bool operator==(const Type* other, const UniquePtr<Type>& current)
{
	return current.get() == other;
}

//Nullptr cases
template<typename Type>
inline bool operator!=(const UniquePtr<Type>& current, nullptr_t)
{
	return current.get() != nullptr;
}
template<typename Type>
inline bool operator==(const UniquePtr<Type>& current, nullptr_t)
{
	return current.get() == nullptr;
}
template<typename Type>
inline bool operator!=(nullptr_t, const UniquePtr<Type>& current)
{
	return current.get() != nullptr;
}
template<typename Type>
inline bool operator==(nullptr_t, const UniquePtr<Type>& current)
{
	return current.get() == nullptr;
}