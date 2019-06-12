#include <iostream>
#include "Inheritance.h"

using namespace std;

int main()
{
	Base base = Base();

	cout << base.PublicMethodBase() << endl;
	cout << base.CallProtectedMethod() << endl;
	cout << base.CallPrivateMethod() << endl;

	system("pause");

	A a = A();
	B b = B();
	C c = C();

	cout << a.PublicMethodBase() << endl;
	cout << a.CallProtectedMethod() << endl;
	cout << a.CallPrivateMethod() << endl;

	cout << c.ImplementedInTermsOfBase() << endl;

	//b.PublicMethodBase(); not working, now the method is protected
	//c.PublicMethodBase(); not working, now the method is private

	system("pause");

	Base aBase = A();

	cout << a.PublicMethodBase() << endl;
	cout << a.CallProtectedMethod() << endl;
	cout << a.CallPrivateMethod() << endl;

	//Base b = B(); not working, no implicit conversion allowed
	//Base c = C(); 
	/*B* pb = &b;
	Base* b = dynamic_cast<Base*>(pb);*/ //Not working neither

	system("pause");

	return 0;
}