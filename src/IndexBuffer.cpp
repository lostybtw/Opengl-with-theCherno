#include "../include/IndexBuffer.h"
#include "../include/Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) :m_Count(count){
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));

	ErrorGlCall(glGenBuffers(1, &m_RendererID));
	ErrorGlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
	ErrorGlCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int) , data, GL_STATIC_DRAW)); 
}
IndexBuffer::~IndexBuffer(){
	ErrorGlCall(glDeleteBuffers(1, &m_RendererID));
}
void IndexBuffer::Bind() const{
	ErrorGlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}
void IndexBuffer::Unbind() const{
	ErrorGlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

