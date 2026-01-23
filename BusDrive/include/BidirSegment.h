#pragma once

#include <glm/glm.hpp>

struct BidirSegment {
	glm::vec3 a;
	glm::vec3 b;

	float precedingTotal;
	float reversePrecedingTotal;

	float getLength() const {
		return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
	}
};