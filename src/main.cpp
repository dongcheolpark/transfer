#include <iostream>
#include <fstream>
#include "FreeImage.h"
#include "ImageTransfer.hpp"

using namespace std;

int main() {
	const char * imagePath = "../test2.png";
	FreeImage_Initialise(TRUE);

	FIBITMAP *dib = FreeImage_Load(FIF_PNG,imagePath,PNG_DEFAULT);
	int width = FreeImage_GetWidth(dib);
	int height = FreeImage_GetHeight(dib);
	cout<<width<<height;
}