#include "GraphicsEngine.h"

int zng::GraphicsEngine::initialize() {
	zng::EventBus::getInstance().subscribe(zng::message::GRAPHICS, graphicsSubscriber);

	return zng::OK;
}
