#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "vec3.h"

using namespace std;

void test_stb_write() {
	const int STRIDE=3;
	unsigned char * buffer = new unsigned char[STRIDE*10*10];
	for(int i=0;i<10;i++) {
		int pos = 5*10+i;
		buffer[pos*STRIDE] = 255;
		buffer[(pos*STRIDE)+1] = 0;
		buffer[(pos*STRIDE)+2] = 0;
	}
	stbi_write_png("out.png", 10,10, STRIDE, buffer, 10*STRIDE);
}

void test_stb_write2() {
	const int STRIDE=3;
	unsigned char * buffer = new unsigned char[STRIDE*10*10];
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			int pos = i*10 + j;
			int rp = pos * STRIDE;
			buffer[rp] = i*25;
			buffer[rp+1] = 0;
			buffer[rp+2] = 0;
		}
	}
	stbi_write_png("out2.png", 10, 10, STRIDE, buffer, 10*STRIDE);
}

int main() {


	test_stb_write();
	test_stb_write2();

	return 0;
}
