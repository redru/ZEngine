#include "GraphicsEngine.h"

int zng::GraphicsEngine::initialize() {

	return zng::OK;
}

void zng::GraphicsEngine::onMessage(Message message) {
	std::cout << "On message" << std::endl;
}
