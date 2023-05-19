#include <iostream>

#include "../include/Renderer.h"
#include "../include/Shader.h"
#include "../include/VertexArray.h"
#include "../include/IndexBuffer.h"

void ClearGlErrors(){
	while(glGetError() != GL_NO_ERROR);
}
bool CheckGlErrors(const char* function, const char* file, int line){
	while(GLenum error = glGetError()){
		std::cout << "[GL Error] (" << error << ") : " << function << " : " << file << " : " << line << std::endl;
		return false;
	}
	return true;
}
void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const{
		shader.Bind();
		va.Bind();
		ib.Bind();	
		ErrorGlCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
void Renderer::Clear() const{
	ErrorGlCall(glClear(GL_COLOR_BUFFER_BIT));
}
