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
#include "Camera.h"

namespace zng {

	class Viewport {

	public:
		Viewport(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) { };

		int x, y, width, height;
	};

	class GraphicsEngine {

		using DrawTargets = std::vector<boost::shared_ptr<zng::Model>>;

		// STARTUP FUNCTIONS
	public:
		int initialize();
		void run();

		// DATA TO BE CHANGED FROM OUTSIDE CLASSES
	public:
		inline void changeViewport(zng::Viewport _viewport) { viewport = _viewport; mustUpdate = true; };

	private:
		inline void updateGraphicsEngine() {
			if (mustUpdate) {
				glViewport(viewport.x, viewport.y, viewport.width, viewport.height);
				mustUpdate = false;
			}
		};

	private:
		bool mustUpdate;
		bool closing;
		zng::Viewport viewport;

		
		// INNER FUNCTIONS
	private:
		void setSubscribers(zng::EventBus& eBus);
		void loadBasicGeometry();
		void drawAll();

		// GETTER - SETTER
	public:
		inline sf::Window& getWindow() { return *window; };

		inline void setCamera(zng::Camera* _camera) { camera.reset(_camera); };
		inline zng::Camera* getCamera() { return camera.get(); };

	private:
		boost::shared_ptr<sf::Window> window;
		boost::shared_ptr<zng::Camera> camera;

		// SINGLETON
	private:
		GraphicsEngine() : mustUpdate(false), closing(false), viewport(zng::Viewport(0, 0, 0, 0)), camera(new Camera(glm::vec3(0.0f, 5.0f, -10.0f), glm::vec3(0.0f, 0.0f, 0.0f))) { };

	public:
		static GraphicsEngine& getInstance() {
			static boost::scoped_ptr<GraphicsEngine> instance(new GraphicsEngine);
			return *instance;
		}

	};

};
