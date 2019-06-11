#include <iostream>
#include "Traits.h"
#include "RandomObject.h"
#include "MultiFile.h"

using namespace std;

int main(){
	int notPointer = 2;
	const char* pointer = "donal";
	RandomObject randomObject = RandomObject(1);
	RandomObject* pRandomObject = &randomObject;

	cout << "int value isPointer value: " << isPointer<decltype(notPointer)>::value << endl;
	cout << "const char* value isPointer value: " << isPointer<decltype(pointer)>::value << endl;
	cout << "RandomObject value isPointer value: " << isPointer<decltype(randomObject)>::value << endl;
	cout << "RandomObject* value isPointer value: " << isPointer<decltype(pRandomObject)>::value << endl;

	system("pause");

	A classA = A();
	B classB = B();
	C classC = C();

	DoSomething(classA);
	DoSomething(classB);
	DoSomething(classC);

	system("pause");

	return 0;
}