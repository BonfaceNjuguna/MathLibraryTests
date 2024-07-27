#pragma once
#include "Vector4.h"
#include "Vector3.h"
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

namespace MathClasses
{
    struct Matrix4
    {
        // Matrix elements
        float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;

        // Constructors
        Matrix4();
        Matrix4(float m1, float m2, float m3, float m4,
            float m5, float m6, float m7, float m8,
            float m9, float m10, float m11, float m12,
            float m13, float m14, float m15, float m16);
        Matrix4(const float* elements);

        // Static identity matrix
        static const Matrix4 identity;

        // Matrix-vector multiplication
        Matrix4 operator*(const Matrix4& rhs) const;
        Vector4 operator*(const Vector4& rhs) const;

        // Matrix addition and subtraction
        bool operator==(const Matrix4& rhs) const;
        bool operator!=(const Matrix4& rhs) const;

        // Helper function to round to a certain number of decimal places
        static float RoundToMat4(float value, int decimalPlaces);

        // Set methods
        void Set(const Matrix4& m);
        void Set(float m1, float m2, float m3, float m4,
            float m5, float m6, float m7, float m8,
            float m9, float m10, float m11, float m12,
            float m13, float m14, float m15, float m16);

        // Scaling
        void SetScaled(float x, float y, float z, float w);
        void SetScaled(const Vector4& v);
        void Scale(float x, float y, float z, float w);
        void Scale(const Vector4& v);

        // Rotation
        void SetRotateX(double radians);
        void SetRotateY(double radians);
        void SetRotateZ(double radians);
        void RotateX(double radians);
        void RotateY(double radians);
        void RotateZ(double radians);
        void SetRotated(float pitch, float yaw, float roll);

        // Translation
        void SetTranslation(float x, float y, float z);
        void Translate(float x, float y, float z);
        void Translate(const Vector4& v);

        // Static factory methods
        static Matrix4 MakeIdentity();
        static Matrix4 MakeTranslation(float x, float y, float z);
        static Matrix4 MakeTranslation(const Vector3& v);
        static Matrix4 MakeRotateX(float radians);
        static Matrix4 MakeRotateY(float radians);
        static Matrix4 MakeRotateZ(float radians);
        static Matrix4 MakeEuler(float pitch, float yaw, float roll);
        static Matrix4 MakeEuler(const Vector3& euler);
        static Matrix4 MakeScale(float x, float y, float z);
        static Matrix4 MakeScale(const Vector3& v);

        // eplison comparison
        bool Equals(const Matrix4& other, float epsilon = 1e-5f) const;

         // ToString method
        std::string ToString() const;
    };

    std::ostream& operator<<(std::ostream& os, const Matrix4& m);
}