#include "../Image.hpp"

void Image::TestUnit() {
	Load();
}

void Image::Load() {
	std::ifstream File(File_Path,std::ios::binary);
	File.seekg(0,File.end);
	int length = (int)File.tellg();
	File.seekg(0,File.beg);
	Input_data = new unsigned char[length];
	File.read((char*)Input_data,length);
	File.close();
}