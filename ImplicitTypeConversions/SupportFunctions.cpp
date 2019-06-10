#include "SupportFunctions.h"
#include <algorithm>


int mcd(int a, int b)
{
	int mcd = 0;
	int num1 = std::max(a, b);
	int num2 = std::min(a, b);
	do
	{
		mcd = num2;
		num2 = num1 % num2;
		num1 = mcd;
	} while(num2 != 0);
	return mcd;
}

int mcm(int a, int b)
{
	int mcm = 0;
	int num1 = std::max(a, b);
	int num2 = std::min(a, b);
	mcm = (num1 / mcd(num1, num2))*num2;
	return mcm;
}