#include <glm/gtx/transform.hpp>
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
	// Apply transforms to points of interest
	glm::vec3 cam = (rotate * glm::vec4(eye_, 1));
	glm::vec3 tgt = (rotate * glm::vec4(at_, 1));

	// Define axes of new coordinate system
	glm::vec3 z = glm::normalize(tgt - cam);
	glm::vec3 x = glm::normalize(glm::cross(up_, z));
	glm::vec3 y = glm::normalize(glm::cross(x, z));

	// Generate view matrix
	return glm::mat4(x.x, x.y, x.z, glm::dot(-x, eye_), 
					 y.x, y.y, y.z, glm::dot(-y, eye_),
					 -z.x, -z.y, -z.z, glm::dot(z, eye_),
					 0.0f, 0.0f, 0.0f, 1.0f) * rotate;

	// return glm::mat4(1.0);
}


void Camera::rotateX (float x) {
	printf("Rotate X: %f\n", x);
	rotate *= glm::rotate(rotation_speed * x, right_);
	glm::vec3 cam = (rotate * glm::vec4(eye_, 1));
	glm::vec3 tgt = (rotate * glm::vec4(at_, 1));

	look_ = glm::normalize(tgt - cam);
	right_ = glm::normalize(glm::cross(up_, look_));
	up_ = glm::normalize(glm::cross(right_, look_));
}

void Camera::rotateY (float y) {
	printf("Rotate Y: %f\n", y);
	rotate *= glm::rotate(rotation_speed * y, up_);
	glm::vec3 cam = (rotate * glm::vec4(eye_, 1));
	glm::vec3 tgt = (rotate * glm::vec4(at_, 1));

	look_ = glm::normalize(tgt - cam);
	right_ = glm::normalize(glm::cross(up_, look_));
	up_ = glm::normalize(glm::cross(right_, look_));
}

void Camera::rotateZ (float z) {
	rotate = glm::rotate(rotation_speed * z, look_);
	look_ = glm::normalize(at_ - eye_);
	right_ = glm::normalize(glm::cross(up_, look_));
	up_ = glm::normalize(glm::cross(right_, look_));
}