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
	// glm::vec3 cam = glm::vec4(eye_, 1.0f);
	// glm::vec3 tgt = glm::vec4(at_, 1.0f);

	// Define axes of new coordinate system
	glm::vec3 look_ = glm::normalize(at_ - eye_);
	glm::vec3 right_ = glm::normalize(glm::cross(up_, look_));
	glm::vec3 up_ = glm::normalize(glm::cross(right_, look_));

	// Generate view matrix
	return  glm::transpose(
			glm::mat4(right_.x, right_.y, right_.z, glm::dot(-right_, eye_), 
					  up_.x,    up_.y,    up_.z,    glm::dot(-up_, eye_),
					  -look_.x, -look_.y, -look_.z, glm::dot(look_, eye_),
					  0.0f,     0.0f,     0.0f,     1.0f));
}

void Camera::translate (glm::vec3 pan) {
	// translate *= glm::translate((pan.x * right_ + pan.y * up_ + pan.z * look_) * pan_speed);
	// printf("Translate:\n");
	// for (int i = 0; i < 4; ++i) {
	// 	for (int j = 0; j < 4; ++j) {
	// 		printf("%f ", translate[i][j]);
	// 	}
	// 	printf("\n");
	// }
	glm::vec3 translate = (pan.x * right_ + pan.y * up_ + pan.z * look_) * pan_speed;
	eye_ += translate;
	at_ += translate;
}

void Camera::orbit (glm::vec2 dir) {
	glm::mat4 rotateX = glm::rotate(rotation_speed * dir.x, up_);
	glm::mat4 rotateY = glm::rotate(rotation_speed * dir.y, right_);
	glm::mat4 orbit = glm::translate(at_) * rotateY * rotateX * glm::translate(-at_);
	eye_ = orbit * glm::vec4(eye_, 1.0f);
	at_ = orbit * glm::vec4(at_, 1.0f);
}

void Camera::rotateX (float x) {
	// rotate *= glm::rotate(rotation_speed * x, up_);
	// eye_ = glm::rotate(rotation_speed * x, up_) * glm::vec4(eye_, 1.0f);
}

void Camera::rotateY (float y) {
	// rotate *= glm::rotate(rotation_speed * y, right_);
	// eye_ = glm::rotate(rotation_speed * y, right_) * glm::vec4(eye_, 1.0f);
}