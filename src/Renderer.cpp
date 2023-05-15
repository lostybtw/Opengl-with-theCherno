#include <iostream>

#include "../include/Renderer.h"

#define ASSERT(x) if(!(x)) __builtin_trap();
#define ErrorGlCall(x) ClearGlErrors(); x; ASSERT(CheckGlErrors(#x, __FILE__, __LINE__));

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

