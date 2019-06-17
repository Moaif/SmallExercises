#include <iostream>
#include "Object.h"

void OutOfMemory(){
	std::cerr << "Not memory available for allocation";
	std::abort();
}

int main()
{
	Object::SetCurrentHandler(OutOfMemory);

	Object* obj = new Object();


	return 0;
}