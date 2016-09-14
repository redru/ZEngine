#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <boost\smart_ptr\scoped_ptr.hpp>
#include <boost\smart_ptr\shared_ptr.hpp>

#include "Codes.h"
#include "Messages.h"

namespace zng {

	class Subscriber {

	public:
		virtual void onMessage(zng::Message& message) = 0;

	};

	class EventBus {

		using SUB = std::vector<zng::Subscriber*>;

	public:
		int initialize();
		int subscribe(unsigned short int type, zng::Subscriber& sub);

		void publish(zng::Message& message);

	private:
		EventBus() { };

	private:
		std::map<unsigned short int, SUB> subscribers;

	public:
		static EventBus& getInstance() {
			static boost::scoped_ptr<EventBus> instance(new EventBus);
			return *instance;
		}


	};

};
