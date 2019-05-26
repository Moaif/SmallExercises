#include "SubscriptionWrapper.h"

int SubscriptionWrapper::counter = 0;

SubscriptionWrapper::SubscriptionWrapper(): m_ID(0)
{}

SubscriptionWrapper::SubscriptionWrapper(const std::function<void()>& f):m_Funct(f)
{
	m_ID = ++SubscriptionWrapper::counter;
}
void SubscriptionWrapper::operator=(const SubscriptionWrapper & wrapper)
{
	if(m_Funct == nullptr)
	{
		m_Funct = wrapper.GetFunct();
		m_ID = ++SubscriptionWrapper::counter;
	}
	else
	{
		std::cerr << "You can not assign to an already assigned SubscriptionWrapper" << std::endl;
	}
}
