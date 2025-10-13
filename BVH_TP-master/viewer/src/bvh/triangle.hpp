#ifndef BVH_TRIANGLE_HPP
#define BVH_TRIANGLE_HPP

#include <vector>
#include "bvh/bbox.hpp"
#include "TriMesh.h"
#include "Vec.h"

class Triangle {
public:
    int indices[3];

    Triangle(const trimesh::TriMesh::Face& face)
        : indices{ face[0], face[1], face[2] }
    {
    }

    BBox bbox(const std::vector<trimesh::point>& vertices) const
    {
        BBox bbox{ vertices[indices[0]] };
        bbox.expand(vertices[indices[1]]);
        bbox.expand(vertices[indices[2]]);
        return bbox;
    }
};

#endif
