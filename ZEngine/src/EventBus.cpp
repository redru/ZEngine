#include "EventBus.h"

int zng::EventBus::initialize() {
	subscribers[message::GRAPHICS] = Subscribers(20);

	return zng::OK;
}

int zng::EventBus::subscribe(unsigned short int type, std::function<void(zng::Message&)> onMessage) {
	Subscribers& subs(subscribers[type]);

	for (Subscribers::iterator it = subs.begin(); it != subs.end(); it++) {
		if (*it == NULL) {
			*it = onMessage;
			return zng::OK;
		}
	}

	return zng::KO;
}

void zng::EventBus::publish(zng::Message& message) {

	Subscribers& subs(subscribers[message.getType()]);

	for (Subscribers::iterator it = subs.begin(); it != subs.end(); it++) {
		if (*it != NULL) {
			(*it)(message);
		}
	}
}
