#ifndef BVH_BVH_HPP
#define BVH_BVH_HPP

#include <vector>
#include "bvh/bbox.hpp"
#include "bvh/triangle.hpp"
#include "TriMesh.h"
#include "Vec.h"

class BVH {
public:
    struct Node {
        BBox bbox;
        /* nbTriangles == 0 if interior node */
        int nbTriangles;
        /* index == indexFirstTriangle if leaf node else indexRightNode */
        int index;
        int padding[2] = { 0, 0 };
    };

    BVH(const std::vector<trimesh::point>& vertices, const std::vector<trimesh::TriMesh::Face>& faces)
        : vertices{ vertices }
    {
        triangles.reserve(faces.size());

        for (const auto& face : faces) {
            triangles.push_back({ face });
        }

        build();
    }

    const std::vector<Node>& getNodes() const {
        return nodes;
    }

    const std::vector<Triangle>& getTriangles() const {
        return triangles;
    }

private:
    const std::vector<trimesh::point>& vertices;
    std::vector<Node> nodes;
    std::vector<Triangle> triangles;

    void build();
    int build(int start, int end);
};

#endif
