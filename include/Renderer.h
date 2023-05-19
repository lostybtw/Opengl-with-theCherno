#pragma once
#include "IndexBuffer.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>

class VertexArray;
class IndexBuffer;
class Shader;

#define ASSERT(x) if(!(x)) __builtin_trap();
#define ErrorGlCall(x) ClearGlErrors(); x; ASSERT(CheckGlErrors(#x, __FILE__, __LINE__));

void ClearGlErrors();
bool CheckGlErrors(const char* function, const char* file, int line);

class Renderer{
	private:

	public:
		void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
		void Clear() const;
};
