#pragma once
#include <string>

namespace MathClasses
{
    struct Vector4
    {
        float x, y, z, w;

        // Constructors
        Vector4();
        Vector4(float x4d, float y4d, float z4d, float w4d);

        // Addition
        Vector4 operator+(const Vector4& rhs) const;
        Vector4& operator+=(const Vector4& rhs);

        // Subtraction
        Vector4 operator-(const Vector4& rhs) const;
        Vector4& operator-=(const Vector4& rhs);

        // Vector scalar multiplication
        Vector4 operator*(float scalar) const;
        friend Vector4 operator*(float scalar, const Vector4& lhs);
        Vector4& operator*=(float scalar);

        // Vector scalar division
        Vector4 operator/(float scalar) const;
        Vector4& operator/=(float scalar);

        // Magnitude
        float Magnitude() const;

        // Magnitude squared
        float MagnitudeSqr() const;

        // Vector normalization
        void Normalise();
        Vector4 Normalised() const;

        // Distance
        float Distance(const Vector4& other) const;

        // Dot product
        float Dot(const Vector4& other) const;

        // Cross product
        Vector4 Cross(const Vector4& other) const;

        // Equality operators
        bool operator==(const Vector4& rhs) const;
        bool operator!=(const Vector4& rhs) const;

        //to string
        std::string ToString() const;
	};
}