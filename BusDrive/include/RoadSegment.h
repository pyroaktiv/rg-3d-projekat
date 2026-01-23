#pragma once

#include <glm/glm.hpp>

class RoadSegment {
private:
	glm::vec3 _position{ {},{},{} };
public:
	static constexpr float LENGTH{ 300.0f };

	const glm::vec3& position{ _position };

	void updateZ(float);
};