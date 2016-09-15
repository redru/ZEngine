#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <boost\smart_ptr\scoped_ptr.hpp>
#include <boost\smart_ptr\shared_ptr.hpp>

#include "Codes.h"
#include "Messages.h"

namespace zng {

	class EventBus {

		using Subscribers = std::vector<std::function<void(zng::Message&)>>;

	public:
		int initialize();
		int subscribe(unsigned short int type, std::function<void(zng::Message&)> onMessage);

		void publish(zng::Message& message);

	private:
		std::map<unsigned short int, Subscribers> subscribers;

	private:
		EventBus() { };

	public:
		static EventBus& getInstance() {
			static boost::scoped_ptr<EventBus> instance(new EventBus);
			return *instance;
		}

	};

};
