#include "ZEngine.h"
#include "Triangle.h"
#include "Mesh.h"

int main()
{
	zng::ZEngine& engine(zng::ZEngine::getInstance());
	
	if (engine.initialize() != zng::OK)
		return 1;

	zng::Triangle triangle1 = *zng::Triangle::create();

	engine.run();

	zng::EventBus& eBus(zng::EventBus::getInstance());
	eBus.publish(zng::GraphicsMessage(60));

	return 0;
}
