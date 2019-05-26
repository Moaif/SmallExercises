#pragma once

#include <vector>
#include <memory>
#include "SubscriptionWrapper.h"
#include "Event.h"

class EventHelper
{
public:
	enum class Channel
	{
		Basic,
		NotThatBasic,
		ThirdOne,
		Max
	};

public:
	static void Init();//Ask how to do this without init
	static void BroadCastAllChannels(const Event& event);
	static void BroadCast(Channel channel,const Event& event);
	static const SubscriptionWrapper* ListenToChannel(Channel channel,const std::function<void()>& f);
	static void StopListeningToChannel(Channel channel, const SubscriptionWrapper& wrapper);

private:
	static std::vector<std::vector<std::unique_ptr<SubscriptionWrapper>>> m_Channels;
};