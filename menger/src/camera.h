#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera {
public:
	glm::mat4 get_view_matrix() const;
	// FIXME: add functions to manipulate camera objects.
	void translatePos (glm::vec3 pan);
	void rotateX (float x);
	void rotateY (float y);
	void rotateZ (float z);
private:
	float camera_distance_ = 3.0;
	glm::vec3 look_ = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up_ = glm::vec3(0.0f, 1.0, 0.0f);
	glm::vec3 right_ = glm::vec3(1.0f, 0.0f, 0.0f);

	glm::vec3 eye_ = glm::vec3(0.0f, 0.0f, camera_distance_);
	glm::vec3 at_ = glm::vec3(0.0f, 0.0f, 0.0f);

	glm::mat4 rotate = glm::mat4(1.0f);
	glm::mat4 translate = glm::mat4(1.0f);
};

#endif
