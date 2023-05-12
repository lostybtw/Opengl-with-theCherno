#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>


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
    window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	if(glewInit() != GLEW_OK)
		std::cout << "Error Initializing GLEW" << std::endl;
	
	float positions[] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float) ,positions, GL_STATIC_DRAW); 

    glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	glEnableVertexAttribArray(0);

	std::string vertexshader = "#version 330 core\n"
		"\n"
		"layout(location=0) in vec4 position;"
		"\n"
		"void main(){\n"
		"	gl_Position = position;\n"
		"}";

	std::string fragmentshader = "#version 330 core\n"
		"\n"
		"layout(location=0) out vec4 color;"
		"\n"
		"void main(){\n"
		"	color = vec4(0.5, 1.0, 0.5, 1.0);\n"
		"}";

	unsigned int Shader = CreateShader(vertexshader, fragmentshader);
	glUseProgram(Shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_RENDERABLE);
		glDrawBuffer(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
	glDeleteProgram(Shader);
    glfwTerminate();
    return 0;
}


