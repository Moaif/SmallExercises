#pragma once
#include <new>

struct NewHandlerObject
{
public:
	NewHandlerObject(std::new_handler handler) :handler(handler){};
	~NewHandlerObject()
	{
		std::set_new_handler(handler);
	};
private:

	NewHandlerObject(const NewHandlerObject& handlerObject){};
	NewHandlerObject* operator=(const NewHandlerObject& handlerObject){};

	std::new_handler handler;
};

class Object
{
public:
	static std::new_handler SetCurrentHandler(std::new_handler handler) throw();
	void* operator new(size_t size) throw(std::bad_alloc);
private:
	static std::new_handler currentHandler;
};
