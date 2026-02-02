#include "../include/vaos.h"
#include "../include/vertices/unit_cube.h"
#include "../include/vertices/quad.h"

#include <GL/glew.h>
#include <glfw/glfw3.h>

void setupVAOs() {
	setupUnitCubeVAO();
	setupQuadVAO();
}

void setupUnitCubeVAO() {
	unsigned vbo;

	glGenVertexArrays(1, &vao_unit_cube);
	glBindVertexArray(vao_unit_cube);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, v_unit_cube.size() * sizeof(float), v_unit_cube.data(), GL_STATIC_DRAW);

	int stride = 8 * sizeof(float);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void setupQuadVAO() {
	unsigned vbo;

	glGenVertexArrays(1, &vao_quad);
	glBindVertexArray(vao_quad);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, v_quad.size() * sizeof(float), v_quad.data(), GL_STATIC_DRAW);

	int stride = 8 * sizeof(float);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}