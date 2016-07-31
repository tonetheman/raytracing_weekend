#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
public:
	vec3 A;
	vec3 B;

	ray() {}
	ray(const vec3& a, const vec3& b) { 
		A = a; 
		B = b; 
	}
	vec3 origin() const {
		return A;
	}
	vec3 direction() const {
		return B;
	}

	// this works because A is origin and B is head of the vector
	// if t is 0 you are at A
	// if t is 1 you are at B
	// if t is 1/2 you are half way between A and B
	vec3 point_at_parameter(float t) const {
		return A + t*B;
	}

};


#endif
