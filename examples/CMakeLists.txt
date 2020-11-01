# examples/CMakeLists.txt

cmake_minimum_required(VERSION 3.15)

# Poject
project( examples
		 VERSION 1.0.0
		 DESCRIPTION "A collection of individual subprojects"
         LANGUAGES CXX )
		 
add_subdirectory(hello)
add_subdirectory(opengl)