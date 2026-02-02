#include <glm/gtc/matrix_transform.hpp>

#include "../include/matrices.h"
#include "../include/matrices/bus_matrices.h"
#include "../include/matrices/road_matrices.h"

#include "../include/Road.h"
#include "../include/RoadSegment.h"
#include "../include/Bus.h"

void setupMatrices() {
	setupBusMatrices();
	setupRoadBaseMatrices();
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
	M_bus_dashboard = glm::scale(M_bus_dashboard, glm::vec3(Bus::WIDTH / 2 - 0.1f, 0.05f, 0.5f));

	M_bus_door = unit;
	M_bus_door = glm::translate(M_bus_door, glm::vec3(Bus::WIDTH / 2 - 0.05f, Bus::FLOOR_HEIGHT, -Bus::REAR_AXLE_TO_FRONT + 0.3f));
	M_bus_door = glm::scale(M_bus_door, glm::vec3(0.05f, Bus::ROOF_HEIGHT - Bus::FLOOR_HEIGHT - 0.5f, 1.2f));
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