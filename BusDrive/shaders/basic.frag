#version 330 core

in vec2 chTex;
in vec4 chCol;

uniform bool uUseTex;


uniform sampler2D uTex;

out vec4 outCol;

void main(){
	if(uUseTex){
		outCol = texture(uTex, chTex);
	}
	else{
		outCol = chCol;
	}

}