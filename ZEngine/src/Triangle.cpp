#include "Triangle.h"

// STATICS ------------------------------------------------------
bool zng::Triangle::initialized = false;
boost::shared_ptr<zng::Mesh> zng::Triangle::mesh(new Mesh);
GLuint zng::Triangle::vao = 0;

// DRAW FUNCTION ------------------------------------------------
void zng::Triangle::draw() {
	glBindVertexArray(vao);
	
	glUniformMatrix4fv(shader.getUniform("mvp"), 1, GL_FALSE, &camera->getMVP()[0][0]);
	// glUniformMatrix4fv(Engine::graphics().defaultShader().uniformId("transform"), 1, GL_FALSE, &transform()[0][0]);

	glUseProgram(shader.getProgram());

	// draw points 0-3 from the currently bound VAO with current in-use shader
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(0);
}

// INITIALIZATION FUNCTION --------------------------------------
void zng::Triangle::initialize() {
	std::cout << "[GRAPHICS] zng::Triangle initialized" << std::endl;

	zng::Triangle::mesh->addVertex(new zng::Vertex(-0.5f, -0.43f, 0.0f));
	zng::Triangle::mesh->addVertex(new zng::Vertex(0.5f, -0.43f, 0.0f));
	zng::Triangle::mesh->addVertex(new zng::Vertex(0.0f, 0.43f, 0.0f));

	std::vector<float>& tmp(mesh->getArrayVertices());
	glm::mat3 colors(1.0f);

	GLuint points_vbo = 0;
	glGenBuffers(1, &points_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), &tmp[0], GL_STATIC_DRAW);

	GLuint colours_vbo = 0;
	glGenBuffers(1, &colours_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), &colors[0][0], GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	zng::Triangle::initialized = true;
}
// --------------------------------------------------------------
