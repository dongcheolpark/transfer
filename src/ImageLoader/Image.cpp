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
	input_length = length;
}


//PngImage

void PngImage::make_crc_table() {
	unsigned long c;
	for(int n = 0; n<256; n++) {
		c = (unsigned long)n;
		for(int k = 0;k<8;k++) {
			if(c & 1) {
				c = 0xedb88320L ^ (c>>1);
			}
			else {
				c = c >> 1;
			}
		}
		crc_table[n] = c;
	}
	crc_table_computed = true;
}

unsigned long PngImage::update_crc(unsigned long crc, unsigned char *buf, int len) {
	unsigned long c = crc;

	if(!crc_table_computed) {
		make_crc_table();
	}
	for(int n = 0;n<len;n++) {
		c = crc_table[(c ^ buf[n] & 0xff)] ^ (c >> 8);
	}
	return c;
}

void PngImage::decode_data() {
	if(Binary_data != NULL) return;

	
}