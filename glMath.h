#pragma once
#include<iostream>
#include<cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


struct vec3 {

	float x, y, z;

	vec3( float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f):x(x_),y(y_), z(z_) {}

	friend std::ostream& operator<<(std::ostream& os,const vec3& v) {
		os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
		return os;
	}

	vec3 operator+(const vec3& v) const{

		return vec3(x + v.x, y + v.y, z + v.z);
	
	}

	vec3 operator-(const vec3& v)const {

		return vec3(x - v.x, y - v.y, z - v.z);
	}

	vec3 operator*(float s) const {

		return vec3(x * s, y * s, z * s);

	}

	vec3 operator-()const{
		return vec3(-x, -y, -z);
	}


	float length() const {
		return std::sqrt(x * x + y * y + z * z);
	}


	vec3 normalize() const {

		float l = length();
		
		if (l > 0) return vec3(x / l, y / l, z / l);
		return vec3(0, 0, 0);
	}


	static float dot(const vec3& v1, const vec3& v2) {

		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	static vec3 cross(const vec3& v1, const vec3& v2) {

		return vec3(v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x);
	}
};

const float PI = 3.14159265359f;


inline float radians(float degrees) {
	return degrees * (PI / 180.0f);
}

struct mat4 {

	float m[16];
	
	mat4() {
		
		for (int i = 0; i < 16; i++) m[i] = 0.0f;

		
		m[0] = 1.0f;
		m[5] = 1.0f;
		m[10] = 1.0f;
		m[15] = 1.0f;
	}

	const float* ptr() const { return m; }  //for pointer refrence to gluniformmatrix4fv

	static mat4 identity() {
		
		return mat4();
	}

	void print() const {
		std::cout << "mat4:" << std::endl;
		for (int i = 0; i < 16; ++i) {
			std::cout << m[i] << "\t";  

			
			if ((i + 1) % 4 == 0) {
				std::cout << std::endl; 
			}
		}
	}

	mat4 operator*(const mat4& rhs)const{

		mat4 result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				float sum = 0.0f;
				for (int k = 0; k < 4;k++) {

					sum += m[k * 4 + j] * rhs.m[i * 4 + k];
				}
				result.m[i * 4 + j] = sum; //stores at result.m[0][0] then increment in accordance
			}
		}

		return result;
	
	
	}

	static mat4 rotate(float angle_rad, const vec3& axis) {
        vec3 norm_axis = axis.normalize();
        float c = std::cos(angle_rad);
        float s = std::sin(angle_rad);
        float t = 1.0f - c;
        float x = norm_axis.x;
        float y = norm_axis.y;
        float z = norm_axis.z;

        mat4 rot = identity();
        // Col 0
        rot.m[0] = t * x * x + c;
        rot.m[1] = t * x * y + s * z;
        rot.m[2] = t * x * z - s * y;
        // Col 1
        rot.m[4] = t * x * y - s * z;
        rot.m[5] = t * y * y + c;
        rot.m[6] = t * y * z + s * x;
        // Col 2
        rot.m[8] = t * x * z + s * y;
        rot.m[9] = t * y * z - s * x;
        rot.m[10] = t * z * z + c;
        
        return rot;
    }

	static mat4 lookAt(const vec3& eye, const vec3& centre, const vec3& up)  {

		vec3 f = (eye - centre).normalize(); //moving in Z axis
		vec3 s = vec3::cross(up, f).normalize(); // moving in sides X axis
		vec3 u = vec3::cross(f, s); // moving up and down Z axis


		mat4 result = identity();
		//tanspose is convertin rows into column
		//only applicable on top 3 rows leaving bottom rows
		//this is transpose of R^-1 from lookAt matrix formula View = R^-1 * T^-1
		result.m[0] = s.x;
		result.m[1] = u.x;
		result.m[2] = f.x;

		result.m[4] = s.y;
		result.m[5] = u.y;
		result.m[6] = f.y;

		result.m[8] = s.z;
		result.m[9] = u.z;
		result.m[10] = f.z;

		//last column for translation

		result.m[12] = -vec3::dot(s, eye);						
		result.m[13] = -vec3::dot(u, eye);						
		result.m[14] = -vec3::dot(f, eye);

		return result;
		
	}

	static mat4 perspective(float fov_rad, float aspect_ratio, float zNear, float zFar) {
		mat4 result;
		for (int i = 0; i < 16; i++) result.m[i];

		float tanHalfFov = std::tan(fov_rad / 2.0f);
		float f = 1.0f / tanHalfFov;
		float zRange = zNear - zFar;

		//col 0
		result.m[0] = f/aspect_ratio;

		//col 1

		result.m[5] = f;

		//col 2

		result.m[10] = (zFar + zNear) / zRange;
		result.m[11] = -1.0f;

		//col 3

		result.m[13] = (2.0f * zFar * zNear) / zRange;

		return result;
	}

	
};
