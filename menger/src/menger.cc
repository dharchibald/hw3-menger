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
	// Triangle 0,1,2 - backface
	obj_vertices.push_back(glm::vec4(min_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(0, 1, 2));

	// Triangle 1,2,3 - backface
	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance + min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, max_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(3, 4, 5));

	// Triangle 4,5,6 - frontface
	obj_vertices.push_back(glm::vec4(min_bounds.x, min_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(6, 7, 8));

	// Triangle 5,6,7 - frontface
	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(9, 10, 11));

	// Triangle 5,1,7 - rightface
	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(12, 13, 14));

	// Triangle 1,7,3 - rightface
	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, max_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(15, 16, 17));

	// Triangle 4,0,6 - leftface
	obj_vertices.push_back(glm::vec4(min_bounds.x, min_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(18, 19, 20));

	// Triangle 0,6,2 - leftface
	obj_vertices.push_back(glm::vec4(min_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(21, 22, 23));

	// Triangle 6,7,2 - topface
	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(24, 25, 26));

	// Triangle 7,2,3 - topface
	obj_vertices.push_back(glm::vec4(max_bounds.x, max_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, max_bounds.y, distance + min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, max_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(27, 28, 29));

	// Triangle 4,5,0 - bottomface
	obj_vertices.push_back(glm::vec4(min_bounds.x, min_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, -1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, -1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, -1.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(30, 31, 32));

	// Triangle 5,0,1 - bottomface
	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance - min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max_bounds.x, min_bounds.y, distance + min_bounds.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, -1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, -1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, -1.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(33, 34, 35));

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

