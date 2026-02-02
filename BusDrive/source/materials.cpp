#include "../include/materials.h"

Material roadMaterial = {
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	0.0f,
	1.0f
};

Material sidewalkMaterial = {
	glm::vec3(0.4f, 0.4f, 0.4f),
	glm::vec3(0.5f, 0.5f, 0.5f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	0.0f,
	1.0f
};

Material busStationMaterial = {
	glm::vec3(0.3f, 0.3f, 0.3f),
	glm::vec3(0.6f, 0.4f, 0.4f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	0.0f,
	1.0f
};


Material busMaterial = {
	glm::vec3(0.0f, 0.0f, 0.1f),
	glm::vec3(0.1, 0.1f, 0.4f),
	glm::vec3(0.3f, 0.3f, 0.3f),
	1.0f,
	1.0f
};

Material busFloorMaterial = {
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.2f, 0.2f, 0.2f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	0.0f,
	1.0f
};

Material busRoofMaterial = {
	glm::vec3(0.1f, 0.1f, 0.1f),
	glm::vec3(0.5f, 0.5f, 0.5f),
	glm::vec3(0.3f, 0.3f, 0.3f),
	3.0f,
	1.0f
};

Material busDashboardMaterial = {
	glm::vec3(0.3f, 0.3f, 0.3f),
	glm::vec3(0.1f, 0.1f, 0.1f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	0.0f,
	1.0f
};


Material busDoorMaterial = {
	glm::vec3(0.3f, 0.3f, 0.3f),
	glm::vec3(0.3f, 0.3f, 0.3f),
	glm::vec3(0.3f, 0.3f, 0.3f),
	10.0f,
	0.7f
};