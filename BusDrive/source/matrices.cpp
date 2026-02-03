#include <glm/gtc/matrix_transform.hpp>

#include "../include/matrices.h"
#include "../include/matrices/bus_matrices.h"
#include "../include/matrices/road_matrices.h"
#include "../include/matrices/control_board_matrices.h"

#include "../include/Road.h"
#include "../include/RoadSegment.h"
#include "../include/Bus.h"

void setupMatrices() {
	setupBusMatrices();
	setupRoadBaseMatrices();
	setupControlBoardMatrices();
}


void setupBusMatrices() {
	glm::mat4 unit = glm::mat4(1.0f);

	M_bus_front_bottom_panel = unit;
	M_bus_front_bottom_panel = glm::translate(M_bus_front_bottom_panel, glm::vec3(-Bus::WIDTH / 2, Bus::FLOOR_HEIGHT, -Bus::REAR_AXLE_TO_FRONT));
	M_bus_front_bottom_panel = glm::scale(M_bus_front_bottom_panel, glm::vec3(Bus::WIDTH, 0.7f, 0.05f));

	M_bus_front_top_panel = unit;
	M_bus_front_top_panel = glm::translate(M_bus_front_top_panel, glm::vec3(-Bus::WIDTH / 2, Bus::ROOF_HEIGHT - 0.5f, -Bus::REAR_AXLE_TO_FRONT));
	M_bus_front_top_panel = glm::scale(M_bus_front_top_panel, glm::vec3(Bus::WIDTH, 0.5f, 0.05f));

	M_bus_left_pillar = unit;
	M_bus_left_pillar = glm::translate(M_bus_left_pillar, glm::vec3(-Bus::WIDTH / 2, Bus::FLOOR_HEIGHT, -Bus::REAR_AXLE_TO_FRONT));
	M_bus_left_pillar = glm::scale(M_bus_left_pillar, glm::vec3(0.1f, Bus::ROOF_HEIGHT - Bus::FLOOR_HEIGHT, 0.1f));

	M_bus_right_pillar = unit;
	M_bus_right_pillar = glm::translate(M_bus_right_pillar, glm::vec3(Bus::WIDTH / 2 - 0.1f, Bus::FLOOR_HEIGHT, -Bus::REAR_AXLE_TO_FRONT));
	M_bus_right_pillar = glm::scale(M_bus_right_pillar, glm::vec3(0.1f, Bus::ROOF_HEIGHT - Bus::FLOOR_HEIGHT, 0.3f));


	M_bus_floor = unit;
	M_bus_floor = glm::translate(M_bus_floor, glm::vec3(-Bus::WIDTH / 2, Bus::FLOOR_HEIGHT - 0.05f, -Bus::REAR_AXLE_TO_FRONT));
	M_bus_floor = glm::scale(M_bus_floor, glm::vec3(Bus::WIDTH, 0.05f, Bus::REAR_AXLE_TO_BACK + Bus::REAR_AXLE_TO_FRONT));


	M_bus_left_side = unit;
	M_bus_left_side = glm::translate(M_bus_left_side, glm::vec3(-Bus::WIDTH / 2, Bus::FLOOR_HEIGHT, -Bus::REAR_AXLE_TO_FRONT + 1.2f));
	M_bus_left_side = glm::scale(M_bus_left_side, glm::vec3(0.05f, Bus::ROOF_HEIGHT - Bus::FLOOR_HEIGHT, Bus::REAR_AXLE_TO_BACK + Bus::REAR_AXLE_TO_FRONT - 1.2f));

	M_bus_right_side = unit;
	M_bus_right_side = glm::translate(M_bus_right_side, glm::vec3(Bus::WIDTH / 2 - 0.05f, Bus::FLOOR_HEIGHT, -Bus::REAR_AXLE_TO_FRONT + 1.5f));
	M_bus_right_side = glm::scale(M_bus_right_side, glm::vec3(0.05f, Bus::ROOF_HEIGHT - Bus::FLOOR_HEIGHT, Bus::REAR_AXLE_TO_BACK + Bus::REAR_AXLE_TO_FRONT - 1.5f));

	M_bus_roof = unit;
	M_bus_roof = glm::translate(M_bus_roof, glm::vec3(-Bus::WIDTH / 2, Bus::ROOF_HEIGHT, -Bus::REAR_AXLE_TO_FRONT));
	M_bus_roof = glm::scale(M_bus_roof, glm::vec3(Bus::WIDTH, 0.05f, Bus::REAR_AXLE_TO_BACK + Bus::REAR_AXLE_TO_FRONT));

	M_bus_drivers_side_bottom_panel = unit;
	M_bus_drivers_side_bottom_panel = glm::translate(M_bus_drivers_side_bottom_panel, glm::vec3(-Bus::WIDTH / 2, Bus::FLOOR_HEIGHT, -Bus::REAR_AXLE_TO_FRONT + 0.1f));
	M_bus_drivers_side_bottom_panel = glm::scale(M_bus_drivers_side_bottom_panel, glm::vec3(0.05f, 0.6f, 1.1f));

	M_bus_drivers_side_top_panel = unit;
	M_bus_drivers_side_top_panel = glm::translate(M_bus_drivers_side_top_panel, glm::vec3(-Bus::WIDTH / 2, Bus::ROOF_HEIGHT - 0.5f, -Bus::REAR_AXLE_TO_FRONT + 0.1f));
	M_bus_drivers_side_top_panel = glm::scale(M_bus_drivers_side_top_panel, glm::vec3(0.05f, 0.5f, 1.1f));

	M_bus_passenger_side_top_panel = unit;
	M_bus_passenger_side_top_panel = glm::translate(M_bus_passenger_side_top_panel, glm::vec3(Bus::WIDTH / 2 - 0.05f, Bus::ROOF_HEIGHT - 0.5f, -Bus::REAR_AXLE_TO_FRONT + 0.3f));
	M_bus_passenger_side_top_panel = glm::scale(M_bus_passenger_side_top_panel, glm::vec3(0.05f, 0.5f, 1.2f));

	M_bus_dashboard = unit;
	M_bus_dashboard = glm::translate(M_bus_dashboard, glm::vec3(-Bus::WIDTH / 2 + 0.1f, Bus::FLOOR_HEIGHT + 0.65f, -Bus::REAR_AXLE_TO_FRONT));
	M_bus_dashboard = glm::rotate(M_bus_dashboard, glm::pi<float>() / 12, glm::vec3(1.0f, 0.0f, 0.0f));
	M_bus_dashboard = glm::scale(M_bus_dashboard, glm::vec3(Bus::WIDTH / 1.2 - 0.1f, 0.05f, 0.5f));

	M_bus_door = unit;
	M_bus_door = glm::translate(M_bus_door, glm::vec3(Bus::WIDTH / 2 - 0.05f, Bus::FLOOR_HEIGHT, -Bus::REAR_AXLE_TO_FRONT + 0.3f));
	M_bus_door = glm::scale(M_bus_door, glm::vec3(0.05f, Bus::ROOF_HEIGHT - Bus::FLOOR_HEIGHT - 0.5f, 1.2f));

	M_bus_windscreen = unit;
	M_bus_windscreen = glm::translate(M_bus_windscreen, glm::vec3(-Bus::WIDTH / 2, Bus::ROOF_HEIGHT - 0.5f, -Bus::REAR_AXLE_TO_FRONT + 0.02f));
	M_bus_windscreen = glm::scale(M_bus_windscreen, glm::vec3(Bus::WIDTH - 0.1f, Bus::ROOF_HEIGHT - 1.2f, 1.0f));
	M_bus_windscreen = glm::rotate(M_bus_windscreen, glm::pi<float>() / 2, glm::vec3(1.0f, 0.0f, 0.0f));

	M_bus_window = unit;
	M_bus_window = glm::translate(M_bus_window, glm::vec3(-Bus::WIDTH / 2 + 0.01f, 0.6f, -Bus::REAR_AXLE_TO_FRONT + 0.1f));
	M_bus_window = glm::scale(M_bus_window, glm::vec3(1.0f, Bus::ROOF_HEIGHT - 1.1f, 1.1f));
	M_bus_window = glm::rotate(M_bus_window, -glm::pi<float>() / 2, glm::vec3(1.0f, 0.0f, 0.0f));
	M_bus_window = glm::rotate(M_bus_window, -glm::pi<float>() / 2, glm::vec3(0.0f, 0.0f, 1.0f));
}

void setupRoadBaseMatrices() {
	glm::mat4 unit = glm::mat4(1.0f);

	M_road_base = unit;
	M_road_base = glm::scale(M_road_base, glm::vec3(Road::EFFECTIVE_ROAD_WIDTH, 1.0f, RoadSegment::LENGTH));
	M_road_base = glm::rotate(M_road_base, glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f));
	M_road_base = glm::translate(M_road_base, glm::vec3(-0.5f, 0.0f, 0.0f));

	M_road_left_sidewalk_base = unit;
	M_road_left_sidewalk_base = glm::translate(M_road_left_sidewalk_base, glm::vec3(-Road::EFFECTIVE_ROAD_WIDTH / 2 - 3.0f, 0.0f, 0.0f));
	M_road_left_sidewalk_base = glm::scale(M_road_left_sidewalk_base, glm::vec3(3.0f, 0.1f, RoadSegment::LENGTH));
	M_road_left_sidewalk_base = glm::rotate(M_road_left_sidewalk_base, glm::pi<float>() / 2, glm::vec3(0.0f, 1.0f, 0.0f));

	M_road_right_sidewalk_base = unit;
	M_road_right_sidewalk_base = glm::translate(M_road_right_sidewalk_base, glm::vec3(Road::EFFECTIVE_ROAD_WIDTH / 2, 0.0f, 0.0f));
	M_road_right_sidewalk_base = glm::scale(M_road_right_sidewalk_base, glm::vec3(3.0f, 0.1f, RoadSegment::LENGTH));
	M_road_right_sidewalk_base = glm::rotate(M_road_right_sidewalk_base, glm::pi<float>() / 2, glm::vec3(0.0f, 1.0f, 0.0f));

	M_road_left_buildings_base = unit;
	M_road_left_buildings_base = glm::translate(M_road_left_buildings_base, glm::vec3(-Road::EFFECTIVE_ROAD_WIDTH / 2 - 3.0f, 0.0f, 0.0f));
	M_road_left_buildings_base = glm::scale(M_road_left_buildings_base, glm::vec3(1.0f, 20.0f, RoadSegment::LENGTH));
	M_road_left_buildings_base = glm::rotate(M_road_left_buildings_base, -glm::pi<float>() / 2, glm::vec3(0.0f, 0.0f, 1.0f));
	M_road_left_buildings_base = glm::rotate(M_road_left_buildings_base, glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f));

	M_road_right_buildings_base = unit;
	M_road_right_buildings_base = glm::translate(M_road_right_buildings_base, glm::vec3(Road::EFFECTIVE_ROAD_WIDTH + 3.0f, 0.0f, 0.0f));
	M_road_right_buildings_base = glm::scale(M_road_right_buildings_base, glm::vec3(1.0f, 20.0f, -RoadSegment::LENGTH));
	M_road_right_buildings_base = glm::rotate(M_road_right_buildings_base, glm::pi<float>() / 2, glm::vec3(0.0f, 0.0f, 1.0f));

	M_road_station_pillar_base = unit;
	M_road_station_pillar_base = glm::translate(M_road_station_pillar_base, glm::vec3(Road::EFFECTIVE_ROAD_WIDTH / 2 + 2.0f, 0.1f, -172.5f));
	M_road_station_pillar_base = glm::scale(M_road_station_pillar_base, glm::vec3(0.2f, 2.6f, 5.0f));
	M_road_station_pillar_base = glm::rotate(M_road_station_pillar_base, glm::pi<float>() / 2, glm::vec3(0.0f, 1.0f, 0.0f));
}

void setupControlBoardMatrices() {
	glm::mat4 unit = glm::mat4(1.0f);

	m_control_board_panel = unit;
	m_control_board_panel = glm::scale(unit, glm::vec3(0.16f, 1.0f, 0.8f));

	m_control_board_passenger_tens = unit;
	m_control_board_passenger_tens = glm::translate(m_control_board_passenger_tens, glm::vec3(0.01f, 0.001f, 0.04f));
	m_control_board_passenger_tens = glm::scale(m_control_board_passenger_tens, glm::vec3(0.1f, 1.0f, 0.1f));

	m_control_board_passenger_ones = unit;
	m_control_board_passenger_ones = glm::translate(m_control_board_passenger_ones, glm::vec3(0.01f, 0.002f, 0.11f));
	m_control_board_passenger_ones = glm::scale(m_control_board_passenger_ones, glm::vec3(0.1f, 1.0f, 0.1f));

	m_control_board_fines_tens = unit;
	m_control_board_fines_tens = glm::translate(m_control_board_fines_tens, glm::vec3(0.01f, 0.001f, 0.22f));
	m_control_board_fines_tens = glm::scale(m_control_board_fines_tens, glm::vec3(0.1f, 1.0f, 0.1f));

	m_control_board_fines_ones = unit;
	m_control_board_fines_ones = glm::translate(m_control_board_fines_ones, glm::vec3(0.01f, 0.002f, 0.29f));
	m_control_board_fines_ones = glm::scale(m_control_board_fines_ones, glm::vec3(0.1f, 1.0f, 0.1f));


	m_control_board_control = unit;
	m_control_board_control = glm::translate(m_control_board_control, glm::vec3(0.01f, 0.001f, 0.5f));
	m_control_board_control = glm::scale(m_control_board_control, glm::vec3(0.1f, 1.0f, 0.1f));


	m_control_board_door = unit;
	m_control_board_door = glm::translate(m_control_board_door, glm::vec3(0.025f, 0.001f, 0.66f));
	m_control_board_door = glm::scale(m_control_board_door, glm::vec3(0.08f, 1.0f, 0.08f));



	glm::mat4 mover = unit;
	mover = glm::translate(mover, glm::vec3(-0.4f, 0.7f + Bus::FLOOR_HEIGHT, -Bus::REAR_AXLE_TO_FRONT + 0.1f));
	mover = glm::rotate(mover, glm::pi<float>() / 3, glm::vec3(0.0f, 1.0f, 0.0f));
	mover = glm::rotate(mover, glm::pi<float>() / 3, glm::vec3(0.0f, 0.0f, 1.0f));


	m_control_board_panel = mover * m_control_board_panel;
	m_control_board_passenger_tens = mover * m_control_board_passenger_tens;
	m_control_board_passenger_ones = mover * m_control_board_passenger_ones;
	m_control_board_fines_tens = mover * m_control_board_fines_tens;
	m_control_board_fines_ones = mover * m_control_board_fines_ones;

	m_control_board_control = mover * m_control_board_control;
	m_control_board_door = mover * m_control_board_door;
}