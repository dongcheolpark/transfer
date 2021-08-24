cmake_minimum_required(VERSION 3.11)

project(
	Transfer
)

set(CMAKE_CXX_STANDARD 17)

add_executable (program
	src/main.cpp
	src/ImageLoader/ImageTransfer.cpp
	src/ImageLoader/Image.cpp
	src/ImageLoader/PngLoader.cpp
)