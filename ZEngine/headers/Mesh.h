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

		inline std::vector<float> getArrayVertices() {
			std::vector<float> points(vertices.size() * 3);

			for (unsigned int index = 0, position = 0; position < vertices.size(); index += 3, position++) {
				points[index] = vertices[position]->getX();
				points[index + 1] = vertices[position]->getY();
				points[index + 2] = vertices[position]->getZ();
			}

			return points;
		};

	private:
		Vertices vertices;

	};

}
