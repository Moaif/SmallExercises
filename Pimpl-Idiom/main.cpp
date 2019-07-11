#include "Interface.h"
#include "RealImplementation.h"
#include <iostream>

using namespace std;

int main()
{
	Interface i1 = Interface("test",1);

	cout << i1.ToString() << endl;
	system("pause");

	//Interface i2 = Interface(i1); //dont work, which is fine

	Interface i2(move(i1));
	i2.ClearText();
	i2.AddText("i2");

	cout << i1.ToString() << endl;
	cout << i2.ToString() << endl;
	system("pause");

	i1 = move(i2);
	i1.AddText(" not anymore ");
	i1 = 22;

	cout << i1.ToString() << endl;
	cout << i2.ToString() << endl;
	system("pause");

	i2 = Interface("i2",33);
	i2 = i2 - 3;

	cout << i1.ToString() << endl;
	cout << i2.ToString() << endl;
	system("pause");

	Interface i3 = Interface();

	cout << i3.ToString() << endl;
	system("pause");

	i3.ClearText();

	cout << i3.ToString() << endl;
	system("pause");

	return 0;
}