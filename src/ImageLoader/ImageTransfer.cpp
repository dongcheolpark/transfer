#include "../ImageTransfer.hpp"


void ImageTransfer::load(std::string File_Path) {
	data = new Image(File_Path);
}