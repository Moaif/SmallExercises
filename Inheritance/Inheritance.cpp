#include "Inheritance.h"

int Base::PublicMethodBase()
{
	return 0;
}

int Base::CallProtectedMethod()
{
	return ProtectedMethodBase();
}

int Base::CallPrivateMethod()
{
	return PrivateMethodBase();
}

int Base::ProtectedMethodBase()
{
	return 0;
}

int Base::PrivateMethodBase()
{
	return 0;
}

int A::PublicMethodBase()
{
	return 1;
}

int A::ProtectedMethodBase()
{
	return 1;
}

int A::PrivateMethodBase()
{
	return 1;
}

int C::ImplementedInTermsOfBase()
{
	return PublicMethodBase();
}
