#include "GraphicsEngine.h"

int zng::GraphicsEngine::initialize() {
	zng::EventBus::getInstance().subscribe(zng::message::GRAPHICS, *this);

	return zng::OK;
}

void zng::GraphicsEngine::onMessage(zng::Message& message) {
	zng::GraphicsMessage& gMessage = dynamic_cast<zng::GraphicsMessage&> (message);
	std::cout << "FPS: " << gMessage.getFps() << std::endl;
}
