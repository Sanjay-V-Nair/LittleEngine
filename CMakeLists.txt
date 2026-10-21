cmake_minimum_required(VERSION 3.20)
project(LittleEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED CONFIG)

add_executable(LittleEngine
    src/main.cpp
    src/FirstApp.cpp
    src/LittleEngine_Window.cpp
)

target_link_libraries(LittleEngine PRIVATE
    SDL3::SDL3
    Vulkan::Vulkan
    glm::glm
)

