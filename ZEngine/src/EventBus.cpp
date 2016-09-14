#include "EventBus.h"

int zng::EventBus::initialize() {
	subscribers[message::GRAPHICS] = std::vector<SUB>(20);

	return zng::OK;
}

int zng::EventBus::subscribe(unsigned short int type, Subscriber& sub) {
	std::vector<SUB>& subs(subscribers[type]);

	for (std::vector<SUB>::iterator it = subs.begin(); it != subs.end(); it++) {
		if (*it == NULL) {
			*it = SUB(&sub);
			return zng::OK;
		}
	}

	return zng::KO;
}

void zng::EventBus::publish(zng::Message& message) {
	std::vector<SUB>& subs(subscribers[message.getType()]);

	for (std::vector<SUB>::iterator it = subs.begin(); it != subs.end(); it++) {
		if (*it != NULL) {
			(*it)->onMessage(message);
		}
	}
}
