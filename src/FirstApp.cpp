// Created by Sanjay
#include "FirstApp.hpp"

namespace LittleEngine {

	void FirstApp::run() {
		while (!littleEngineWindow.ShouldClose()) {
			littleEngineWindow.PollEvents();
		}
	}

}