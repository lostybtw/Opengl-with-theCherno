#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>

#define ASSERT(x) if(!(x)) __builtin_trap();
#define ErrorGlCall(x) ClearGlErrors(); x; ASSERT(CheckGlErrors(#x, __FILE__, __LINE__));

void ClearGlErrors();
bool CheckGlErrors(const char* function, const char* file, int line);
