#include <glm/gtx/rotate_vector.hpp>
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


void Camera::rotateX (float x) {
	eye_ = glm::rotate(eye_, rotation_speed * x, up_);
	printf("RotateX!!:\nEYE: (%f, %f, %f)\n", eye_.x, eye_.y, eye_.z);

	look_ = glm::normalize(at_ - eye_);
	right_ = glm::normalize(glm::cross(up_, look_));
	up_ = glm::normalize(glm::cross(right_, look_));
	printf("Look: (%f, %f, %f)\n", look_.x, look_.y, look_.z);
	printf("Right: (%f, %f, %f)\n", right_.x, right_.y, right_.z);
	printf("Up: (%f, %f, %f)\n", up_.x, up_.y, up_.z);
}

void Camera::rotateY (float y) {
	eye_ = glm::rotate(eye_, rotation_speed * y, right_);
	printf("RotateY!!:\nEYE: (%f, %f, %f)\n", eye_.x, eye_.y, eye_.z);

	look_ = glm::normalize(at_ - eye_);
	right_ = glm::normalize(glm::cross(up_, look_));
	up_ = glm::normalize(glm::cross(right_, look_));
	printf("Look: (%f, %f, %f)\n", look_.x, look_.y, look_.z);
	printf("Right: (%f, %f, %f)\n", right_.x, right_.y, right_.z);
	printf("Up: (%f, %f, %f)\n", up_.x, up_.y, up_.z);
}

void Camera::rotateZ (float z) {
	look_ = glm::normalize(at_ - eye_);
	right_ = glm::normalize(glm::cross(up_, look_));
	up_ = glm::normalize(glm::cross(right_, look_));
}