#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if(result==GL_FALSE){
		int length; 
		glGetShaderiv(id,GL_INFO_LOG_LENGTH, &length); 
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length ,message);
		std::string error_type;
		if(type == GL_VERTEX_SHADER){error_type = "Vertex";}
		else{error_type = "Fragment";}
		std::cout << "Failed to Compile " << error_type << " Shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	return id;
}

static unsigned int CreateShader(const std::string& vertex_shader , const std::string& fragment_shader){
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(vertex_shader, GL_VERTEX_SHADER);
	unsigned int fs = CompileShader(fragment_shader, GL_FRAGMENT_SHADER);
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
//	glDetachShader(program,vs);
//	glDetachShader(program,fs);
	glValidateProgram(program);
	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	if(glewInit() != GLEW_OK)
		std::cout << "Error Initializing GLEW" << std::endl;
	
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

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float) ,positions, GL_STATIC_DRAW); 


	glEnableVertexAttribArray(0); 
    glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	unsigned int ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 8 * sizeof(unsigned int), indicies, GL_STATIC_DRAW);
	

	ShaderProgramSource	src = ParseShader("res/basic.shader");
	unsigned int Shader = CreateShader(src.VertexSource, src.FragmentSource);
	glUseProgram(Shader); 

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_RENDERABLE);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
	glDeleteProgram(Shader);
    glfwTerminate();
    return 0;
}


