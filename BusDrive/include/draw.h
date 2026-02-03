#pragma once

#include <glm/glm.hpp>
#include <string>

#include "../include/Shader.h"
#include "../include/Texture.h"

void drawRoad();
void drawBus();
void drawPassengers();
void drawControlBoard();


void drawPlainCube(const glm::mat4&, const Material&, const Light&, glm::vec3);
void drawTexturedCube(const glm::mat4&, const Material&, const Light&, const Texture&, const TexScale&, glm::vec3);



void drawPlainQuad(const glm::mat4&, const Material&, const Light&, glm::vec3);
void drawTexturedQuad(const glm::mat4&, const Material&, const Light&, const Texture&, const TexScale&, glm::vec3);
