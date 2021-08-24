#include "../Image.hpp"

#include <cstring>

void Image::TestUnit() {
}

void Image::Load() {
	if(Input_data != NULL) return;
	std::ifstream File(File_Path,std::ios::binary);
	File.seekg(0,File.end);
	int length = (int)File.tellg();
	File.seekg(0,File.beg);
	Input_data = new unsigned char[length];
	File.read((char*)Input_data,length);
	File.close();
	input_length = length;
	std::cout<<"image load complete\n";
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

int PngImage::ChunkDataToNum(int ptr,int size) {
	int res = 0;
	ptr += size;
	for(int i = 0;i<size;i++) {
		res += Input_data[ptr-i]*pow(16,i);
	}
	return res;
}

void PngImage::decode_data() {
	if(Binary_data != NULL || Input_data == NULL) return;
	int ptr = 0;	
	//check header Signature
	for(ptr = 0;ptr<8;ptr++) {
		if(Input_data[ptr] != Header_Signature[ptr]) return;
	}
	ptr = 7;
	//chunks
	while(ptr <= input_length) {
		if(Input_data[ptr+1] == (unsigned char)EOF) break;
		int n = 0;
		//find chunk length
		n = ChunkDataToNum(ptr,4);
		std::cout<<n<<std::endl;
		ptr += 4;
		//find chunk type
		unsigned char type[5];
		std::string Type;
		type[4] = '\0';
		ptr++;
		for(int i = 0;i<4;i++,ptr++) {
			type[i] = Input_data[ptr];
		}

		std::cout<<type<<std::endl;
		Type = static_cast<std::string>(reinterpret_cast<const char *>(type));
		if(Type == "IEND") break;
		ptr += n-1;
		ptr += 4;
	}
}