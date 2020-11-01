# examples/opengl/CMakeLists.txt

cmake_minimum_required(VERSION 3.15)

# Poject
project( opengl
		 VERSION 1.0.0
		 DESCRIPTION "Example using openGL"
         LANGUAGES CXX )
		 
# The main executable
add_executable(opengl
  src/Application.h
  src/Application.cpp
  src/MyApplication.h
  src/MyApplication.cpp
  src/glError.h
  src/glError.cpp
  src/main.cpp
  src/Shader.h
  src/Shader.cpp
)

target_compile_features(opengl PRIVATE cxx_std_11)

# TODO: add libraries (glm, glew, glfw)