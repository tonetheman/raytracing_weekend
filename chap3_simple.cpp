#include <iostream>
#include "ray.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// assumes STRIDE is 3 in this buffer
void write_ppm(unsigned char * buffer, int width, int height,
	const char * filename) {
	FILE * outf = fopen(filename,"w");
	fprintf(outf, "P6\n");
	fprintf(outf, "%d %d\n", width, height);
	fprintf(outf, "%d\n", 255);
	for(int i=0;i<width*height;i++) {
		const int pos = i * 3;
		fprintf(outf, "%d %d %d", buffer[pos],buffer[pos+1],buffer[pos+2]);
		if (i%width==0) {
			fprintf(outf,"\n");
		}
	}
	fclose(outf);
}

int main() {

	const int W=800;
	const int H=450;
	const int STRIDE = 3;

	unsigned char buffer[W*H*3];

	vec3 origin(0,0,0);

	for(int i=0;i<W*H;i++) {
		const int xx = i%W;
		const int yy = i/W;

		int pixel = yy*W + xx;
		buffer[pixel] = 0;
		buffer[pixel+1] = 0;
		buffer[pixel+2] = 255;

	}

	write_ppm(buffer, W, H, "out3_simple.ppm");

	return 0;
}

