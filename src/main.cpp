#include <iostream>
#include <fstream>
#include "ImageTransfer.hpp"

using namespace std;

int main() {
	ImageTransfer test("test.png");
	test.run();
}