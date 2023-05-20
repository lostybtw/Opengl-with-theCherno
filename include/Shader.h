#pragma once

#include <forward_list>
#include <string>
#include <unordered_map>

struct ShaderProgramSource{
	std::string VertexSource;
	std::string FragmentSource;
	std::unordered_map<std::string, int> m_UniformLocationCache;
};

class Shader{
	private:
		unsigned int m_RendererID;
		std::string m_FilePath;
		unsigned int GetUniformLocation(const std::string& name);
		ShaderProgramSource ParseShader(const std::string& file);
		unsigned int CompileShader(const std::string& source, unsigned int type);
		unsigned int CreateShader(const std::string& vertex_shader, const std::string& fragment_shader);
		std::unordered_map<std::string, int> m_UniformLocationCache;

	public:
		Shader(const std::string& filepath);
		~Shader();
		
		void Bind() const;
		void Unbind() const;
		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void SetUniform1f(const std::string& name, float value);
		void SetUniform1i(const std::string& name , int value);

};