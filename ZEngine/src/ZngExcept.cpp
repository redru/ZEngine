#include "ZngExcept.h"


const char* zng::ModuleInitializationException::what() const throw()
{
	return "ModuleInitializationException happened";
}

const char* zng::EngineInitializationException::what() const throw()
{
	return "EngineInitializationException happened";
}
