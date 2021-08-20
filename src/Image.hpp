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
	unsigned char * Input_data;
	unsigned char * Binary_data;
public:
	Image(std::string _File_Path) : File_Path(_File_Path) {
	}
	~Image() {
	}
	void Load(); 
	void TestUnit();
};

class PngImage : public Image{
private:
public:
};

#endif
