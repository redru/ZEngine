#include "GraphicsEngine.h"

int zng::GraphicsEngine::initialize() {
	zng::EventBus& eBus(zng::EventBus::getInstance());
	setGraphicsSubscriber(eBus);

	return zng::OK;
}

void zng::GraphicsEngine::setGraphicsSubscriber(zng::EventBus& eBus) {

	eBus.subscribe(zng::message::GRAPHICS, [&](zng::Message& message) {

		zng::GraphicsMessage& gMessage = dynamic_cast<zng::GraphicsMessage&> (message);
		std::cout << "FPS: " << gMessage.getFps() << std::endl;

	});

}
