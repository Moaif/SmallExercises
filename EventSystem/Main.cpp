
#include "SubscriptionWrapper.h"
#include "EventHelper.h"

int main()
{
	EventHelper::Init();//Ask how to remove this
	Event* event = new Event();
	const SubscriptionWrapper* sub1 = EventHelper::ListenToChannel(EventHelper::Channel::Basic,[](){std::cout << "\nsub1\n";});

	EventHelper::BroadCastAllChannels(*event);

	const SubscriptionWrapper* sub2 = EventHelper::ListenToChannel(EventHelper::Channel::Basic,[](){std::cout << "\nsub2\n";});
	const SubscriptionWrapper* sub3 = EventHelper::ListenToChannel(EventHelper::Channel::NotThatBasic,[](){std::cout << "\nsub3\n";});

	EventHelper::BroadCastAllChannels(*event);

	EventHelper::StopListeningToChannel(EventHelper::Channel::NotThatBasic, *sub1);//Should do nothing

	EventHelper::BroadCastAllChannels(*event);

 	EventHelper::StopListeningToChannel(EventHelper::Channel::Basic, *sub1);

	EventHelper::BroadCastAllChannels(*event);

	EventHelper::BroadCast(EventHelper::Channel::NotThatBasic, *event);

	return 0;
}