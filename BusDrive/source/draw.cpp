#include <glm/gtc/matrix_transform.hpp>

#include "../include/draw.h"
#include "../include/vertices/unit_cube.h"
#include "../include/vertices/quad.h"
#include "../include/globals.h"
#include "../include/matrices/bus_matrices.h"
#include "../include/matrices/road_matrices.h"
#include "../include/materials.h"

void drawRoad() {

	struct Light light = {
		Bus::CAMERA_POS,
		glm::vec3(0.5f, 0.5f, 0.5f),
		glm::vec3(0.5f, 0.5f, 0.5f),
		glm::vec3(0.5f, 0.5f, 0.5f),
	};



	for (int i = 0; i < 3; i++) {
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, g_bus.yaw, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::translate(model, glm::vec3(-g_bus.pos.x, 0.0f, g_road.getSegmentZ(i)));
		drawTexturedQuad(model * M_road_base, roadMaterial, light, g_tex_road, TexScale{300.0f, 16.0f}, Bus::CAMERA_POS);
		drawPlainCube(model * M_road_left_sidewalk_base, sidewalkMaterial, light, Bus::CAMERA_POS);
		drawPlainCube(model * M_road_right_sidewalk_base, sidewalkMaterial, light, Bus::CAMERA_POS);
		drawPlainCube(model * M_road_station_pillar_base, busStationMaterial, light, Bus::CAMERA_POS);
	}
}

void drawBus() {

	struct Light light = {
		Bus::CAMERA_POS,
		glm::vec3(0.7f, 0.7f, 0.7f),
		glm::vec3(0.7f, 0.7f, 0.7f),
		glm::vec3(0.5f, 0.5f, 0.5f),
	};

	glm::mat4 model = glm::mat4(1.0f);

	drawPlainCube(model * M_bus_front_bottom_panel, busMaterial, light, Bus::CAMERA_POS);
	drawPlainCube(model * M_bus_front_top_panel, busMaterial, light, Bus::CAMERA_POS);
	drawPlainCube(model * M_bus_left_pillar, busMaterial, light, Bus::CAMERA_POS);
	drawPlainCube(model * M_bus_right_pillar, busMaterial, light, Bus::CAMERA_POS);
	drawPlainCube(model * M_bus_floor, busFloorMaterial, light, Bus::CAMERA_POS);
	drawPlainCube(model * M_bus_left_side, busMaterial, light, Bus::CAMERA_POS);
	drawPlainCube(model * M_bus_right_side, busMaterial, light, Bus::CAMERA_POS);
	drawPlainCube(model * M_bus_roof, busRoofMaterial, light, Bus::CAMERA_POS);
	drawPlainCube(model * M_bus_drivers_side_bottom_panel, busMaterial, light, Bus::CAMERA_POS);
	drawPlainCube(model * M_bus_drivers_side_top_panel, busMaterial, light, Bus::CAMERA_POS);
	drawPlainCube(model * M_bus_passenger_side_top_panel, busMaterial, light, Bus::CAMERA_POS);
	drawPlainCube(model * M_bus_dashboard, busDashboardMaterial, light, Bus::CAMERA_POS);

	if (g_bus.doorsOpen == false) {
		drawPlainCube(model * M_bus_door, busDoorMaterial, light, Bus::CAMERA_POS);
	}
}

void drawPassenger() {
	if (g_bunch.currentPassenger != nullptr) {

		struct Light light = {
		Bus::CAMERA_POS,
		glm::vec3(0.7f, 0.7f, 0.7f),
		glm::vec3(0.7f, 0.7f, 0.7f),
		glm::vec3(0.5f, 0.5f, 0.5f),
		};

		glm::mat4 model = glm::mat4(1.0f);

		model = glm::translate(model, g_bunch.currentPassenger->pos);
		model = glm::scale(model, glm::vec3(0.5f, g_bunch.currentPassenger->scaleY, 0.5f));
		model = glm::translate(model, glm::vec3(-0.5f, 0.0f, -0.5f));

		drawPlainCube(model, busStationMaterial, light, Bus::CAMERA_POS);
	}
}

void drawPlainCube(const glm::mat4& transform, const Material& material, const Light& light, glm::vec3 viewPos) {
	g_shader_phong.use();

	g_shader_phong.setBool("uUseTex", false);
	g_shader_phong.setMaterial("uMaterial", material);
	g_shader_phong.setLight("uLight", light);
	g_shader_phong.setVec3("uViewPos", viewPos);

	glm::mat4 VP = g_camera.getProjectionMatrix() * g_camera.getViewMatrix();

	glm::mat3 M_Tinv = glm::mat3(glm::transpose(glm::inverse(transform)));

	g_shader_phong.setMat3("uM_Tinv", M_Tinv);
	g_shader_phong.setMat4("uM", transform);
	g_shader_phong.setMat4("uVP", VP);

	glBindVertexArray(vao_unit_cube);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 4, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 20, 4);

	glBindVertexArray(0);
}

void drawTexturedCube(const glm::mat4& transform, const Material& material, const Light& light, const Texture& texture, const TexScale& texScale, glm::vec3 viewPos) {
	g_shader_phong.use();

	g_shader_phong.setBool("uUseTex", true);
	g_shader_phong.setMaterial("uMaterial", material);
	g_shader_phong.setLight("uLight", light);
	g_shader_phong.setTexScale("uScale", texScale);
	g_shader_phong.setVec3("uViewPos", viewPos);

	glm::mat4 VP = g_camera.getProjectionMatrix() * g_camera.getViewMatrix();

	glm::mat3 M_Tinv = glm::mat3(glm::transpose(glm::inverse(transform)));

	g_shader_phong.setMat3("uM_Tinv", M_Tinv);
	g_shader_phong.setMat4("uM", transform);
	g_shader_phong.setMat4("uVP", VP);

	glBindVertexArray(vao_unit_cube);

	texture.bind(0);
	g_shader_phong.setInt("uTex", 0);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 4, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 20, 4);

	glBindVertexArray(0);
}

void drawPlainQuad(const glm::mat4& transform, const Material& material, const Light& light, glm::vec3 viewPos) {
	g_shader_phong.use();

	g_shader_phong.setBool("uUseTex", false);
	g_shader_phong.setMaterial("uMaterial", material);
	g_shader_phong.setLight("uLight", light);
	g_shader_phong.setVec3("uViewPos", viewPos);

	glm::mat4 VP = g_camera.getProjectionMatrix() * g_camera.getViewMatrix();

	glm::mat3 M_Tinv = glm::mat3(glm::transpose(glm::inverse(transform)));

	g_shader_phong.setMat3("uM_Tinv", M_Tinv);
	g_shader_phong.setMat4("uM", transform);
	g_shader_phong.setMat4("uVP", VP);

	glBindVertexArray(vao_quad);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glBindVertexArray(0);
}

void drawTexturedQuad(const glm::mat4& transform, const Material& material, const Light& light, const Texture& texture, const TexScale& texScale, glm::vec3 viewPos) {
	g_shader_phong.use();

	g_shader_phong.setBool("uUseTex", true);
	g_shader_phong.setMaterial("uMaterial", material);
	g_shader_phong.setLight("uLight", light);
	g_shader_phong.setTexScale("uScale", texScale);
	g_shader_phong.setVec3("uViewPos", viewPos);

	glm::mat4 VP = g_camera.getProjectionMatrix() * g_camera.getViewMatrix();

	glm::mat3 M_Tinv = glm::mat3(glm::transpose(glm::inverse(transform)));

	g_shader_phong.setMat3("uM_Tinv", M_Tinv);
	g_shader_phong.setMat4("uM", transform);
	g_shader_phong.setMat4("uVP", VP);

	glBindVertexArray(vao_quad);

	texture.bind(0);
	g_shader_phong.setInt("uTex", 0);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glBindVertexArray(0);
}