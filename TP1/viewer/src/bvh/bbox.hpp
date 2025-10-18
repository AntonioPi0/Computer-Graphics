#ifndef BVH_BBOX_HPP
#define BVH_BBOX_HPP

#include <limits>
#include "bvh/vector.hpp"

#define infinity std::numeric_limits<float>::infinity()

class BBox {
public:
    Vector3f lower;
    float padding_0 = 0.f;
    Vector3f upper;
    float padding_1 = 0.f;

    BBox()
        : lower{ infinity }, upper{ -infinity }
    {
    }

    BBox(const Vector3f& lower, const Vector3f& upper)
        : lower{ lower }, upper{ upper }
    {
    }

    BBox(const Vector3f& point)
        : lower{ point }, upper{ point }
    {
    }

    Vector3f extent() const
    {
        return upper - lower;
    }

    Vector3f centroid() const
    {
        return 0.5f * (lower + upper);
    }

    float area() const
    {
        const Vector3f ext = extent();
        return 2.f * (ext.x * ext.y + ext.x * ext.z + ext.y * ext.z);
    }

    int maxDimension() const
    {
        const Vector3f ext = extent();
        int dim = 0;
        if (ext.y > ext[dim]) dim = 1;
        if (ext.z > ext[dim]) dim = 2;
        return dim;
    }

    void expand(const Vector3f& point)
    {
        lower = min(lower, point);
        upper = max(upper, point);
    }

    void expand(const BBox& bbox)
    {
        lower = min(lower, bbox.lower);
        upper = max(upper, bbox.upper);
    }
};

#endif
