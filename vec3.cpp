
#include <iostream>

#include "vec3.h"

std::ostream& operator<<(std::ostream& os, const vec3 &src) {
	os << src.e[0] << " " << src.e[1] << " " << src.e[2];
	return os;
}

