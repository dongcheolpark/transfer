#ifndef __ImageTransfer__
#define __ImageTransfer__

#include "Image.hpp"
#include <string>

class ImageTransfer {
private:
	Image * data;
public : 
	ImageTransfer() : data(NULL) {}
	ImageTransfer(const char * File_Path) {
		load(std::string(File_Path));
	}
	ImageTransfer(std::string File_Path) {
		load(File_Path);
	}
	~ImageTransfer() {
		if(data != NULL) {
			delete data;
		}
	}
	void load(std::string File_Path);
	void run() {
	}
};

#endif