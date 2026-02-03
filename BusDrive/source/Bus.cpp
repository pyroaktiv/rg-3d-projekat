#include <glm/glm.hpp>
#include <vector>

#include "../include/Bus.h"
#include "../include/Road.h"
#include "../include/util.h"
#include "../include/globals.h"

void Bus::doStateStep() {
    double currentTime = glfwGetTime();
    float dt = static_cast<float>(currentTime - lastRegisteredTime);

    lastRegisteredTime = currentTime;

    float a = 0.0f;

    if (glfwGetKey(g_window, GLFW_KEY_W) == GLFW_PRESS && _doorsOpen == false) {
        a = MAX_ACCELERATION * glm::exp(ACCELERATION_CONSTANT * (_v / MAX_VELOCITY));
    }
    else if (glfwGetKey(g_window, GLFW_KEY_S) == GLFW_PRESS) {
        a = -MAX_DECELERATION;
    }
    else {
        a = -COASTING_CONSTANT * (glm::exp(_v / MAX_VELOCITY) - 1.0f) - 1.0f;
    }

    _v = glm::clamp(_v + (double)a * dt, 0.0, (double)MAX_VELOCITY);
    if (_v < 0.01) _v = 0.0;

    if (glfwGetKey(g_window, GLFW_KEY_A) == GLFW_PRESS) {
        _steeringAngle -= MAX_STEERING_SPEED_TURNING * glm::exp(-STEERING_TURNING_CONSTANT * _v) * dt;
    }

    else if (glfwGetKey(g_window, GLFW_KEY_D) == GLFW_PRESS) {
        _steeringAngle += MAX_STEERING_SPEED_TURNING * glm::exp(-STEERING_TURNING_CONSTANT * _v) * dt;
    }

    else {
        float centeringDirection = (_steeringAngle > 0) ? -1.0f : 1.0f;
        float centeringAmount = MAX_STEERING_SPEED_TURNING * 0.5f * dt;

        if (glm::abs(_steeringAngle) > centeringAmount) {
            _steeringAngle += centeringDirection * centeringAmount;
        }
        else {
            _steeringAngle = 0.0f;
        }
    }

    _steeringAngle = glm::clamp(_steeringAngle, -MAX_STEERING_ANGLE, MAX_STEERING_ANGLE);
    if (glm::abs(_steeringAngle) < 0.005f) _steeringAngle = 0.0f;

    float deltaYaw = (_v / WHEELBASE) * glm::tan(_steeringAngle) * dt;
    float nextYaw = wrapAngle(_yaw + deltaYaw);

    float dx = sin(nextYaw) * _v * dt;
    float dz = cos(nextYaw) * _v * dt;

    float nextX = _pos.x + dx;
    if (isWithinBounds(nextX, nextYaw)) {
        _pos.x = nextX;
        _yaw = nextYaw;
    }
    _pos.z -= dz;

    g_road.updateSegments(_pos.z);

    g_camera.pos = CAMERA_POS;
}

bool
Bus::isWithinBounds(float testX, float testYaw) const {
	std::vector<float> lateralOffsets = { -WIDTH / 2, WIDTH / 2 };
	std::vector<float> longitudinalOffsets = { REAR_AXLE_TO_BACK, -REAR_AXLE_TO_FRONT };

	float cosY = cos(testYaw);
	float sinY = sin(testYaw);

	for (float localX : lateralOffsets) {
		for (float localZ : longitudinalOffsets) {

			float cornerWorldX = testX + localX * cosY - localZ * sinY;

			if (glm::abs(cornerWorldX) > Road::EFFECTIVE_ROAD_WIDTH / 2) {
				return false;
			}
		}
	}
    return true;
}

bool
Bus::isNearStation() const {
    bool isAngleCorrect = _yaw >= -pi / 6 && _yaw <= pi / 6;
    bool isZOffsetCorrect = (g_road.localOffset - CAMERA_POS.z) >= Road::MIN_STATION_RELATIVE_Z
        && (g_road.localOffset - CAMERA_POS.z) <= Road::MAX_STATION_RELATIVE_Z;

    bool isXCorrect = _pos.x >= Road::EFFECTIVE_ROAD_WIDTH / 4;

    if (isAngleCorrect && isZOffsetCorrect && isXCorrect) {
        return true;
    }
    return false;
}

void
Bus::openDoors() {
    if (_v == 0 && isNearStation()) {
        _doorsOpen = true;
    }
    if (g_bunch.isControlInside) {
        g_bunch.disembarkControl();
    }
}

void
Bus::closeDoors() {
    if (g_bunch.boardingPassengers.empty() == true || g_bunch.disembarkingPassengers.empty() == true) {
        _doorsOpen = false;
    }
}