#include "ZEngine.h"

int main()
{
	zng::ZEngine& engine(zng::ZEngine::getInstance());
	
	if (engine.initialize() != zng::OK)
		return 1;

	zng::ShaderFactory& factory(zng::ShaderFactory::getInstance());

	engine.run();

	zng::EventBus& eBus(zng::EventBus::getInstance());
	eBus.publish(zng::GraphicsMessage(60));

	return 0;
}
