#include "../../include/vertices/road.h"
#include "../../include/RoadSegment.h"
#include "../../include/Road.h"

std::vector<float> v_road = {
	-Road::EFFECTIVE_ROAD_WIDTH / 2, 0.0f, 0.0f,		0.5f, 0.5f, 0.5f, 1.0f,			0.0f, 0.0f,
	Road::EFFECTIVE_ROAD_WIDTH / 2, 0.0f, 0.0f,			0.5f, 0.5f, 0.5f, 1.0f, 		1.0f, 0.0f,
	Road::EFFECTIVE_ROAD_WIDTH / 2, 0.0f, RoadSegment::LENGTH,		0.5f, 0.5f, 0.5f, 1.0f,			1.0f, RoadSegment::LENGTH,
	-Road::EFFECTIVE_ROAD_WIDTH / 2, 0.0f, RoadSegment::LENGTH,		0.5f, 0.5f, 0.5f, 1.0f,			0.0f, RoadSegment::LENGTH
};