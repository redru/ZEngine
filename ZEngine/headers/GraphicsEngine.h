#pragma once
#include <boost\smart_ptr\scoped_ptr.hpp>

#include "Codes.h"
#include "EventBus.h"

namespace zng {

	class GraphicsEngine : public Subscriber {

	public:
		int initialize();
		virtual void onMessage(Message message) override;

	private:
		GraphicsEngine() { };
		// ~GraphicsEngine() { };

	public:
		static GraphicsEngine& getInstance() {
			static boost::scoped_ptr<GraphicsEngine> instance(new GraphicsEngine);
			return *instance;
		}


	};

};
