#pragma once
#include <vector>
#include <boost\smart_ptr\shared_ptr.hpp>

#include "Vertex.h"

namespace zng {

	class Mesh {

		using Vertices = std::vector<boost::shared_ptr<Vertex>>;

	public:
		Mesh() { };
		~Mesh() { };

	public:
		inline void addVertex(Vertex* vertex) { vertices.push_back(boost::shared_ptr<Vertex>(vertex)); };
		inline Vertex& getVertex(int& index) { return *vertices[index]; };

		inline Vertices& getVertices() { return vertices; };

	private:
		Vertices vertices;

	};

}
