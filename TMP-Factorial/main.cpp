#include<iostream>
#include "Factorial.h"

using namespace std;

int main()
{
	cout << "Factorial of 5: " << Factorial<5>::value << endl;

	cout << "Factorial of 12: " << Factorial<12>::value << endl;

	cout << "Factorial of 0: " << Factorial<0>::value << endl;

	//cout << "Factorial of -5: " << Factorial<-5>::value << endl;  it works, but it takes the max int value -5, and it's to complex for the compilation so it breaks

	system("pause");

	return 0;
}