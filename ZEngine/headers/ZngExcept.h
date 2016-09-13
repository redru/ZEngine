#pragma once
#include <iostream>
#include <exception>

namespace zng {

	class ModuleInitializationException : public std::exception {

	public:
		virtual const char* what() const throw();

	};

	class EngineInitializationException {

	public:
		virtual const char* what() const throw();

	};

}
