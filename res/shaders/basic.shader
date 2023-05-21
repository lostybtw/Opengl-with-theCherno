#shader vertex
#version 330 core
layout(location=0) in vec4 position; 
layout(location=1) in vec2 texture_coordinate;
out vec2 v_texture_coordinate;
void main(){
	gl_Position = position;
};

#shader fragment
#version 330 core
uniform vec4 u_color;
uniform sampler2D u_Texture;
layout(location=0) out vec4 color;
in vec2 v_texture_coordinate;
void main(){
	vec4 texColor = texture(u_Texture, v_texture_coordinate); 
	color = texColor;
};
