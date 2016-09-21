#pragma once
#include <iostream>
#include <thread>

#include <boost\smart_ptr\scoped_ptr.hpp>
#include <GL\glew.h>
#include <SFML\Window.hpp>
#include <SFML\OpenGL.hpp>

#include "Codes.h"
#include "EventBus.h"
#include "ObjectStorageEngine.h"
#include "Triangle.h"

namespace zng {

	class GraphicsEngine {

		using DrawTargets = std::vector<boost::shared_ptr<zng::Model>>;

	public:
		int initialize();
		void run();

	public:
		inline sf::Window& getWindow() { return *window; };

	private:
		void setGraphicsSubscriber(zng::EventBus& eBus);
		void loadBasicGeometry();
		void drawAll();

	private:
		boost::shared_ptr<sf::Window> window;

	private:
		GraphicsEngine() { };

	public:
		static GraphicsEngine& getInstance() {
			static boost::scoped_ptr<GraphicsEngine> instance(new GraphicsEngine);
			return *instance;
		}

	};

};
