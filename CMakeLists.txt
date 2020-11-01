# CMakeLists.txt

cmake_minimum_required(VERSION 3.15)

# Top level poject
project( sandbox 
		 VERSION 1.0.0
		 DESCRIPTION "Top level project"
         HOMEPAGE_URL "https://github.com/jposselt/sandbox"
         LANGUAGES CXX )

add_subdirectory(examples)