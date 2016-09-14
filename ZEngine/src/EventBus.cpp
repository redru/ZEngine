#include "EventBus.h"

int zng::EventBus::initialize() {
	subscribers[message::GRAPHICS] = SUB(20);

	return zng::OK;
}

int zng::EventBus::subscribe(unsigned short int type, std::function<void(zng::Message&)> onMessage) {
	SUB& subs(subscribers[type]);

	for (SUB::iterator it = subs.begin(); it != subs.end(); it++) {
		if (*it == NULL) {
			*it = onMessage;
			return zng::OK;
		}
	}

	return zng::KO;
}

void zng::EventBus::publish(zng::Message& message) {

	SUB& subs(subscribers[message.getType()]);

	for (SUB::iterator it = subs.begin(); it != subs.end(); it++) {
		if (*it != NULL) {
			(*it)(message);
		}
	}
}
