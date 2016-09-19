#pragma once
#include "Model.h"

namespace zng {

	class Triangle : public zng::Model {

	public:
		inline static Triangle* create() {
			return new Triangle;
		}

	private:
		Triangle();

		virtual void draw() override;

	};

}