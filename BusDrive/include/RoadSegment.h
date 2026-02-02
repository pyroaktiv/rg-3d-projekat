#pragma once

#include <glm/glm.hpp>

class RoadSegment {
private:
	glm::vec3 _position{ {},{},{} };
public:
	static constexpr float LENGTH{ 300.0f };

	void updateZ(float);

	glm::vec3 getPosition();
};