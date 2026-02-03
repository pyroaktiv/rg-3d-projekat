#pragma once

#include <gl/glew.h>
#include <glfw/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

class Bus {
private:
	static constexpr float pi{ glm::pi<float>() };

	double lastRegisteredTime{glfwGetTime()};

	bool isWithinBounds(float, float) const;
	bool isNearStation() const;

	glm::vec3 _pos{ {},{},{} };
	float _yaw{ 0.0f };
	float _steeringAngle{ 0.0f };
	float _v{ 0.0f };

	bool _doorsOpen{ false };

public:

	static constexpr float MAX_DECELERATION{ 8.0f };
	static constexpr float MAX_ACCELERATION{ 2.5f };
	static constexpr float MAX_VELOCITY{ 13.89f };
	static constexpr float MAX_REVERSE_VELOCITY{ 1.0f };
	static constexpr float MAX_STEERING_SPEED_TURNING{ 3 * pi / 2 };

	static constexpr float MAX_STEERING_ANGLE{ pi / 4 };

	static constexpr float WHEELBASE{ 6.9f };
	static constexpr float REAR_AXLE_TO_BACK{ 3.4f };
	static constexpr float REAR_AXLE_TO_FRONT{ 9.6f };
	static constexpr float WIDTH{ 2.5f };
	static constexpr float FLOOR_HEIGHT{ 0.35f };
	static constexpr float ROOF_HEIGHT{ 3.0f };

	static constexpr glm::vec3 CAMERA_POS = glm::vec3(-0.7f, 1.0f + FLOOR_HEIGHT, -8.6f);

	static constexpr float STEERING_TURNING_CONSTANT{ 0.2f };
	static constexpr float STEERING_CENTERING_CONSTANT{ 0.2f };
	static constexpr float ACCELERATION_CONSTANT{ 0.3f };
	static constexpr float COASTING_CONSTANT{ 1.5f };

	const glm::vec3& pos{ _pos };
	const float& yaw{ _yaw };
	const float& steeringAngle{ _steeringAngle };
	const float& v{ _v };
	const bool& doorsOpen{ _doorsOpen };

	void doStateStep();

	void openDoors();
	void closeDoors();
};