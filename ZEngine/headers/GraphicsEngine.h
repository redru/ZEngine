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
		class : public Subscriber {

			virtual void onMessage(zng::Message& message) {
				zng::GraphicsMessage& gMessage = dynamic_cast<zng::GraphicsMessage&> (message);
				std::cout << "FPS: " << gMessage.getFps() << std::endl;
			};

		} graphicsSubscriber;

	};

};
