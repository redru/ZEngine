#include "EventBus.h"

int zng::EventBus::initialize() {
	subscribers[message::GRAPHICS] = std::vector<Subscriber*>(20);

	return zng::OK;
}

int zng::EventBus::subscribe(unsigned short int type, Subscriber& sub) {
	std::vector<Subscriber*>& subs(subscribers[type]);

	for (std::vector<Subscriber*>::iterator it = subs.begin(); it != subs.end(); it++) {
		if (*it == NULL) {
			*it = &sub;
			return zng::OK;
		}
	}

	return zng::KO;
}

void zng::EventBus::publish(unsigned short int type, const Message message) {

}

void zng::EventBus::publishGraphicsMessage() {

}

void zng::EventBus::publishPhysicsMessage() {

}

void zng::EventBus::publishSoundMessage() {

}
