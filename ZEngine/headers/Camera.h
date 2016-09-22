#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm\mat4x4.hpp>

namespace zng {

	class Camera {

	public:
		Camera() : position(glm::vec3(0.0f)), lookTarget(glm::vec3(0.0f)), up(glm::vec3(0.0f, 1.0f, 0.0f)), upside_down(glm::vec3(0.0f, -1.0f, 0.0f)), mustEvaluate(true) { };
		Camera(glm::vec3 position, glm::vec3 lookTarget) : position(position), lookTarget(lookTarget), up(glm::vec3(0.0f, 1.0f, 0.0f)), upside_down(glm::vec3(0.0f, -1.0f, 0.0f)), mustEvaluate(true) { };
		~Camera() { };

	public:
		inline void translateTo(float x, float y, float z) {
			mustEvaluate = true;
			position.x = x;
			position.y = y;
			position.z = z;
		};

		inline void move(float xOffset, float yOffset, float zOffset) {
			mustEvaluate = true;
			position.x += xOffset;
			position.y += yOffset;
			position.z += zOffset;
		};

		inline void lookAt(float xOffset, float yOffset, float zOffset) {
			mustEvaluate = true;
			lookTarget.x += xOffset;
			lookTarget.y += yOffset;
			lookTarget.z += zOffset;
		};

		void calculateMVP() {
			if (mustEvaluate) {
				glm::mat4 model(1.0f);

				glm::mat4 view = glm::lookAt(
					position,
					lookTarget,
					up        // probably glm::vec3(0,1,0), but (0,-1,0) would make you looking upside-down, which can be great too
				);

				glm::mat4 projection = glm::perspective(
					60.0f,         // The horizontal Field of View, in degrees : the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
					16.0f / 9.0f, // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
					0.1f,        // Near clipping plane. Keep as big as possible, or you'll get precision issues.
					100.0f       // Far clipping plane. Keep as little as possible.
				);

				mvp = projection * view * model;
				
				mustEvaluate = false;
			}
		};

		inline glm::mat4& getMVP() { return mvp; };

	private:
		glm::vec3 position;
		glm::vec3 lookTarget;
		glm::mat4 mvp;

		bool mustEvaluate;

		const glm::vec3 up;
		const glm::vec3 upside_down;

	};

}
