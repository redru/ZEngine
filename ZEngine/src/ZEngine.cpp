#include "ZEngine.h"

int zng::ZEngine::initialize() {
	zng::EventBus& eventBus(zng::EventBus::getInstance());
	zng::GraphicsEngine& graphics( zng::GraphicsEngine::getInstance() );
	zng::PhysicsEngine& physics( zng::PhysicsEngine::getInstance() );
	zng::SoundEngine& sound( zng::SoundEngine::getInstance() );

	if (eventBus.initialize() == zng::KO) {
		return zng::KO;
	}

	if (graphics.initialize() == zng::KO) {
		return zng::KO;
	}

	if (physics.initialize() == zng::KO) {
		return zng::KO;
	}

	if (sound.initialize() == zng::KO) {
		return zng::KO;
	}

	eventBus.subscribe(zng::message::GRAPHICS, graphics);

	return zng::OK;
}
