#include "../include/Texture.h"
#include "../include/vendor/stb_image.h"

Texture::Texture(const std::string& filepath)
	:m_FilePath(filepath), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)
{	
	 stbi_set_flip_vertically_on_load(1);
	 m_LocalBuffer = stbi_load(filepath.c_str(), &m_Width, &m_Height, &m_BPP, 4);
	 ErrorGlCall(glGenTextures(1, &m_RendererID));
	 ErrorGlCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
	 ErrorGlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	 ErrorGlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	 ErrorGlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	 ErrorGlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	
	 ErrorGlCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0,	GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
	 ErrorGlCall(glBindTexture(GL_TEXTURE_2D, 0));

	 if(m_LocalBuffer){
		stbi_image_free(m_LocalBuffer);
	 }
}
Texture::~Texture(){
	ErrorGlCall(glDeleteTextures(1, &m_RendererID));
}
void Texture::Bind(unsigned int slot /* =0 */) const{
	ErrorGlCall(glActiveTexture(GL_TEXTURE0 + slot));
	ErrorGlCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
	ErrorGlCall(glEnable(GL_TEXTURE_2D));
}
void Texture::Unbind() const{
	 ErrorGlCall(glDisable(GL_TEXTURE_2D));
	 ErrorGlCall(glBindTexture(GL_TEXTURE_2D, 0));
}
