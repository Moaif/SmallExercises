#include <iostream>
#include "Rational.h"
#include "RationalTemplated.h"

using namespace std;
void TestRational();
void TestRationalTemplated();

int main()
{
	//TestRational();
	TestRationalTemplated();

	return 0;
}

void TestRational()
{
	Rational r1 = Rational(1, 2);
	Rational result;

	result = 2 * r1;
	cout << result.ToString() << endl;
	system("pause");

	result = r1 * 2;
	cout << result.ToString() << endl;
	system("pause");

	result = r1 - 2.2;
	cout << result.ToString() << endl;
	system("pause");

	result = r1 + 2 / 4;
	cout << result.ToString() << endl;
	system("pause");

	result = r1 / 2.2f;
	cout << result.ToString() << endl;
	system("pause");

	result = r1 + Rational(2, 3);
	cout << result.ToString() << endl;
	system("pause");
}

void TestRationalTemplated()
{
	RationalTemplated<int> r1 = RationalTemplated<int>(1,2);
	RationalTemplated<float> result;

	result = 2 * r1;
	cout << result.ToString() << endl;
	system("pause");

	result = r1 * 2;
	cout << result.ToString() << endl;
	system("pause");

	result = r1 - 2.2;
	cout << result.ToString() << endl;
	system("pause");

	result = r1 + 2 / 4;
	cout << result.ToString() << endl;
	system("pause");

	result = r1 / 2.2f;
	cout << result.ToString() << endl;
	system("pause");

	//I want to know how to do this, currently I'm having a problem cause
	//more than 1 operator can be used for this, as the int can be cast to double
	// and the double to int, so both operators will match and dont know how to solve it
	/*result = r1 + RationalTemplated<double>(2, 3);
	cout << result.ToString() << endl;
	system("pause");*/
}