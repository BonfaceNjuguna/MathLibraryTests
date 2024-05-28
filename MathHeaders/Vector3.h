#pragma once
#include <string>

namespace MathClasses
{
    struct Vector3
    {
        float x, y, z;

        // Constructors
        Vector3();
        Vector3(float x3d, float y3d, float z3d);

        // Addition
        Vector3 operator+(const Vector3& rhs) const;
        Vector3& operator+=(const Vector3& rhs);

        // Subtraction
        Vector3 operator-(const Vector3& rhs) const;
        Vector3& operator-=(const Vector3& rhs);

        // Vector scalar multiplication
        Vector3 operator*(float scalar) const;
        friend Vector3 operator*(float scalar, const Vector3& lhs);
        Vector3& operator*=(float scalar);

        // Vector scalar division
        Vector3 operator/(float scalar) const;
        Vector3& operator/=(float scalar);

        // Magnitude
        float Magnitude() const;

        // Magnitude squared
        float MagnitudeSqr() const;

        // Vector normalization
        void Normalise();
        Vector3 Normalised() const;

        // Distance
        float Distance(const Vector3& other) const;

        // Dot product
        float Dot(const Vector3& other) const;

        // Cross product
        Vector3 Cross(const Vector3& other) const;

        // Equality operators
        bool operator==(const Vector3& rhs) const;
        bool operator!=(const Vector3& rhs) const;

        //to string
        std::string ToString() const;
	};
}