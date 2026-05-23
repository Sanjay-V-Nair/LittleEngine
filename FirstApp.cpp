#include "FirstApp.hpp"

namespace LittleEngine {

	void FirstApp::run() {
		while (!littleEngineWindow.ShouldClose()) {
			glfwPollEvents();
		}
	}

}