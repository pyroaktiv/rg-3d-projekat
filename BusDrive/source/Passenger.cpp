#include "../include/Passenger.h"
#include "../include/util.h"

void
Passenger::doStateStep() {

	if (_state == PASG_UNBOARDED || _state == PASG_BOARDED)
		return;

	double deltaT = glfwGetTime() - lastRegisteredTime;

	float deltaDist = V * deltaT;
	dist += deltaDist;

	// Boarding
	if (_state == PASG_BOARDING) {
		if (dist >= SHARED_PATH_LENGTH) {
			_state = PASG_BOARDED;
			return;
		}

		int seg = 0;

		while (seg < 3 && sharedPath[seg + 1].precedingTotal < dist)
			seg++;

		if (seg == 3 && _orientation != DIR_POS_Z)
			_orientation = DIR_POS_Z;

		float relDist = dist - sharedPath[seg].precedingTotal;
		float alpha = relDist / sharedPath[seg].getLength();

		_pos = glm::mix(sharedPath[seg].a, sharedPath[seg].b, alpha);
	}

	// Unboarding
	else {
		if (dist >= SHARED_PATH_LENGTH) {
			_state = PASG_UNBOARDED;
			return;
		}

		int seg = 3;

		while (seg > 0 && sharedPath[seg - 1].reversePrecedingTotal < dist)
			seg--;

		if (seg == 2 && _orientation != DIR_POS_X)
			_orientation = DIR_POS_X;

		float relDist = dist - sharedPath[seg].reversePrecedingTotal;
		float alpha = relDist / sharedPath[seg].getLength();

		_pos = glm::mix(sharedPath[seg].b, sharedPath[seg].a, alpha);
	}
}

void
Passenger::startBoarding() {
	if (_state == PASG_UNBOARDED) {
		scaleY = randomNumber(MIN_SCALE_Y, MAX_SCALE_Y);
		material = Material{
			glm::vec3(randomNumber(0.0f, 0.5f), randomNumber(0.0f, 0.5f), randomNumber(0.0f, 0.5f)),
			glm::vec3(randomNumber(0.0f, 0.5f), randomNumber(0.0f, 0.5f), randomNumber(0.0f, 0.5f)),
			glm::vec3(randomNumber(0.0f, 0.3f), randomNumber(0.0f, 0.3f), randomNumber(0.0f, 0.3f)),
			randomNumber(0.0f, 0.3f),
			1.0f
		};
		lastRegisteredTime = glfwGetTime();
		dist = 0.0f;
		_state = PASG_BOARDING;
		_orientation = DIR_NEG_X;
	}
}

void
Passenger::startDisembarking() {
	if (_state == PASG_BOARDED) {
		lastRegisteredTime = glfwGetTime();
		dist = 0.0f;
		_state = PASG_DISEMBARKING;
		_orientation = DIR_NEG_Z;
	}
}