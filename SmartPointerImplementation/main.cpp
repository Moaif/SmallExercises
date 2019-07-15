#include "UniquePtr.h"
#include "TestObject.h"
#include "TestObject2.h"
#include <iostream>

using namespace std;

int main()
{
	UniquePtr<int> ptr;
	UniquePtr<int> ptr2 = UniquePtr<int>(new int(2));
	UniquePtr<int> ptrNull = UniquePtr<int>(nullptr);

	cout << ptr.isNullptr() << endl;
	cout << ptr2.isNullptr() << endl;
	cout << ptrNull.isNullptr() << endl;

	system("pause");

	UniquePtr<int> ptr2New = move(ptr2);

	cout << ptr2.isNullptr() << endl;
	cout << ptr2New.isNullptr() << endl;

	system("pause");

	//It does not work, so its fine
	//UniquePtr ptrCopy = UniquePtr(ptr2);
	//UniquePtr ptrCopy2 = ptr2;

	int* p = new int(3);
	UniquePtr<int> ptr3 = UniquePtr<int>(p);
	delete p;//Can we prevent this?
	//Fine, not allowed
	//delete ptr3;

	if(ptrNull.isNullptr())
	{
		cout << "Entered in ptrNull" << endl;
		system("pause");
	}
	if(!ptrNull.isNullptr())
	{
		cout << "Entered in !ptrNull" << endl;
		system("pause");
	}
	if(ptrNull == nullptr)
	{
		cout << "Entered in ptrNull == nullptr" << endl;
		system("pause");
	}
	if(nullptr == ptrNull)
	{
		cout << "Entered in nullptr == ptrNull" << endl;
		system("pause");
	}
	if(ptrNull != nullptr)
	{
		cout << "Entered in ptrNull != nullptr" << endl;
		system("pause");
	}
	if(nullptr != ptrNull)
	{
		cout << "Entered in nullptr != ptrNull" << endl;
		system("pause");
	}

	if(ptrNull == ptr3)
	{
		cout << "Entered in ptrNull == ptr3" << endl;
		system("pause");
	}
	if(ptrNull != ptr3)
	{
		cout << "Entered in ptrNull != ptr3" << endl;
		system("pause");
	}

	UniquePtr<int> ptr4;
	int* p2 = new int(4);
	if(ptr4 == p2)
	{
		cout << "Entered in ptr4 == p2" << endl;
		system("pause");
	}
	if(ptr4 != p2)
	{
		cout << "Entered in ptr4 != p2" << endl;
		system("pause");
	}

	UniquePtr<TestObject> ptrObj;
	UniquePtr<TestObject> ptrObj2 = UniquePtr<TestObject>(new TestObject(2));
	UniquePtr<TestObject> ptrObjNull = UniquePtr <TestObject>();

	cout << ptrObj.isNullptr() << endl;
	cout << ptrObj2.isNullptr() << endl;
	cout << ptrObjNull.isNullptr() << endl;

	cout << ptrObj2->GetInt() << endl;

	system("pause");

	UniquePtr<TestObject> ptrOjb3 = move(ptrObj2);

	cout << ptrObj2.isNullptr() << endl;
	cout << ptrOjb3.isNullptr() << endl;

	cout << (*ptrOjb3).GetInt() << endl;

	ptrOjb3.get()->DoSomething();

	system("pause");
	
	//Not working, so its fine
	//ptr = move(ptrOjb3);
	//UniquePtr<TestObject2> ptrObject;
	//TestObject* obj = new TestObject();
	//UniquePtr<TestObject2> ptrObject2 = UniquePtr<TestObject2>(obj); fine
	/*if(ptrObject == ptrOjb3) fine
	{
	}
	if(ptrObject == obj)fine
	{
	}*/

	return 0;
}