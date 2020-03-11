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
	// Define axes of new coordinate system
	glm::vec3 z = glm::normalize(at_ - eye_);
	glm::vec3 x = glm::normalize(glm::cross(up_, z));
	glm::vec3 y = glm::normalize(glm::cross(x, z));

	// Generate view matrix
	return  glm::transpose(
			glm::mat4(x.x,  x.y,  x.z,  glm::dot(-x, eye_), 
					  y.x,  y.y,  y.z,  glm::dot(-y, eye_),
					  -z.x, -z.y, -z.z, glm::dot(z, eye_),
					  0.0f, 0.0f, 0.0f, 1.0f));
}

void Camera::translate (glm::vec3 pan) {
	// Don't need to update basis vectors
	glm::vec3 translate = (pan.x * right_ + pan.y * -up_ + pan.z * look_) * pan_speed;
	eye_ += translate;
	at_ += translate;    
}

void Camera::orbit (glm::vec2 dir) {
	// Rotate around y-axis and update look/right vector in space
	eye_ = glm::rotate(eye_, rotation_speed * dir.x, up_);
	look_ = glm::normalize(at_ - eye_);
	right_ = glm::normalize(glm::cross(look_, up_));

	// Rotate around x-axis and update look/up vector in space
	eye_ = glm::rotate(eye_, rotation_speed * dir.y, right_);
	look_ = glm::normalize(at_ - eye_);
	up_ = glm::cross(right_, look_);

	look_ = glm::normalize(look_);
	right_ = glm::normalize(right_);
	up_ = glm::normalize(up_);
	// printf("Look: (%f, %f, %f)\n", look_.x, look_.y, look_.z);
	// printf("Right: (%f, %f, %f)\n", right_.x, right_.y, right_.z);
	// printf("Up: (%f, %f, %f)\n\n", up_.x, up_.y, up_.z);
}

void Camera::zoom (float dist) {
	eye_ += dist * look_ * zoom_speed;
}

void Camera::rotateX (float x) {
	// rotate *= glm::rotate(rotation_speed * x, up_);
	// eye_ = glm::rotate(rotation_speed * x, up_) * glm::vec4(eye_, 1.0f);
}

void Camera::rotateY (float y) {
	// rotate *= glm::rotate(rotation_speed * y, right_);
	// eye_ = glm::rotate(rotation_speed * y, right_) * glm::vec4(eye_, 1.0f);
}