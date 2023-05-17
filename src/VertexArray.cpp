#include "../include/VertexArray.h"
#include "../include/Renderer.h"

#define BUFFER_OFFSET(idx) (static_cast<char*>(0) + (idx))

VertexArray::VertexArray(){
	ErrorGlCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray(){
	ErrorGlCall(glDeleteVertexArrays(1,&m_RendererID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout){
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for(unsigned int i = 0; i < elements.size(); i++){
		const auto& element = elements[i];
		ErrorGlCall(glEnableVertexAttribArray(i));
		ErrorGlCall(glVertexAttribPointer(i,element.count, element.type, element.normalized, layout.GetStride(), (const void*) offset));
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}
void VertexArray::Bind() const{
	ErrorGlCall(glBindVertexArray(m_RendererID));
}
void VertexArray::Unbind() const{
	ErrorGlCall(glBindVertexArray(0));
}
