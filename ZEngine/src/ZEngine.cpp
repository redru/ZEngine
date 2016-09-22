#include "ZEngine.h"

int zng::ZEngine::initialize() {
	zng::ObjectStorageEngine& objectStorage(zng::ObjectStorageEngine::getInstance());
	zng::EventBus& eBus(zng::EventBus::getInstance());
	zng::GraphicsEngine& graphics( zng::GraphicsEngine::getInstance() );
	zng::ShaderFactory& shaderFactory( zng::ShaderFactory::getInstance() );
	zng::PhysicsEngine& physics( zng::PhysicsEngine::getInstance() );
	zng::SoundEngine& sound( zng::SoundEngine::getInstance() );

	if (objectStorage.initialize() == zng::KO)
		return zng::KO;

	if (eBus.initialize() == zng::KO) {
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

	shaderFactory.initializeDefault();

	graphics.run();

	return zng::OK;
}

int zng::ZEngine::run() {
	running = true;

	zng::GraphicsEngine& graphics(zng::GraphicsEngine::getInstance());
	zng::EventBus& eBus(zng::EventBus::getInstance());

	sf::Window& window(graphics.getWindow());

	while (running) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				running = false;
				eBus.publish(zng::ShutdownMessage());
			} else if (event.type == sf::Event::Resized) {
				graphics.changeViewport(zng::Viewport(0, 0, event.size.width, event.size.height));
			}
		}

	}

	return zng::OK;
}
