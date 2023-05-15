#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sched.h>
#include <string>
#include <sstream>

#include "Renderer.cpp"
#include "VertexBuffer.cpp"
#include "IndexBuffer.cpp"

struct ShaderProgramSource{
	std::string VertexSource;
	std::string FragmentSource;
};

static ShaderProgramSource ParseShader(const std::string& file){
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

static unsigned int CompileShader(const std::string& source , unsigned int type){
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

static unsigned int CreateShader(const std::string& vertex_shader , const std::string& fragment_shader){
	ErrorGlCall(unsigned int program = glCreateProgram());
	unsigned int vs = CompileShader(vertex_shader, GL_VERTEX_SHADER);
	unsigned int fs = CompileShader(fragment_shader, GL_FRAGMENT_SHADER);
	ErrorGlCall(glAttachShader(program, vs));
	ErrorGlCall(glAttachShader(program, fs));
	ErrorGlCall(glLinkProgram(program));
//	glDetachShader(program,vs);
//	glDetachShader(program,fs);
	ErrorGlCall(glValidateProgram(program));
	ErrorGlCall(glDeleteShader(vs));
	ErrorGlCall(glDeleteShader(fs));

	return program;
}


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()){
        return -1;
	}
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	glfwSwapInterval(1);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	if(glewInit() != GLEW_OK)
		std::cout << "Error Initializing GLEW" << std::endl;
	{	
	float positions[] = 
	  { 
		-0.5f, -0.5f, 
		0.5f, -0.5f, 
		0.5f, 0.5f, 
		-0.5f, 0.5f 
	  };
	unsigned int indicies[] = {
		0,1,2,
		2,3,0
	};

	unsigned int vao;
	ErrorGlCall(glGenVertexArrays(1, &vao));
	ErrorGlCall(glBindVertexArray(vao));

	VertexBuffer vb(positions, 4 * 2 * sizeof(float));
	
	ErrorGlCall(glEnableVertexAttribArray(0)); 
    ErrorGlCall(glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));
	
	IndexBuffer ib(indicies, 6);

	ShaderProgramSource	src = ParseShader("res/shaders/basic.shader");
	unsigned int Shader = CreateShader(src.VertexSource, src.FragmentSource);
	ErrorGlCall(glUseProgram(Shader)); 
	ErrorGlCall(int uloc = glGetUniformLocation(Shader, "u_color"));
	ASSERT(uloc != -1);

	float red = 0.5f;
	float inc = 0.05f;
	
	ErrorGlCall(glBindVertexArray(0));
	ErrorGlCall(glUseProgram(0));
	vb.Unbind();
	ib.Unbind();
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        ErrorGlCall(glClear(GL_COLOR_BUFFER_BIT));

		ErrorGlCall(glUseProgram(Shader));
		ErrorGlCall(glUniform4f(uloc, red, 0.5f, 0.8f, 1.0f));
		
		ErrorGlCall(glBindVertexArray(vao));
		ib.Bind();	
		
		ErrorGlCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		if(red > 1.0f){
			inc = -0.01f;
		} 
		else if(red < 0.0f){
			inc = 0.01f;
		}

		red += inc;
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
	ErrorGlCall(glDeleteProgram(Shader));
	}
    glfwTerminate();
    return 0;
}


