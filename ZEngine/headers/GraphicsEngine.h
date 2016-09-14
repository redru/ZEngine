#pragma once
#include <boost\smart_ptr\scoped_ptr.hpp>

#include "Codes.h"
#include "EventBus.h"

namespace zng {

	class GraphicsEngine {

	public:
		int initialize();

	private:
		GraphicsEngine() { };

	public:
		static GraphicsEngine& getInstance() {
			static boost::scoped_ptr<GraphicsEngine> instance(new GraphicsEngine);
			return *instance;
		}

	private:
		void setGraphicsSubscriber(zng::EventBus& eBus);

	};

};
