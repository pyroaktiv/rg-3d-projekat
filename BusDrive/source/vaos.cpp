#include "../include/vaos.h"
#include "../include/vertices/unit_cube.h"

#include <GL/glew.h>
#include <glfw/glfw3.h>

void setupVAOs() {
	setupUnitCubeVAO();
}

void setupUnitCubeVAO() {
	unsigned vbo;

	glGenVertexArrays(1, &vao_unit_cube);
	glBindVertexArray(vao_unit_cube);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, v_unit_cube.size() * sizeof(float), v_unit_cube.data(), GL_STATIC_DRAW);

	int stride = 9 * sizeof(float);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)(7 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}