#include "ZEngine.h"

int zng::ZEngine::initialize()
{
	zng::GraphicsEngine& graphics( zng::GraphicsEngine::getInstance() );
	zng::PhysicsEngine& physics( zng::PhysicsEngine::getInstance() );
	zng::SoundEngine& sound( zng::SoundEngine::getInstance() );
	zng::EventBus& eventBus( zng::EventBus::getInstance() );

	if (graphics.initialize() == zng::KO)
	{
		return zng::KO;
	}

	if (physics.initialize() == zng::KO)
	{
		return zng::KO;
	}

	if (sound.initialize() == zng::KO)
	{
		return zng::KO;
	}

	return zng::OK;
}
