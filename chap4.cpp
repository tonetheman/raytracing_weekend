#include <iostream>
#include "ray.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
    
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

bool hit_sphere(const vec3& center, float radius, const ray& r) {
}


vec3 color(const ray& r) {
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0-t) * vec3(1.0,1.0,1.0) + t * vec3(0.5,0.7,1.0);
}

int main() {

	int nx = 200;
	int ny = 200;
	const int STRIDE = 3;

	unsigned char buffer[nx*ny*STRIDE];

	vec3 lower_left_corner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);
	for (int j=ny-1; j >= 0; j--) {
		for (int i=0; i<nx; i++) {
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);
			ray r(origin, lower_left_corner + u * horizontal +
				v * vertical);
			vec3 col = color(r);

			int pos = i*200 + j;
			int rp = pos * STRIDE;

			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);
			buffer[rp] = ir;
			buffer[rp+1] = ig;
			buffer[rp+2] = ib;
		}

		stbi_write_png("out5.png", 200, 200, STRIDE, buffer, 200*STRIDE);
	}	

	return 0;
}
