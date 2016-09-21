#pragma once
#include "Model.h"

namespace zng {

	class Triangle : public zng::Model {

	public:
		inline static boost::shared_ptr<Triangle> create() {
			boost::shared_ptr<Triangle> triangle(new Triangle);
			return triangle;
		}

		static void initialize();

	public:
		inline static const bool& isInitialized() { return initialized; };
		inline static Mesh& getMesh() { return *mesh; };

	private:
		Triangle();

		virtual void draw() override;

	private:
		static boost::shared_ptr<Mesh> mesh;
		static bool initialized;

	};

}
