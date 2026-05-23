#include "LittleEngine_Window.hpp"

namespace LittleEngine {

	LittleEngineWindow::LittleEngineWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{name} {
		initWindow();
	}

	LittleEngineWindow::~LittleEngineWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void LittleEngineWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		
		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}


}
