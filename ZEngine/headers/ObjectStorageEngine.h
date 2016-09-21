#pragma once
#include <boost\smart_ptr\scoped_ptr.hpp>

#include "Codes.h"
#include "Model.h"

namespace zng {

	class ObjectStorageEngine {

		using DrawTargets = std::vector<boost::shared_ptr<zng::Model>>;

	public:
		int initialize();

	public:
		int addDrawTarget(boost::shared_ptr<zng::Model> model);
		inline DrawTargets& getDrawTargets() { return drawTargets; };

	private:
		ObjectStorageEngine() : drawTargets(200) { };
		// ~PhysicsEngine() { };

	public:
		static ObjectStorageEngine& getInstance() {
			static boost::scoped_ptr<ObjectStorageEngine> instance(new ObjectStorageEngine);
			return *instance;
		}

	private:
		DrawTargets drawTargets;

	};

}
