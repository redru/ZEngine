#pragma once
#include <boost\smart_ptr\scoped_ptr.hpp>

#include "Codes.h"

namespace zng
{

	class PhysicsEngine
	{

	public:
		int initialize();

	private:
		PhysicsEngine() { };
		// ~PhysicsEngine() { };

	public:
		static PhysicsEngine& getInstance()
		{
			static boost::scoped_ptr<PhysicsEngine> instance(new PhysicsEngine);
			return *instance;
		}


	};

};
