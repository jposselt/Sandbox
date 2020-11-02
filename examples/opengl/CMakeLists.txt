# examples/opengl/CMakeLists.txt

cmake_minimum_required(VERSION 3.15)

# Poject
project(opengl_project
	VERSION 1.0.0
	DESCRIPTION "Example using openGL"
	LANGUAGES CXX
)

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

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

# Add package repository
conan_add_remote(
	NAME
    bincrafters
    URL
    https://api.bintray.com/conan/bincrafters/public-conan
)

# Import required packages
conan_cmake_run(
	REQUIRES
		glfw/3.3.2
		glew/2.1.0
		glm/0.9.9.8
	BASIC_SETUP
	CMAKE_TARGETS	# individual targets to link to
	BUILD
		all			# build all dependencies; otherwise we may not
					# get debugging information (at least on Windows)
)

# Link libraries to our target
target_link_libraries(opengl
	PRIVATE
		CONAN_PKG::glew
		CONAN_PKG::glfw
		CONAN_PKG::glm
)

# Copy shader files to build directory
add_custom_command(
	TARGET opengl
	POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
		make_directory ${CMAKE_CURRENT_BINARY_DIR}/shader	# create output dir
	COMMAND ${CMAKE_COMMAND} -E
		copy_if_different									# copy files if changed
			${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.vert	# vertex shader file
			${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.frag	# fragment shader file
			${CMAKE_CURRENT_BINARY_DIR}/shader				# destination dir
)