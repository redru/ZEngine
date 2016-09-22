#pragma once
#include "Model.h"
#include "Camera.h"

namespace zng {

	class Triangle : public zng::Model {

	public:
		inline static boost::shared_ptr<Triangle> create(zng::Camera* camera) {
			boost::shared_ptr<zng::Triangle> triangle(new Triangle(camera));
			return triangle;
		}

		static void initialize();

	public:
		inline static const bool& isInitialized() { return initialized; };
		inline static Mesh& getMesh() { return *mesh; };

	private:
		Triangle(zng::Camera* camera) : camera(camera), zng::Model("default") { };

		virtual void draw() override;

	private:
		boost::shared_ptr<zng::Camera> camera;

		static boost::shared_ptr<Mesh> mesh;
		static bool initialized;
		static GLuint vao;

	};

}
