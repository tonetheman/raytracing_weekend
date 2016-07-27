#ifndef VEC3
#define VEC3


class vec3 {
public:
	float e[3];
	vec3() {}
	vec3(float e0, float e1, float e2) {
		e[0] = e0;
		e[1] = e1;
		e[2] = e2;
	}
	inline float x() const { return e[0]; }

	// unary plus
	inline const vec3& operator+() const { return *this; }
};

#endif
