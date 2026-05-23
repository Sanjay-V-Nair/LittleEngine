#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace LittleEngine {

	class LittleEngineWindow {

	public:
		LittleEngineWindow(int w, int h, std::string name);
		~LittleEngineWindow();

		bool ShouldClose() {
			return glfwWindowShouldClose(window);
		}

	private:

		const int width;
		const int height;
		std::string windowName;

		GLFWwindow* window;

		void initWindow();
	};
}