#pragma once
#include <iostream>
#include <string>
#include <map>

#include <GL\glew.h>

namespace zng {

	class Shader {

		using Uniforms = std::map<std::string, GLuint>;

	public:
		Shader() : program(-1) { };
		Shader(GLuint program) : program(program) { };

		inline void setProgram(GLuint _program) { program = _program; };
		inline GLuint getProgram() { return program; };

		inline void setUniform(std::string name, GLuint uniformId) { uniforms[name] = uniformId; };
		inline GLuint getUniform(std::string name) {
			Uniforms::iterator it = uniforms.find(name);
			if (it == uniforms.end())
				throw std::exception("Uniform not found.");

			return it->second;
		}

	private:
		GLuint program;
		Uniforms uniforms;

	};

}
