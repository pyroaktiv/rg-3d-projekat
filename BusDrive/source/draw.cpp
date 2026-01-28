#include "../include/draw.h"
#include "../include/vertices/unit_cube.h"
#include "../include/globals.h"

void drawRoad() {

}





void drawUnitCube(glm::mat4 transform) {
	g_shader_basic.use();
	
	g_shader_basic.setBool("uUseTex", false);

	glm::mat4 MVP = g_camera.getProjectionMatrix() * g_camera.getViewMatrix() * transform;

	g_shader_basic.setMat4("uMVP", MVP);

	glBindVertexArray(vao_unit_cube);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 4, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 20, 4);

	glBindVertexArray(0);
}