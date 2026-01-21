#include <glm/gtc/matrix_transform.hpp>

#include "../include/FpsCamera.h"
#include "../include/util.h"
#include "../include/globals.h"

FpsCamera::FpsCamera() {
	updateDirection();
}

float
FpsCamera::getYaw() const {
	return yaw;
}

float
FpsCamera::getPitch() const {
	return pitch;
}

void
FpsCamera::setYaw(float yaw) {
	float angle = glm::clamp(wrapAngle(yaw), -pi + 0.01f, -0.01f);

	this->yaw = angle;

	updateDirection();
}

void
FpsCamera::setPitch(float pitch) {
	float angle = glm::clamp(wrapAngle(pitch), -pi / 2, pi / 2);

	this->pitch = angle;

	updateDirection();
}

void
FpsCamera::setScreenSize(float width, float height) {
	screenWidth = width;
	screenHeight = height;
}

glm::vec3
FpsCamera::getAt() const {
	return pos + direction;
}

glm::mat4
FpsCamera::getViewMatrix() const {
	return glm::lookAt(pos, getAt(), UP);
}

glm::mat4
FpsCamera::getProjectionMatrix() const {
	return projection;
}

void
FpsCamera::setOrtho() {
	projection = glm::ortho(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_BOTTOM, ORTHO_TOP, ORTHO_NEAR, ORTHO_FAR);
}

void
FpsCamera::setPersp() {
	projection = glm::perspective(PERSP_FOV, screenWidth / screenHeight, PERSP_NEAR, PERSP_FAR);
}

void
FpsCamera::updateDirection() {
	direction.x = cos(this->yaw) * cos(this->pitch);
	direction.y = sin(this->pitch);
	direction.z = sin(this->yaw) * cos(this->pitch);

	direction = glm::normalize(direction);
}