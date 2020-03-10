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

void
Menger::create_menger(std::vector<glm::vec4>& obj_vertices,
					  std::vector<glm::vec4>& vtx_normals,
					  std::vector<glm::uvec3>& obj_faces,
					  glm::vec3 min,
					  glm::vec3 max) const
{
	unsigned long n_vtx = obj_vertices.size();

	// Square 0,1,2,3 - backface
	obj_vertices.push_back(glm::vec4(min.x, min.y, min.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max.x, min.y, min.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min.x, max.y, min.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max.x, max.y, min.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(n_vtx + 2, n_vtx,     n_vtx + 1));
	obj_faces.push_back(glm::uvec3(n_vtx + 1, n_vtx + 3, n_vtx + 2));

	// Square 4,5,6,7 - frontface
	obj_vertices.push_back(glm::vec4(min.x, min.y, max.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max.x, min.y, max.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min.x, max.y, max.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max.x, max.y, max.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(n_vtx + 6, n_vtx + 4, n_vtx + 5));
	obj_faces.push_back(glm::uvec3(n_vtx + 5, n_vtx + 7, n_vtx + 6));

	// Square 5,1,7,3 - rightface
	obj_vertices.push_back(glm::vec4(max.x, min.y, max.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max.x, min.y, min.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max.x, max.y, max.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max.x, max.y, min.z, 1.0f));
	vtx_normals.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(n_vtx + 10, n_vtx + 8,  n_vtx + 9));
	obj_faces.push_back(glm::uvec3(n_vtx + 9,  n_vtx + 11, n_vtx + 10));

	// Square 4,0,6,2 - leftface
	obj_vertices.push_back(glm::vec4(min.x, min.y, max.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min.x, min.y, min.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min.x, max.y, max.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min.x, max.y, min.z, 1.0f));
	vtx_normals.push_back(glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(n_vtx + 14, n_vtx + 12, n_vtx + 13));
	obj_faces.push_back(glm::uvec3(n_vtx + 13, n_vtx + 15, n_vtx + 14));

	// Square 6,7,2,3 - topface
	obj_vertices.push_back(glm::vec4(min.x, max.y, max.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max.x, max.y, max.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min.x, max.y, min.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max.x, max.y, min.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(n_vtx + 18, n_vtx + 16, n_vtx + 17));
	obj_faces.push_back(glm::uvec3(n_vtx + 17, n_vtx + 19, n_vtx + 18));

	// Triangle 4,5,0,1 - bottomface
	obj_vertices.push_back(glm::vec4(min.x, min.y, max.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max.x, min.y, max.z, 1.0f));
	obj_vertices.push_back(glm::vec4(min.x, min.y, min.z, 1.0f));
	obj_vertices.push_back(glm::vec4(max.x, min.y, min.z, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, -1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, -1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, -1.0f, 0.0f, 0.0f));
	vtx_normals.push_back(glm::vec4(0.0f, -1.0f, 0.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(n_vtx + 22, n_vtx + 20, n_vtx + 21));
	obj_faces.push_back(glm::uvec3(n_vtx + 21, n_vtx + 23, n_vtx + 22));
}

// FIXME generate Menger sponge geometry
void
Menger::generate_geometry(std::vector<glm::vec4>& obj_vertices,
						  std::vector<glm::vec4>& vtx_normals,
                          std::vector<glm::uvec3>& obj_faces) const
{
	// create_menger(obj_vertices, vtx_normals, obj_faces, min_bounds, max_bounds);
	// Do not actually construct cubes until end stage
	// Recursively narrow down pool of cubes to work with
	std::vector<glm::vec3> cube_pool;
	cube_pool.push_back(min_bounds);

	for (int i = 1; i <= nesting_level_; ++i) {
		std::vector<glm::vec3> temp;

		glm::vec3 length = (max_bounds - min_bounds) * (float)(1.0f / pow(3.0, i));
		glm::vec3 dx = glm::vec3(length.x, 0.0f, 0.0f);
		glm::vec3 dy = glm::vec3(0.0f, length.y, 0.0f);
		glm::vec3 dz = glm::vec3(0.0f, 0.0f, length.z);

		for (int cube = 0; cube < cube_pool.size(); ++cube) {
			// Store lower bound of all subcubes to be constructed
			glm::vec3 cube_bounds = cube_pool[cube];
			temp.push_back(cube_bounds);
			temp.push_back(cube_bounds + dx);
			temp.push_back(cube_bounds + 2.0f*dx);
			temp.push_back(cube_bounds + dy);
			temp.push_back(cube_bounds + dy + 2.0f*dx);
			temp.push_back(cube_bounds + 2.0f*dy);
			temp.push_back(cube_bounds + 2.0f*dy + dx);
			temp.push_back(cube_bounds + 2.0f*dy + 2.0f*dx);
			temp.push_back(cube_bounds + dz);
			temp.push_back(cube_bounds + dz + 2.0f*dx);
			temp.push_back(cube_bounds + dz + 2.0f*dy);
			temp.push_back(cube_bounds + dz + 2.0f*dy + 2.0f*dx);
			temp.push_back(cube_bounds + 2.0f*dz);
			temp.push_back(cube_bounds + 2.0f*dz + dx);
			temp.push_back(cube_bounds + 2.0f*dz + 2.0f*dx);
			temp.push_back(cube_bounds + 2.0f*dz + dy);
			temp.push_back(cube_bounds + 2.0f*dz + dy + 2.0f*dx);
			temp.push_back(cube_bounds + 2.0f*dz + 2.0f*dy);
			temp.push_back(cube_bounds + 2.0f*dz + 2.0f*dy + dx);
			temp.push_back(cube_bounds + 2.0f*dz + 2.0f*dy + 2.0f*dx);
		}
		cube_pool = temp;
	}

	glm::vec3 length = (max_bounds - min_bounds) * (float)(1.0f / pow(3.0, nesting_level_));
	for (int i = 0; i < cube_pool.size(); ++i) {
		create_menger(obj_vertices, vtx_normals, obj_faces, cube_pool[i], cube_pool[i] + length);
	}
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

