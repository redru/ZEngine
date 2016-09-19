#pragma once
#include <vector>
#include <boost\smart_ptr\shared_ptr.hpp>

#include "Vertex.h"

namespace zng {

	class Mesh {

		using c_Vertex = boost::shared_ptr<Vertex>;
		using c_Vertices = std::vector<c_Vertex>;

	public:
		Mesh() { };
		~Mesh() { };

	public:
		inline void addVertex(Vertex* vertex) { vertices.push_back(c_Vertex(vertex)); };
		inline c_Vertices& getVertices() { return vertices; };

	private:
		c_Vertices vertices;

	};

}
