cmake_minimum_required(VERSION 3.11)

project(
	Transfer
)

add_executable (program
	src/main.cpp
	src/ImageLoader/ImageTransfer.cpp
	src/ImageLoader/Image.cpp
	src/ImageLoader/PngImage.cpp
)