#pragma once

#include <vector>
#include "RoadSegment.h"

class Road {
private:
	std::vector<RoadSegment> segments{ RoadSegment(), RoadSegment(), RoadSegment()};

	float _localOffset{ 0.0f }; 
public:
	static constexpr float MIN_STATION_RELATIVE_Z{ 170.0f };
	static constexpr float MAX_STATION_RELATIVE_Z{ 180.0f };

	static constexpr float EFFECTIVE_ROAD_WIDTH{ 16.0f };

	const float& localOffset{ _localOffset };

	void updateSegments(float);

	float getSegmentZ(int);
};