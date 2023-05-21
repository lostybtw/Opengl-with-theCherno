#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "VertexBufferLayout.cpp"
#include "Renderer.cpp"
#include "VertexBuffer.cpp"
#include "VertexArray.cpp"
#include "IndexBuffer.cpp"
#include "Shader.cpp"
#include "Texture.cpp"
#include "stb_image.cpp"

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
		-0.5f, -0.5f,	0.0f, 0.0f,
		0.5f, -0.5f,	1.0f,0.0f,
		0.5f, 0.5f,		1.0f, 1.0f,
		-0.5f, 0.5f ,	0.0f, 1.0f
	  };
	unsigned int indicies[] = {
		0,1,2,
		2,3,0
	};
	
	ErrorGlCall(glEnable(GL_BLEND));
	ErrorGlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	VertexArray va;
	VertexBuffer vb(positions, 4 * 4 * sizeof(float));
	
	VertexBufferLayout layout;
	layout.Push(GL_FLOAT, 2);
	layout.Push(GL_FLOAT, 2);
	va.AddBuffer(vb, layout);
	
	IndexBuffer ib(indicies, 6);

	Shader shader("res/shaders/basic.shader");
	shader.Bind();

	Texture texture("res/textures/old_rect_texture.png");
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);
	
	//float red = 0.5f;
	//float inc = 0.05f;
	
	va.Unbind();
	vb.Unbind();
	ib.Unbind();
	shader.Unbind();
	Renderer renderer;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
		renderer.Clear();

		va.Bind();
		ib.Bind();
		shader.Bind();
		texture.Bind();
		shader.SetUniform4f("u_color", 0.8f, 0.5f, 0.8f, 1.0f);
		renderer.Draw(va, ib, shader);
		/*if(red > 1.0f){
			inc = -0.01f;
		} 
		else if(red < 0.0f){
			inc = 0.01f;
		}

		red += inc;*/
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
	}
    glfwTerminate();
    return 0;
}


