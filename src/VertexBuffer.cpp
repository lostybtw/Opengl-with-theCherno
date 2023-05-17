#include "../include/VertexBuffer.h"
#include "../include/Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size){
	ErrorGlCall(glGenBuffers(1, &m_RendererID));
	ErrorGlCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	ErrorGlCall(glBufferData(GL_ARRAY_BUFFER, size , data, GL_STATIC_DRAW)); 
}
VertexBuffer::~VertexBuffer(){
	ErrorGlCall(glDeleteBuffers(1, &m_RendererID));
}
void VertexBuffer::Bind() const {
	ErrorGlCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}
void VertexBuffer::Unbind() const {
	ErrorGlCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
