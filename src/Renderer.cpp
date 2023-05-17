#include <iostream>

#include "../include/Renderer.h"

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

