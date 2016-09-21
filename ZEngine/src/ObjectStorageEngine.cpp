#include "ObjectStorageEngine.h"

int zng::ObjectStorageEngine::initialize() {

	return zng::OK;
}

int zng::ObjectStorageEngine::addDrawTarget(boost::shared_ptr<zng::Model> model) {
	for (DrawTargets::iterator it(drawTargets.begin()); it != drawTargets.end(); it++) {
		if (*it == NULL) {
			*it = model;
			return 0;
		}
	}

	return 1;
}
