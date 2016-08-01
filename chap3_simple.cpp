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

vec3 make_color(const ray& r) {
	vec3 unit_direction = unit_vector(r.direction());

}

int main() {

	const int W=800;
	const int H=450;
	const int STRIDE = 3;

	unsigned char buffer[W*H*3];

	vec3 origin(0,0,0);

	// the horizontal size of the view plane
	vec3 horizontal(4,0,0);

	// vertical size of the view plane
	vec3 vertical(0,2,0);

	vec3 lower_left_corner(-2,-1,-1);

	for(int i=0;i<W*H;i++) {
	
		const int xx = i%W;
		const int yy = i/W;

		// get a percentage of where you are in X
		// and in Y
		const float u = float(xx) / float(W);
		const float v = float(yy) /float(H);

		//std::cout << "pixel " << xx << " " << yy << 
		//	" " << u << " " << v << std::endl;

		// create a ray from the origin
		// that streches to another point
		// defined by lower left corner + percent*horizontal size
		//	+ percent*vertical size

		ray r(origin, lower_left_corner + u*horizontal + v*vertical);

		// TODO: determine color here of what is at the end of
		// the ray r

		int pixel = yy*W + xx;
		buffer[pixel] = 0;
		buffer[pixel+1] = 0;
		buffer[pixel+2] = 255;

	}

	write_ppm(buffer, W, H, "out3_simple.ppm");

	return 0;
}

