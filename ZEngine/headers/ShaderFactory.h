#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

#include <GL\glew.h>
#include <boost\smart_ptr\scoped_ptr.hpp>
#include <boost\smart_ptr\shared_ptr.hpp>

#include "Shader.h"

namespace zng {

	class ShaderFactory {

		using ShaderMap = std::map<std::string, boost::shared_ptr<zng::Shader>>;

	public:
		void initializeDefault();

		void loadShader(std::string name, std::string vertexPath, std::string fragmentPath);
		zng::Shader& getShader(std::string name);

	private:
		ShaderMap shaderMap;

	public:
		static ShaderFactory& getInstance() {
			static boost::scoped_ptr<ShaderFactory> instance( new ShaderFactory );
			return *instance;
		};

	private:
		ShaderFactory() { };

	};

}
