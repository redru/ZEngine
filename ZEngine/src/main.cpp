#include "ZEngine.h"

int main()
{
	zng::ZEngine& engine(zng::ZEngine::getInstance());
	int result = engine.initialize();

	return 0;
}
