#include "ZEngine.h"
#include "Triangle.h"
#include "Mesh.h"

int main()
{
	zng::ZEngine& engine(zng::ZEngine::getInstance());
	
	if (engine.initialize() != zng::OK)
		return 1;

	boost::shared_ptr<zng::Triangle> triangle(zng::Triangle::create());
	zng::ObjectStorageEngine::getInstance().addDrawTarget(triangle);

	engine.run();

	zng::EventBus& eBus(zng::EventBus::getInstance());
	eBus.publish(zng::GraphicsMessage(60));

	return 0;
}
