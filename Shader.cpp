#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include"glMath.h"


Shader::Shader(const char* vertexPath, const char* fragmentPath) {
	std::ifstream vFile(vertexPath);
	std::ifstream fFile(fragmentPath);
	std::stringstream vStream, fStream;

	vStream << vFile.rdbuf();
	fStream << fFile.rdbuf();

	std::string vCode = vStream.str();
	std::string fCode = fStream.str();

	const char* vShaderCode = vCode.c_str();
	const char* fShaderCode = fCode.c_str();

	unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

Shader::~Shader() {
	glDeleteProgram(ID);
}

void Shader::use() const {
	glUseProgram(ID);
}



void Shader::setFloat(const std::string& name, float value) const {
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setVec2(const std::string& name, const vec2& value) const {
	glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, value.ptr());
}


void Shader::setMat4(const std::string& name, const mat4& mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, mat.ptr());
}


void Shader::setVec3(const std::string& name, const vec3& value) const
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, value.ptr());
}

void Shader::setVec4(const std::string& name, const vec4& value) const
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, value.ptr());
}

void Shader::setInt(const std::string& name, int value) const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}