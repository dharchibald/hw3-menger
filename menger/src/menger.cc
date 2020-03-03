#include "menger.h"

namespace {
	const int kMinLevel = 0;
	const int kMaxLevel = 4;
};

const glm::vec3 min_bounds(-0.5, -0.5, -0.5);
const glm::vec3 max_bounds( 0.5,  0.5,  0.5);
const float distance = -5.0f;

Menger::Menger()
{
	// Add additional initialization if you like
}

Menger::~Menger()
{
}

void
Menger::set_nesting_level(int level)
{
	nesting_level_ = level;
	dirty_ = true;
}

bool
Menger::is_dirty() const
{
	return dirty_;
}

void
Menger::set_clean()
{
	dirty_ = false;
}

// FIXME generate Menger sponge geometry
void
Menger::generate_geometry(std::vector<glm::vec4>& obj_vertices,
						  std::vector<glm::vec4>& vtx_normals,
                          std::vector<glm::uvec3>& obj_faces) const
{
	// Can't avoid duplicate vertices for shared geometry?
	// Construct vertices in terms of triangles needed
	obj_vertices.push_back(glm::vec4(min_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(-third, -third, third, 0.0f));

	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(third, -third, third, 0.0f));

	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(-third, third, third, 0.0f));

	obj_vertices.push_back(glm::vec4(max_bounds.x, max_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(third, third, third, 0.0f));

	obj_vertices.push_back(glm::vec4(min_bounds.x, min_bounds.y, distance - min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(-third, -third, -third, 0.0f));

	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance - min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(third, -third, -third, 0.0f));

	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(-third, third, -third, 0.0f));

	obj_vertices.push_back(glm::vec4(max_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(third, third, -third, 0.0f));


	/* Back face */
	obj_faces.push_back(glm::uvec3(0, 1, 2));
	obj_faces.push_back(glm::uvec3(1, 2, 3));

	/* Front face */
	obj_faces.push_back(glm::uvec3(4, 5, 6));
	obj_faces.push_back(glm::uvec3(5, 6, 7));

	/* Right face */
	obj_faces.push_back(glm::uvec3(5, 1, 7));
	obj_faces.push_back(glm::uvec3(1, 7, 3));

	/* Left face */
	obj_faces.push_back(glm::uvec3(4, 0, 6));
	obj_faces.push_back(glm::uvec3(0, 6, 2));

	/* Top face */
	obj_faces.push_back(glm::uvec3(6, 7, 2));
	obj_faces.push_back(glm::uvec3(7, 2, 3));

	/* Bottom face */
	obj_faces.push_back(glm::uvec3(4, 5, 0));
	obj_faces.push_back(glm::uvec3(5, 0, 1));


	/*
	obj_vertices.push_back(glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(0.5f, -0.5f, -0.5f, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(0.0f, 0.5f, -0.5f, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(0, 1, 2));
	*/
}

