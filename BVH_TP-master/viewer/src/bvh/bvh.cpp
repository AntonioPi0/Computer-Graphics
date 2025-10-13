#include <algorithm>
#include "bvh/bvh.hpp"
#include "bvh/bbox.hpp"

const int LEAF_SIZE = 4;

void BVH::build()
{
    const int nbTriangles = triangles.size();
    nodes.reserve(2 * nbTriangles - 1);

    build(0, nbTriangles);

    nodes.shrink_to_fit();
}

int BVH::build(int start, int end)
{
    /* build node bounding box */
    BBox bbox;
    for (int i = start; i < end; ++i)
        bbox.expand(triangles[i].bbox(vertices));

    /* check if the node can be a leaf */
    const int nbTriangles = end - start;
    if (nbTriangles <= LEAF_SIZE) {
        /* add leaf node to the list */
        const int nodeIndex = nodes.size();
        nodes.push_back({ bbox, nbTriangles, start });
        return nodeIndex;
    }

    /* split the triangles along the largest axis */
    const int dim = bbox.maxDimension();

    /* try mid-point splitting */
    const float midCoord = bbox.centroid()[dim];
    const auto& it = std::partition(triangles.begin() + start,
                                    triangles.begin() + end,
                                    [this, dim, midCoord](const Triangle& p) {
                                        return p.bbox(vertices).centroid()[dim] < midCoord;
                                    });

    int middle = it - triangles.begin();

    /* if we have an empty child, we fall through median splitting */
    if (middle == start || middle == end) {
        middle = (start + end) / 2;
        std::nth_element(triangles.begin() + start,
                         triangles.begin() + middle,
                         triangles.begin() + end,
                         [this, dim](const Triangle& p, const Triangle& q) {
                            return p.bbox(vertices).centroid()[dim] < q.bbox(vertices).centroid()[dim];
                        });
    }

    /* NOTE: we could implement Surface Area Heuristic (SAH) for a better splitting */

    /* add interior node to the list, with unknown right index */
    const int nodeIndex = nodes.size();
    nodes.push_back({ bbox, 0, 0 });
    Node& node = nodes.back();

    /* build children & set right node index */
    build(start, middle);
    node.index = build(middle, end);

    return nodeIndex;
}
