# examples/hello/CMakeLists.txt

cmake_minimum_required(VERSION 3.15)

# Poject
project( hello
		 VERSION 1.0.0
		 DESCRIPTION "Hello world"
         LANGUAGES CXX )

# All sources that also need to be tested in unit tests go into a static library
add_library(hello_lib STATIC hello.cpp hello.h)
target_include_directories(hello_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(hello_lib PRIVATE cxx_std_17)

# The main program
add_executable(hello main.cpp)
target_link_libraries(hello PRIVATE hello_lib)