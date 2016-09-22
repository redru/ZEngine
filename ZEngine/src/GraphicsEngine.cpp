#include "GraphicsEngine.h"

int zng::GraphicsEngine::initialize() {
	sf::Context context;

	if (glewInit())
		return zng::KO;

	glewExperimental = GL_TRUE;

	zng::EventBus& eBus(zng::EventBus::getInstance());
	setSubscribers(eBus);

	return zng::OK;
}

void zng::GraphicsEngine::setSubscribers(zng::EventBus& eBus) {

	eBus.subscribe(zng::MESSAGE::GRAPHICS, [&](zng::Message& message) {

		zng::GraphicsMessage& gMessage = dynamic_cast<zng::GraphicsMessage&> (message);
		std::cout << "FPS: " << gMessage.getFps() << std::endl;

	});

	eBus.subscribe(zng::MESSAGE::SHUTDOWN, [&](zng::Message& message) {
		closing = true;
	});

}

void zng::GraphicsEngine::loadBasicGeometry() {
	zng::Triangle::initialize();
}

void zng::GraphicsEngine::run() {

	// create the window (remember: it's safer to create it in the main thread due to OS limitations)
	window.reset( new sf::Window(sf::VideoMode(800, 600), "OpenGL") );

	// deactivate its OpenGL context
	window->setActive(false);

	std::thread GRAPHICS_THREAD([&](boost::shared_ptr<sf::Window> win) {
		
		win->setActive(true);

		loadBasicGeometry();

		// OPENGL SETUP
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		// -----------

		while (win->isOpen() && !closing) {
			updateGraphicsEngine();
			camera->calculateMVP();

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			drawAll();

			win->display();
		}
	}, window);

	GRAPHICS_THREAD.detach();

}

void zng::GraphicsEngine::drawAll() {
	DrawTargets& dTargs(zng::ObjectStorageEngine::getInstance().getDrawTargets());
	for (DrawTargets::iterator it(dTargs.begin()); it != dTargs.end(); it++) {
		if (*it != NULL) {
			(*it)->draw();
		}
	}
}
