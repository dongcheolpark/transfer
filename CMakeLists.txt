cmake_minimum_required(VERSION 3.11)

project(
	Transfer
)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(FreeImage)

add_executable (program
	src/main.cpp
	src/ImageLoader/ImageTransfer.cpp
	src/ImageLoader/Image.cpp
	src/ImageLoader/PngLoader.cpp
)
target_include_directories(program PUBLIC ${FreeImage_SOURCE_DIR}/Source)
target_link_libraries(program FreeImage)
