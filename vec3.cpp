
#include <iostream>

#include "vec3.h"

std::ostream& operator<<(std::ostream& os, const vec3 &src) {
	os << src.e[0] << " " << src.e[1] << " " << src.e[2];
	return os;
}

inline vec3 operator+(const vec3& v1, const vec3& v2) {
	return vec3(v1.e[0]+v2.e[0], v1.e[1]+v2.e[1], v1.e[2]+v2.e[2]);
}

inline vec3 operator*(const vec3& v1, const vec3& v2) {
	return vec3(v1.e[0]*v2.e[0], v1.e[1]*v2.e[1], v1.e[2]*v2.e[2]);
}

