
#include <iostream>

#include "vec3.h"

std::ostream& operator<<(std::ostream& os, const vec3 &src) {
	os << src.e[0] << " " << src.e[1] << " " << src.e[2];
	return os;
}

inline vec3 operator*(float t, const vec3& v) {
	return vec3(t*v.e[0],t*v.e[1],t*v.e[2]);
}

inline vec3 operator*(const vec3& v, float t) {
	return vec3(t*v.e[0],t*v.e[1],t*v.e[2]);
}
