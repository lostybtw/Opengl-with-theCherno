#pragma once 

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <type_traits>
#include <vector>
#include "Renderer.h"

struct VertexBufferElement{
	unsigned int count;
	unsigned int type;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type){
		switch (type) {
			case GL_FLOAT: return 4;
			case GL_UNSIGNED_INT: return 4;
			case GL_UNSIGNED_BYTE: return 1;
		}
		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout{
	private:
		std::vector<VertexBufferElement> m_Elements;
		unsigned int m_Stride;
	public:
		VertexBufferLayout()
			: m_Stride(0) {}
		
		void Push(unsigned int type, unsigned int count){
			m_Elements.push_back({count, type, false});
			m_Stride += count * VertexBufferElement::GetSizeOfType(type);
		}
		
		inline const std::vector<VertexBufferElement> GetElements() const {return m_Elements;}
		inline unsigned int GetStride() const {return m_Stride;}
};

