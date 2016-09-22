#include "ZEngine.h"
#include "Triangle.h"
#include "Mesh.h"

int main()
{
	// Instantiate engine
	zng::ZEngine& engine(zng::ZEngine::getInstance());
	
	// Initialize engine
	if (engine.initialize() != zng::OK)
		return 1;

	// Get graphics engine
	zng::GraphicsEngine& graphics(zng::GraphicsEngine::getInstance());

	// Create game camera
	boost::shared_ptr<zng::Camera> camera( new zng::Camera(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f)) );

	// Set default camera to graphics
	graphics.setCamera(camera.get());

	// Create a new triangle and set his camera
	boost::shared_ptr<zng::Triangle> triangle(zng::Triangle::create(camera.get()));

	// Add triangle to the draw list
	zng::ObjectStorageEngine::getInstance().addDrawTarget(triangle);

	// Run engine
	engine.run();

	zng::EventBus& eBus(zng::EventBus::getInstance());
	eBus.publish(zng::GraphicsMessage(60));

	return 0;
}
