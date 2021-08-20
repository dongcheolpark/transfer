#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream image("../test.png",ios::binary);
	char buffer[1000];
	int count = 0;
	while(!image.eof()) {
		image.read(buffer,1000);
		int n = image.gcount();
		for(int i = 0;i<n;i++) {
			cout<<buffer[i];
		}
	}
}