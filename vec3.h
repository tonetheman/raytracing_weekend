#ifndef VEC3
#define VEC3

#include <cmath>

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
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	inline float r() const { return e[0]; }
	inline float g() const { return e[1]; }
	inline float b() const { return e[2]; }
	
	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }

	inline vec3& operator-=(const vec3 &v2);
	inline vec3& operator/=(const vec3 &v2);
	inline vec3& operator/=(const float t);

	inline float length() const {
		return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
	}
	inline float squared_length() const {
		return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
	}
	inline void make_unit_vector();

};

vec3 operator*(const vec3 &v1, const vec3 &v2);
vec3 operator*(float t, const vec3 &v);
vec3 operator*(const vec3 &v, float t);
vec3 operator+(const vec3 &v1, const vec3 &v2);
vec3 operator-(const vec3 &v1, const vec3 &v2);

vec3 unit_vector(vec3 v);
float dot(const vec3& v1, const vec3& v2);

#endif
