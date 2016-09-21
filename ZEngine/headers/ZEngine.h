#pragma once
#include <iostream>

#include "EventBus.h"
#include "GraphicsEngine.h"
#include "ShaderFactory.h"
#include "PhysicsEngine.h"
#include "SoundEngine.h"
#include "ObjectStorageEngine.h"

namespace zng {

	class ZEngine {

	public:
		int initialize();
		int run();

	private:
		bool running;

	private:
		ZEngine() { };

	public:
		static ZEngine& getInstance() {
			static boost::scoped_ptr<ZEngine> instance( new ZEngine );
			return *instance;
		}

	};

}
