#include "../ImageTransfer.hpp"

//img factory
void ImageTransfer::load(std::string File_Path) {
	std::string Ext = File_Path.substr(File_Path.find_last_of(".") + 1);
	if(Ext == "png") {
		data = new PngImage(File_Path);
	}
	else {
		data = new Image(File_Path);
	}
	data->decode_data();
}