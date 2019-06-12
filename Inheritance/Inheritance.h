#pragma once

class Base
{
public:
	virtual int PublicMethodBase();
	virtual int CallProtectedMethod();
	virtual int CallPrivateMethod();

	int x;
protected:
	virtual int ProtectedMethodBase();

	int y;
private:
	virtual int PrivateMethodBase();

	int z;
};

class A : public Base
{
public:
	virtual int PublicMethodBase() override;

protected:
	virtual int ProtectedMethodBase() override;

private:
	virtual int PrivateMethodBase() override; //Non virtual interface Idiom if the method that call this one is not virtual

	//x is public
	//y is protected
	//z is not accesible from this class
};

class B : protected Base
{
	//x is protected
	//y is protected
	//z is not accesible from this class
};

class C : private Base
{
public:
	int ImplementedInTermsOfBase();

	//x is private
	//y is private
	//z is not accesible from this class
};