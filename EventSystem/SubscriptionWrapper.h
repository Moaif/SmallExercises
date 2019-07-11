#pragma once

#include <functional>
#include <iostream>

class SubscriptionWrapper
{
public:
	SubscriptionWrapper();
	SubscriptionWrapper(const std::function<void()>& f);

	int GetID()const {return m_ID;};
	std::function<void()> GetFunct() const{return m_Funct;};


	void operator()() { m_Funct(); };
	void operator=(const SubscriptionWrapper& wrapper);
	bool operator==(const SubscriptionWrapper& wrapper){return m_ID == wrapper.GetID();}
	bool operator!=(nullptr_t){return m_Funct != nullptr;}
public:
	static int counter;
private:
	unsigned m_ID;
	std::function<void()> m_Funct;
};