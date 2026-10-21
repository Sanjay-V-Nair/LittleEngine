#include "LittleEngine_Window.hpp"

namespace LittleEngine {

	LittleEngineWindow::LittleEngineWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{name} {
		initWindow();
	}

	LittleEngineWindow::~LittleEngineWindow() {
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void LittleEngineWindow::initWindow() {
		if (!SDL_Init(SDL_INIT_VIDEO)) {
			throw std::runtime_error(SDL_GetError());
		}

		window = SDL_CreateWindow(windowName.c_str(), width, height, SDL_WINDOW_VULKAN);
		if (!window) {
			throw std::runtime_error(SDL_GetError());
		}
	}

    void LittleEngineWindow::PollEvents() {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				shouldClose = true;
			}
		}
	}


}
