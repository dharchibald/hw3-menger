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
	glm::vec3 tgt = translate * rotate * glm::vec4(eye_, 1.0f);
	glm::vec3 cam = translate * rotate * glm::vec4(at_, 1.0f);

	// Define axes of new coordinate system
	glm::vec3 look_ = glm::normalize(tgt - cam);
	glm::vec3 right_ = glm::normalize(glm::cross(up_, look_));
	glm::vec3 up_ = glm::normalize(glm::cross(right_, look_));

	// Generate view matrix
	return  glm::mat4(right_.x, right_.y, right_.z, glm::dot(-right_, eye_), 
					  up_.x,    up_.y,    up_.z,    glm::dot(-up_, eye_),
					  look_.x,  look_.y,  look_.z,  glm::dot(-look_, eye_),
					  0.0f,     0.0f,     0.0f,     1.0f);

	// return glm::mat4(1.0);
}

void Camera::translatePos (glm::vec3 pan) {
	printf("Pan: (%f, %f, %f)\n", pan.x, pan.y, pan.z);
	translate *= glm::translate((pan.x * right_ + pan.y * up_ + pan.z * look_) * pan_speed);
	printf("Translate: (%f, %f, %f)\n", translate[0][3], translate[1][3], translate[2][3]);
}

void Camera::rotateX (float x) {
	rotate *= glm::rotate(rotation_speed * x, up_);
}

void Camera::rotateY (float y) {
	rotate *= glm::rotate(rotation_speed * y, right_);
}

void Camera::rotateZ (float z) {
	look_ = glm::normalize(at_ - eye_);
	right_ = glm::normalize(glm::cross(up_, look_));
	up_ = glm::normalize(glm::cross(right_, look_));
}