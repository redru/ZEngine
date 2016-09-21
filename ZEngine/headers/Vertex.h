#pragma once
#include <glm\vec3.hpp>

namespace zng {

	class Vertex {

		using XYZ = glm::vec3;

	public:
		Vertex() : vert(0.0f) { };
		Vertex(float x, float y, float z) : vert(x, y, z) { };
		~Vertex() { };

		inline void setXYZ(float x, float y, float z) { vert.x = x; vert.y = y; vert.z = z; };
		inline const XYZ& getXYZ() { return vert; };

	private:
		XYZ vert;

	};

}
