#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

class FpsCamera {
private:

	static constexpr float pi{ glm::pi<float>() };

	float screenWidth;
	float screenHeight;

	float yaw{ -glm::pi<float>() / 2 };
	float pitch{};

	glm::vec3 direction;

	glm::mat4 projection;

	void updateDirection();

public:

	static constexpr float PERSP_FOV{ glm::radians(60.0f) };
	static constexpr float PERSP_NEAR{ 0.1f };
	static constexpr float PERSP_FAR{ 200.0f };

	static constexpr float ORTHO_LEFT{ -1.0f };
	static constexpr float ORTHO_RIGHT{ 1.0f };
	static constexpr float ORTHO_BOTTOM{ -1.0f };
	static constexpr float ORTHO_TOP{ 1.0f };
	static constexpr float ORTHO_NEAR{ 0.1f };
	static constexpr float ORTHO_FAR{ 200.0f };

	static constexpr float MIN_YAW{ -pi + 0.01f };
	static constexpr float MAX_YAW{ 0.01f };

	static constexpr float MIN_PITCH{ -pi / 2 + 0.01f };
	static constexpr float MAX_PITCH{ pi /2 + 0.01f };

	FpsCamera();

	glm::vec3 pos{ {},{},{} };

	static constexpr glm::vec3 UP{ glm::vec3(0.0f, 1.0f, 0.0f) };

	float getYaw() const;
	float getPitch() const;

	void setYaw(float);
	void setPitch(float);

	void setScreenSize(float, float);

	glm::vec3 getAt() const;

	glm::mat4 getViewMatrix() const;
	glm::mat4 getProjectionMatrix() const;
	void setOrtho();
	void setPersp();

	void handleMouseMovement(float, float, float);
};