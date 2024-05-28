#pragma once
#include "Vector3.h"
#include <cmath>

namespace MathClasses
{
    struct Matrix3
    {
        float m1, m2, m3, m4, m5, m6, m7, m8, m9;

        // Constructors
        Matrix3();
        Matrix3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9);

        Matrix3(const float numbers[9]);

        static const Matrix3 identity;

        // Matrix multiplication
        Matrix3 operator*(const Matrix3& rhs) const;

        // Matrix-vector multiplication
        Vector3 operator*(const Vector3& rhs) const;

        // Set methods
        void Set(const Matrix3& m);
        void Set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9);

        // Scaling
        void SetScaled(float x, float y, float z);
        void SetScaled(const Vector3& v);
        void Scale(float x, float y, float z);
        void Scale(const Vector3& v);

        // Rotation
        void SetRotateX(double radians);
        void SetRotateY(double radians);
        void SetRotateZ(double radians);
        void RotateX(double radians);
        void RotateY(double radians);
        void RotateZ(double radians);
        void SetRotated(float pitch, float yaw, float roll);

        // Translation
        void SetTranslation(float x, float y);
        void Translate(float x, float y);
        void Translate(const Vector3& v);

        // ToString method
        std::string ToString() const;

        // Static factory methods
        static Matrix3 MakeIdentity();
        static Matrix3 MakeTranslation(float x, float y);
        static Matrix3 MakeTranslation(const Vector3& v);
        static Matrix3 MakeTranslation(float x, float y, float z);
        static Matrix3 MakeRotateX(float radians);
        static Matrix3 MakeRotateY(float radians);
        static Matrix3 MakeRotateZ(float radians);
        static Matrix3 MakeEuler(float pitch, float yaw, float roll);
        static Matrix3 MakeEuler(const Vector3& euler);
        static Matrix3 MakeScale(float x, float y);
        static Matrix3 MakeScale(float x, float y, float z);
        static Matrix3 MakeScale(const Vector3& scale);

        // Transpose method
        Matrix3 Transposed() const;

        // Equality operator
        bool operator==(const Matrix3& rhs) const;
	};
}