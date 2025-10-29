#ifndef BVH_VECTOR_HPP
#define BVH_VECTOR_HPP

#include <cmath>
#include "Vec.h"

template <typename T>
class Vector3 {
public:
    T x, y, z;

    Vector3()
        : x{ 0 }, y{ 0 }, z{ 0 }
    {
    }

    Vector3(T x, T y, T z)
        : x{ x }, y{ y }, z{ z }
    {
    }

    Vector3(const trimesh::point& point)
        : x{ point[0] }, y{ point[1] }, z{ point[2] }
    {
    }

    Vector3(T value)
        : x{ value }, y{ value }, z{ value }
    {
    }

    T& operator[](int index) {
        if (index == 0) return x;
        if (index == 1) return y;
        return z;
    }

    const T& operator[](int index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        return z;
    }

    Vector3<T>& operator+=(const Vector3<T>& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;

        return *this;
    }

    Vector3<T>& operator-=(const Vector3<T>& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;

        return *this;
    }

    template <typename U>
    Vector3<T>& operator*=(U rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;

        return *this;
    }

    template <typename U>
    Vector3<T>& operator/=(U rhs)
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;

        return *this;
    }
};

template <typename T>
inline Vector3<T> operator-(const Vector3<T>& rhs)
{
    return Vector3<T>{ -rhs.x, -rhs.y, -rhs.z };
}

template <typename T>
inline Vector3<T> operator+(Vector3<T> lhs, const Vector3<T>& rhs)
{
    return lhs += rhs;
}

template <typename T>
inline Vector3<T> operator-(Vector3<T> lhs, const Vector3<T>& rhs)
{
    return lhs -= rhs;
}

template <typename T, typename U>
inline Vector3<T> operator*(Vector3<T> lhs, U rhs)
{
    return lhs *= rhs;
}

template <typename T, typename U>
inline Vector3<T> operator*(U lhs, Vector3<T> rhs)
{
    return rhs *= lhs;
}

template <typename T, typename U>
inline Vector3<T> operator/(Vector3<T> lhs, U rhs)
{
    return lhs /= rhs;
}

template <typename T>
inline Vector3<T> min(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
    return Vector3<T>{
        std::fmin(lhs.x, rhs.x),
        std::fmin(lhs.y, rhs.y),
        std::fmin(lhs.z, rhs.z)
    };
}

template <typename T>
inline Vector3<T> max(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
    return Vector3<T>{
        std::fmax(lhs.x, rhs.x),
        std::fmax(lhs.y, rhs.y),
        std::fmax(lhs.z, rhs.z)
    };
}

using Vector3f = Vector3<float>;

#endif
