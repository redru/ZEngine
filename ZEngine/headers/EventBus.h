#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <boost\smart_ptr\scoped_ptr.hpp>

#include "Codes.h"

namespace zng {

	namespace message {

		static unsigned short int GRAPHICS = 0x000000;

	}

	class Message { };

	class GraphicsMessage : public Message {

	public:
		GraphicsMessage() { };
		GraphicsMessage(int fps) : fps(fps) { };

		inline int getFps() { return fps; };

	private:
		int fps;

	};

	class Subscriber {

	public:
		virtual void onMessage(Message message) = 0;

	};

	class EventBus {

	public:
		int initialize();
		int subscribe(unsigned short int type, Subscriber& sub);

		void publish(unsigned short int type, const Message message);
		void publishGraphicsMessage();
		void publishPhysicsMessage();
		void publishSoundMessage();

	private:
		EventBus() { };
		// ~GraphicsEngine() { };

	private:
		std::map<unsigned short int, std::vector<Subscriber*>> subscribers;

	public:
		static EventBus& getInstance() {
			static boost::scoped_ptr<EventBus> instance(new EventBus);
			return *instance;
		}


	};

};
