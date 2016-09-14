#pragma once
#include <iostream>
#include <boost\smart_ptr\scoped_ptr.hpp>

#include "EventBus.h"
#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "SoundEngine.h"

namespace zng {

	class ZEngine {

	public:
		int initialize();

	private:
		ZEngine() { };

	public:
		static ZEngine& getInstance() {
			static boost::scoped_ptr<ZEngine> instance( new ZEngine );
			return *instance;
		}

	};

}
