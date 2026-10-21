#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include <vulkan/vulkan.h>

#include <string>

namespace LittleEngine {

	class LittleEngineWindow {

	public:
			LittleEngineWindow(int w, int h, std::string name);
			~LittleEngineWindow();

			bool ShouldClose() const { return shouldClose; }
			void PollEvents();

    private:
			const int width;
			const int height;
			std::string windowName;

			SDL_Window* window = nullptr;
			bool shouldClose = false;

			void initWindow();
    };
}