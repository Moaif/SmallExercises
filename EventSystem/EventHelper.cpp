#include "EventHelper.h"

std::vector<std::vector<std::unique_ptr<SubscriptionWrapper>>> EventHelper::m_Channels = std::vector<std::vector<std::unique_ptr<SubscriptionWrapper>>>();

void EventHelper::Init()
{
	for(int i = 0; i < static_cast<int>(EventHelper::Channel::Max)-1; ++i)
	{
		m_Channels.push_back(std::vector<std::unique_ptr<SubscriptionWrapper>>());
	}
}

void EventHelper::BroadCastAllChannels(const Event & event)
{
	std::vector<std::vector<std::unique_ptr<SubscriptionWrapper>>>::iterator it = m_Channels.begin();
	for(; it != m_Channels.end(); ++it)
	{
		std::vector<std::unique_ptr<SubscriptionWrapper>>::iterator it2 = (*it).begin();
		for(; it2 != (*it).end(); ++it2)
		if(*it2 && (*it2)->GetID() != 0)
		{
			(*(*it2))();
		}
	}
	system("pause");
}

void EventHelper::BroadCast(Channel channel, const Event & event)
{
	std::vector<std::unique_ptr<SubscriptionWrapper>>::iterator it = m_Channels[static_cast<int>(channel)].begin();
	for(; it != m_Channels[static_cast<int>(channel)].end(); ++it)
	{
		if(*it && (*it)->GetID() != 0)
		{
			(*(*it))();
		}
	}
	system("pause");
}

const SubscriptionWrapper * EventHelper::ListenToChannel(Channel channel,const std::function<void()>& f)
{
	std::unique_ptr<SubscriptionWrapper> pWrapper = std::make_unique<SubscriptionWrapper>(f);
	SubscriptionWrapper* ret = pWrapper.get();
	m_Channels[static_cast<int>(channel)].push_back(std::move(pWrapper));
	return ret;
}

void EventHelper::StopListeningToChannel(Channel channel, const SubscriptionWrapper & wrapper)
{
	std::vector<std::unique_ptr<SubscriptionWrapper>>::iterator it = m_Channels[static_cast<int>(channel)].begin();
	for(; it != m_Channels[static_cast<int>(channel)].end(); ++it)
	{
		if(*(*it) == wrapper)
		{
			m_Channels[static_cast<int>(channel)].erase(it);
			break;
		}
	}
}
