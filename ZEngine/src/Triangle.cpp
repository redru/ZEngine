#include "Triangle.h"

bool zng::Triangle::initialized = false;
boost::shared_ptr<zng::Mesh> zng::Triangle::mesh(new Mesh);

zng::Triangle::Triangle() : zng::Model("default") {
	
}

void zng::Triangle::draw() {
	
}

void zng::Triangle::initialize() {
	std::cout << "[GRAPHICS] zng::Triangle initialized" << std::endl;

	zng::Triangle::mesh->addVertex(new zng::Vertex(-0.5f, -0.43f, 0.0f));
	zng::Triangle::mesh->addVertex(new zng::Vertex(0.5f, -0.43f, 0.0f));
	zng::Triangle::mesh->addVertex(new zng::Vertex(0.0f, 0.43f, 0.0f));

	zng::Triangle::initialized = true;
}
