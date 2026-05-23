#pragma once

#include "LittleEngine_Window.hpp"

namespace LittleEngine {

	class FirstApp {

	public :
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		LittleEngineWindow littleEngineWindow{WIDTH, HEIGHT, "Hello Vulkan"};

	};

}