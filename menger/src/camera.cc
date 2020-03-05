#include "camera.h"
#include <stdio.h>

namespace {
	float pan_speed = 0.1f;
	float roll_speed = 0.1f;
	float rotation_speed = 0.05f;
	float zoom_speed = 0.1f;
};

// FIXME: Calculate the view matrix
glm::mat4 Camera::get_view_matrix() const
{
	// Define axes of new coordinate system
	glm::vec3 z = glm::normalize(at_ - eye_);
	glm::vec3 x = glm::normalize(glm::cross(up_, z));
	glm::vec3 y = glm::normalize(glm::cross(x, z));

	// Generate view matrix
	return glm::mat4(x.x, x.y, x.z, glm::dot(-x, eye_), 
					 y.x, y.y, y.z, glm::dot(-y, eye_),
					 -z.x, -z.y, -z.z, glm::dot(z, eye_),
					 0.0f, 0.0f, 0.0f, 1.0f);

	// return glm::mat4(1.0);
}
