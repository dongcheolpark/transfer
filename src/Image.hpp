#ifndef __Image__
#define __Image__

#include <iostream>
#include <fstream>
#include <string>

class Image {
protected:
	//signatures
	const std::string Png_Header_Signature;
	std::string File_Path;
	int Width;
	int Height;
	int input_length;  
	int Binary_length;
	unsigned char * Input_data;
	unsigned char * Binary_data;
public:
	Image() : Input_data(NULL),Binary_data(NULL) {}
	Image(std::string _File_Path) : File_Path(_File_Path) {
		Load();
	}
	~Image() {
		if(Input_data != NULL) {
			delete Input_data;
		}
	}
	void Load(); 
	virtual void decode_data();
	void TestUnit();
};

class PngImage : public Image{
private:
	unsigned long crc_table[256];
	bool crc_table_computed;
	void make_crc_table();
	unsigned long update_crc(unsigned long crc, unsigned char *buf,int len);
	unsigned long crc(unsigned char *buf, int len) {
		 return update_crc(0xffffffffL, buf, len) ^ 0xffffffffL;
	}
public:
	PngImage(std::string _File_Path)
	 : Image(_File_Path), crc_table_computed(false) {}
	void decode_data();
};

#endif
