#pragma once
#include <boost\smart_ptr\scoped_ptr.hpp>

#include "Codes.h"

namespace zng
{

	class SoundEngine
	{

	public:
		int initialize();

	private:
		SoundEngine() { };
		// ~SoundEngine() { };

	public:
		static SoundEngine& getInstance()
		{
			static boost::scoped_ptr<SoundEngine> instance(new SoundEngine);
			return *instance;
		}


	};

};
