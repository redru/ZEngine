#pragma once
#include <boost\smart_ptr\scoped_ptr.hpp>

#include "Codes.h"

namespace zng
{

	class GraphicsEngine
	{

	public:
		int initialize();

	private:
		GraphicsEngine() { };
		// ~GraphicsEngine() { };

	public:
		static GraphicsEngine& getInstance()
		{
			static boost::scoped_ptr<GraphicsEngine> instance(new GraphicsEngine);
			return *instance;
		}


	};

};
