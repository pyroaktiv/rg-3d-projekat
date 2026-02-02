
#include "../include/Road.h"
#include "../include/RoadSegment.h"

void
Road::updateSegments(float busZ) {
	_localOffset = fmod(-busZ, RoadSegment::LENGTH);

	if (_localOffset < 0) {
		_localOffset += RoadSegment::LENGTH;
	}

	for (int i = 0; i < 3; i++) {

		float relativeZ = (i - 1) * RoadSegment::LENGTH + _localOffset;
		segments[i].updateZ(relativeZ);
	}
}

float
Road::getSegmentZ(int i) {
	return segments[i].getPosition().z;
}