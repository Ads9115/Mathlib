#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H




#include <string>
#include <glad/glad.h>
#include"glMath.h"

class Shader {
public:
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();
	void use() const;

	void setFloat(const std::string& name, float value) const;
	void setVec2(const std::string& name, const vec2& value) const;
	void setMat4(const std::string& name, const mat4& mat) const;
	void setVec3(const std::string& name, const vec3& value) const;
	void setInt(const std::string& name, int value) const;
};


#endif 