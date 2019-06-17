#include "Object.h"

std::new_handler Object::currentHandler = 0;

std::new_handler Object::SetCurrentHandler(std::new_handler handler) throw()
{
	std::new_handler ret = currentHandler;
	currentHandler = handler;
	return ret;
}

void * Object::operator new(size_t size) throw(std::bad_alloc)
{
	NewHandlerObject handlerObject(std::set_new_handler(currentHandler));
	return ::operator new(size);
}
