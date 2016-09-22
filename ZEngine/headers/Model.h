#pragma once
#include <boost\smart_ptr\shared_ptr.hpp>
#include <glm\vec3.hpp>

#include "Mesh.h"
#include "Shader.h"
#include "ShaderFactory.h"

namespace zng {

	class Model {

		using Transform = glm::vec3;

	public:
		Model() : shader(zng::ShaderFactory::getInstance().getShader("default")), position(0.0f), rotation(0.0f), size(1.0f), active(true) { };
		Model(std::string shader) : shader(zng::ShaderFactory::getInstance().getShader(shader)), position(0.0f), rotation(0.0f), size(1.0f) { };
		~Model() { };

	public:
		virtual void draw() = 0;

		inline void setActive(bool _active) { active = _active; };
		inline bool isActive() { return active; };

	protected:
		Shader& shader;
		Transform position;
		Transform rotation;
		Transform size;
		bool active;

	};

}
