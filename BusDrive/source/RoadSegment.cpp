#include "../include/RoadSegment.h"

void
RoadSegment::updateZ(float z) {
	_position.z = z;
}

glm::vec3
RoadSegment::getPosition() {
	return _position;
}