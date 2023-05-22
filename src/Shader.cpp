#include "../include/Shader.h"
#include "../include/Renderer.h"

#include <locale>
#include <string>
#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>
#include <system_error>
#include <type_traits>


Shader::Shader(const std::string& filepath) : m_FilePath(filepath), m_RendererID(0){
	ShaderProgramSource source =  ParseShader(filepath);
	m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
}
Shader::~Shader(){
	ErrorGlCall(glDeleteProgram(m_RendererID));	
}
void Shader::Bind() const{
	ErrorGlCall(glUseProgram(m_RendererID));
} 
void Shader::Unbind() const{
	ErrorGlCall(glUseProgram(0));
}
void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3){
	ErrorGlCall(glUniform4f(GetUniformLocation(name) ,v0, v1, v2, v3));		
}
void Shader::SetUniform1f(const std::string& name, float value){
	ErrorGlCall(glUniform1f(GetUniformLocation(name), value));
}
void Shader::SetUniform1i(const std::string& name, int value){
	ErrorGlCall(glUniform1i(GetUniformLocation(name), value));
}
void Shader::SetUniformMat4f(const std::string& name, glm::mat4 matrix){
	ErrorGlCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
}

unsigned int Shader::GetUniformLocation(const std::string& name){
	if(m_UniformLocationCache.find(name) != m_UniformLocationCache.end()){
		return m_UniformLocationCache[name];
	} 
	ErrorGlCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
	if(location == -1){
		std::cout << "Warning: uniform " << name << " doesn't exist!" << std::endl;
	}
	m_UniformLocationCache[name] = location;
	return location;
}

ShaderProgramSource Shader::ParseShader(const std::string& file){
	enum class shader_type{
		NONE = -1, VERTEX = 0, FRAGMENT = 1	
	};
	std::ifstream stream(file);
	std::string line;
	std::stringstream ss[2];
	shader_type type = shader_type::NONE;
	while(getline(stream, line)){
		if(line.find("#shader") != std::string::npos){
				if(line.find("vertex") != std::string::npos){
					type = shader_type::VERTEX;
				}
				else if(line.find("fragment") != std::string::npos){
					type = shader_type::FRAGMENT;
				}
		}
		else{
			ss[int(type)] << line << '\n';
		}
	}
	return {ss[0].str(), ss[1].str()};
}

unsigned int Shader::CompileShader(const std::string& source , unsigned int type){
	ErrorGlCall(unsigned int id = glCreateShader(type));
	const char* src = source.c_str();
	ErrorGlCall(glShaderSource(id, 1, &src, nullptr));
	ErrorGlCall(glCompileShader(id));
	int result;
	ErrorGlCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if(result==GL_FALSE){
		int length; 
		ErrorGlCall(glGetShaderiv(id,GL_INFO_LOG_LENGTH, &length)); 
		char* message = (char*)alloca(length * sizeof(char));
		ErrorGlCall(glGetShaderInfoLog(id, length, &length ,message));
		std::string error_type;
		if(type == GL_VERTEX_SHADER){error_type = "Vertex";}
		else{error_type = "Fragment";}
		std::cout << "Failed to Compile " << error_type << " Shader!" << std::endl;
		std::cout << message << std::endl;
		ErrorGlCall(glDeleteShader(id));
		return 0;
	}
	return id;
}

unsigned int Shader::CreateShader(const std::string& vertex_shader , const std::string& fragment_shader){
	ErrorGlCall(unsigned int m_RendererID = glCreateProgram());
	unsigned int vs = CompileShader(vertex_shader, GL_VERTEX_SHADER);
	unsigned int fs = CompileShader(fragment_shader, GL_FRAGMENT_SHADER);
	ErrorGlCall(glAttachShader(m_RendererID, vs));
	ErrorGlCall(glAttachShader(m_RendererID, fs));
	ErrorGlCall(glLinkProgram(m_RendererID));
//	glDetachShader(m_RendererID,vs);
//	glDetachShader(m_RendererID,fs);
	ErrorGlCall(glValidateProgram(m_RendererID));
	ErrorGlCall(glDeleteShader(vs));
	ErrorGlCall(glDeleteShader(fs));

	return m_RendererID;
}


