#version 330 core


struct Light {
    vec3 pos;
    vec3 kA;
    vec3 kD;
    vec3 kS;
};

struct Material {
    vec3 kA;
    vec3 kD;
    vec3 kS;
    float shine;
    float alpha;
};

struct TexScale {
    float scaleS;
    float scaleT;
};

in vec3 chFragPos;
in vec3 chNor;
in vec2 chTex;

out vec4 outCol;

uniform bool uUseTex;
uniform sampler2D uTex;

uniform TexScale uScale;

uniform Light uLight;
uniform Material uMaterial;
uniform vec3 uViewPos;

void main()
{
    vec3 objectColor;
    float finalAlpha;

    if (uUseTex) {
        vec4 texColor = texture(uTex, vec2(chTex.s * uScale.scaleS, chTex.t * uScale.scaleT));
        objectColor = texColor.rgb;
        finalAlpha = texColor.a;
    } else {
        objectColor = uMaterial.kD;
        finalAlpha = uMaterial.alpha;
    }

    vec3 normal = normalize(chNor);
    vec3 lightDirection = normalize(uLight.pos - chFragPos);
    vec3 viewDirection = normalize(uViewPos - chFragPos);
    vec3 reflectionDirection = reflect(-lightDirection, normal);

    vec3 ambientComponent = uUseTex ? objectColor : uMaterial.kA;
    vec3 resA = uLight.kA * ambientComponent;

    float nD = max(dot(normal, lightDirection), 0.0);
    vec3 resD = uLight.kD * (nD * objectColor);

    float s = pow(max(dot(viewDirection, reflectionDirection), 0.0), uMaterial.shine);
    vec3 resS = uLight.kS * (s * uMaterial.kS);

    outCol = vec4(resA + resD + resS, finalAlpha);
}