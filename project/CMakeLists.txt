cmake_minimum_required(VERSION 3.10)
project(Graphics1)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
link_libraries(glfw)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)

message(STATUS "Output directory: ${EXECUTABLE_OUTPUT_PATH}")
message(STATUS "Include directory: ${INCLUDE_PATH}")


add_subdirectory(${INCLUDE_PATH})
add_executable(main ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(main PUBLIC glad glm)