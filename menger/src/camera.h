#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera {
public:
	glm::mat4 get_view_matrix() const;
	// FIXME: add functions to manipulate camera objects.
	void translate (glm::vec3 pan);
	void orbit (glm::vec2 dir);
	void rotate (glm::vec2 dir);
	void roll (float degree);
	void zoom (float dist);
	bool isFPSmode () const;
	void toggleFPS ();

private:
	bool fps_mode = false;
	float camera_distance_ = 3.0;
	glm::vec3 look_ = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up_ = glm::vec3(0.0f, 1.0, 0.0f);
	glm::vec3 right_ = glm::vec3(1.0f, 0.0f, 0.0f);

	glm::vec3 eye_ = glm::vec3(0.0f, 0.0f, camera_distance_);
	glm::vec3 at_ = glm::vec3(0.0f, 0.0f, 0.0f);
};

#endif
