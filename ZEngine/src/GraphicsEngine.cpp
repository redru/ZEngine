#include "GraphicsEngine.h"

int zng::GraphicsEngine::initialize() {
	sf::Context context;

	if (glewInit())
		return zng::KO;

	glewExperimental = GL_TRUE;

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

void zng::GraphicsEngine::loadBasicGeometry() {

}

void zng::GraphicsEngine::run() {

	// create the window (remember: it's safer to create it in the main thread due to OS limitations)
	window.reset( new sf::Window(sf::VideoMode(800, 600), "OpenGL") );

	// deactivate its OpenGL context
	window->setActive(false);

	std::thread GRAPHICS_THREAD([&](boost::shared_ptr<sf::Window> win) {
		
		win->setActive(true);

		// OPENGL SETUP
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		// -----------

		while (win->isOpen()) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			win->display();
		}
	}, window);

	GRAPHICS_THREAD.detach();

}
