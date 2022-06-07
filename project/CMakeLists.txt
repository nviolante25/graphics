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


include_directories(${INCLUDE_PATH}/glm-0.9.2.7)
add_executable(main ${PROJECT_SOURCE_DIR}/main.cpp ${INCLUDE_PATH}/glad/glad.c)