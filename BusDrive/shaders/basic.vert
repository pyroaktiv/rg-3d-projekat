#version 330 core

layout(location = 0) in vec3 inPos;
layout(location = 1) in vec4 inCol;
layout(location = 2) in vec2 inTex;

uniform mat4 uMVP;

out vec4 chCol;
out vec2 chTex;

void main(){
	gl_Position = uMVP * vec4(inPos, 1.0f);

	chCol = inCol;
	chTex = inTex;
}