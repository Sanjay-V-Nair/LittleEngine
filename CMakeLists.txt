cmake_minimum_required(VERSION 3.20)
project(LittleEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED CONFIG)
find_package(Vulkan REQUIRED COMPONENTS glslc)

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

file(GLOB SHADER_SOURCES CONFIGURE_DEPENDS shaders/*.vert shaders/*.frag)

set(SPIRV_FILES)
foreach(SHADER ${SHADER_SOURCES})
    get_filename_component(SHADER_NAME ${SHADER} NAME)
    set(SPIRV ${CMAKE_BINARY_DIR}/shaders/${SHADER_NAME}.spv)
    add_custom_command(
        OUTPUT ${SPIRV}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/shaders
        COMMAND ${Vulkan_GLSLC_EXECUTABLE} ${SHADER} -o ${SPIRV}
        DEPENDS ${SHADER}
        COMMENT "Compiling ${SHADER_NAME}")
    list(APPEND SPIRV_FILES ${SPIRV})
endforeach()

add_custom_target(Shaders DEPENDS ${SPIRV_FILES})
add_dependencies(LittleEngine Shaders)
