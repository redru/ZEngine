#pragma once
#include <boost\smart_ptr\scoped_ptr.hpp>

#include "Codes.h"

namespace zng
{

	class EventBus
	{

	public:
		int initialize();
		int subscribe();

		void publishGraphicsMessage();
		void publishPhysicsMessage();
		void publishSoundMessage();

	private:
		EventBus() { };
		// ~GraphicsEngine() { };

	public:
		static EventBus& getInstance()
		{
			static boost::scoped_ptr<EventBus> instance( new EventBus );
			return *instance;
		}


	};

};
