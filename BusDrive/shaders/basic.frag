#version 330 core

in vec2 chTex;


uniform sampler2D uTex;

out vec4 outCol;

void main(){
	outCol = texture(uTex, chTex);
}