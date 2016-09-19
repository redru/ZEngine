#pragma once
#include <boost\smart_ptr\shared_ptr.hpp>

#include "Mesh.h"
#include "Shader.h"
#include "ShaderFactory.h"

namespace zng {

	class Model {

	public:
		Model() : shader(zng::ShaderFactory::getInstance().getShader("default")) { };
		Model(std::string shader) : shader(zng::ShaderFactory::getInstance().getShader(shader)) { };
		~Model() { };

	public:
		virtual void draw() = 0;

	public:
		inline void setMesh(Mesh* _mesh) { mesh.reset(_mesh); };
		inline Mesh& getMesh() { return *mesh; };


	private:
		boost::shared_ptr<Mesh> mesh;
		Shader& shader;

	};

}
