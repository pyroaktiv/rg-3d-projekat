#include <glm/gtc/matrix_transform.hpp>

#include "../include/draw.h"
#include "../include/vertices/unit_cube.h"
#include "../include/vertices/quad.h"
#include "../include/globals.h"
#include "../include/matrices/bus_matrices.h"
#include "../include/matrices/road_matrices.h"
#include "../include/matrices/control_board_matrices.h"
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

	drawPlainQuad(model * M_bus_windscreen, busGlassMaterial, light, Bus::CAMERA_POS);
	drawPlainQuad(model * M_bus_window, busGlassMaterial, light, Bus::CAMERA_POS);
}

void drawPassengers() {
	struct Light light = {
	Bus::CAMERA_POS,
	glm::vec3(0.7f, 0.7f, 0.7f),
	glm::vec3(0.7f, 0.7f, 0.7f),
	glm::vec3(0.5f, 0.5f, 0.5f),
	};

	g_shader_phong.use();
	g_shader_phong.setBool("uUseTex", false);
	g_shader_phong.setLight("uLight", light);
	g_shader_phong.setVec3("uViewPos", Bus::CAMERA_POS);

	

	for (auto p : g_bunch.boardingPassengers) {
		glm::mat4 model = glm::mat4(1.0f);

		if (p->isControl) {
			model = glm::translate(model, p->pos);
			model = glm::scale(model, glm::vec3(0.01f, 0.01f * p->scaleY, 0.01f));

			if (p->orientation == DIR_NEG_X) {
				model = glm::rotate(model, -glm::pi<float>() / 2, glm::vec3(0.0f, 1.0f, 0.0f));
			}

			model = glm::rotate(model, -glm::pi<float>() / 2, glm::vec3(1.0f, 0.0f, 0.0f));
		}
		else {
			model = glm::translate(model, p->pos);
			model = glm::scale(model, glm::vec3(0.5f, 0.5 * p->scaleY, 0.5f));
			model = glm::translate(model, glm::vec3(0.0f, 1.5f, 0.0f));

			if (p->orientation == DIR_NEG_X) {
				model = glm::rotate(model, -glm::pi<float>() / 2, glm::vec3(0.0f, 1.0f, 0.0f));
			}
		}

		glm::mat3 M_Tinv = glm::mat3(glm::transpose(glm::inverse(model)));
		glm::mat4 VP = g_camera.getProjectionMatrix() * g_camera.getViewMatrix();

		g_shader_phong.setMat3("uM_Tinv", M_Tinv);
		g_shader_phong.setMat4("uM", model);
		g_shader_phong.setMat4("uVP", VP);
		g_shader_phong.setMaterial("uMaterial", p->material);

		if (p->isControl) {
			g_model_control.Draw(g_shader_phong);
		}
		else {
			g_model_passenger.Draw(g_shader_phong);
		}
	}

	for (auto p : g_bunch.disembarkingPassengers) {
		glm::mat4 model = glm::mat4(1.0f);

		if (p->isControl) {
			model = glm::translate(model, p->pos);
			model = glm::scale(model, glm::vec3(0.01f, 0.01f * p->scaleY, 0.01f));

			if (p->orientation == DIR_POS_X) {
				model = glm::rotate(model, glm::pi<float>() / 2, glm::vec3(0.0f, 1.0f, 0.0f));
			}
			else {
				model = glm::rotate(model, glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f));
			}
			model = glm::rotate(model, -glm::pi<float>() / 2, glm::vec3(1.0f, 0.0f, 0.0f));
		}
		else {
			model = glm::translate(model, p->pos);
			model = glm::scale(model, glm::vec3(0.5f, 0.5 * p->scaleY, 0.5f));
			model = glm::translate(model, glm::vec3(0.0f, 1.5f, 0.0f));

			if (p->orientation == DIR_POS_X) {
				model = glm::rotate(model, glm::pi<float>() / 2, glm::vec3(0.0f, 1.0f, 0.0f));
			}
			else {
				model = glm::rotate(model, glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f));
			}
		}

		glm::mat3 M_Tinv = glm::mat3(glm::transpose(glm::inverse(model)));

		glm::mat4 VP = g_camera.getProjectionMatrix() * g_camera.getViewMatrix();

		g_shader_phong.setMat3("uM_Tinv", M_Tinv);
		g_shader_phong.setMat4("uM", model);
		g_shader_phong.setMat4("uVP", VP);
		g_shader_phong.setMaterial("uMaterial", p->material);

		if (p->isControl) {
			g_model_control.Draw(g_shader_phong);
		}
		else {
			g_model_passenger.Draw(g_shader_phong);
		}
	}
}

void drawSteeringWheel() {
	glm::mat4 model = glm::mat4(1.0f);

	struct Light light = {
	Bus::CAMERA_POS,
	glm::vec3(0.7f, 0.7f, 0.7f),
	glm::vec3(0.7f, 0.7f, 0.7f),
	glm::vec3(0.5f, 0.5f, 0.5f),
	};

	g_shader_phong.use();
	g_shader_phong.setBool("uUseTex", false);
	g_shader_phong.setLight("uLight", light);
	g_shader_phong.setVec3("uViewPos", Bus::CAMERA_POS);

	model = glm::translate(model, glm::vec3(Bus::CAMERA_POS.x, Bus::FLOOR_HEIGHT + 0.7f, -Bus::REAR_AXLE_TO_FRONT + 0.4f));
	model = glm::rotate(model, glm::pi<float>() / 12, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::pi<float>() - g_bus.steeringAngle * 8, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));

	glm::mat3 M_Tinv = glm::mat3(glm::transpose(glm::inverse(model)));

	glm::mat4 VP = g_camera.getProjectionMatrix() * g_camera.getViewMatrix();

	g_shader_phong.setMat3("uM_Tinv", M_Tinv);
	g_shader_phong.setMat4("uM", model);
	g_shader_phong.setMat4("uVP", VP);
	g_shader_phong.setMaterial("uMaterial", Material{ glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.3f, 0.3f, 0.3f), 10.0f, 1.0f });

	g_model_steering_wheel.Draw(g_shader_phong);
}

void drawDogtags() {

}

void drawControlBoard() {
	struct Light light = {
	Bus::CAMERA_POS,
	glm::vec3(0.7f, 0.7f, 0.7f),
	glm::vec3(0.7f, 0.7f, 0.7f),
	glm::vec3(0.5f, 0.5f, 0.5f),
	};

	drawTexturedQuad(m_control_board_panel, roadMaterial, light, g_tex_panel, TexScale{1.0f, 1.0f}, Bus::CAMERA_POS);
	drawTexturedQuad(m_control_board_passenger_tens, roadMaterial, light, numbers[g_bunch.totalPassengers / 10], TexScale{1.0f, 1.0f}, Bus::CAMERA_POS);
	drawTexturedQuad(m_control_board_passenger_ones, roadMaterial, light, numbers[g_bunch.totalPassengers % 10], TexScale{1.0f, 1.0f}, Bus::CAMERA_POS);

	drawTexturedQuad(m_control_board_fines_tens, roadMaterial, light, numbers[(g_bunch.totalFines % 100) / 10], TexScale{ 1.0f, 1.0f }, Bus::CAMERA_POS);
	drawTexturedQuad(m_control_board_fines_ones, roadMaterial, light, numbers[g_bunch.totalFines % 10], TexScale{ 1.0f, 1.0f }, Bus::CAMERA_POS);

	if (g_bunch.isControlInside) {
		drawTexturedQuad(m_control_board_control, roadMaterial, light, g_tex_control, TexScale{ 1.0f, 1.0f }, Bus::CAMERA_POS);
	}
	
	if (g_bus.doorsOpen) {
		drawTexturedQuad(m_control_board_door, roadMaterial, light, g_tex_door_open, TexScale{ 1.0f, 1.0f }, Bus::CAMERA_POS);
	}
	else {
		drawTexturedQuad(m_control_board_door, roadMaterial, light, g_tex_door_closed, TexScale{ 1.0f, 1.0f }, Bus::CAMERA_POS);
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