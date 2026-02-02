#version 330 core

layout(location = 0) in vec3 inPos;
layout(location = 1) in vec2 inTex;
layout(location = 2) in vec3 inNor;

uniform mat3 uM_Tinv;
uniform mat4 uM;
uniform mat4 uVP;

out vec3 chFragPos;
out vec3 chNor;
out vec2 chTex;

void main(){
	chFragPos = vec3(uM * vec4(inPos, 1.0));
	gl_Position = uVP * vec4(chFragPos, 1.0);
	chNor = uM_Tinv * inNor;
	chTex = inTex;
}