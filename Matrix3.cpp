#include "MathHeaders/Matrix3.h"
#include <sstream>
#include <cmath>  

namespace MathClasses {

    const Matrix3 Matrix3::identity = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);

    // Constructors
    Matrix3::Matrix3() : m1(0), m2(0), m3(0), m4(0), m5(0), m6(0), m7(0), m8(0), m9(0) {}

    Matrix3::Matrix3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
        : m1(m1), m2(m2), m3(m3), m4(m4), m5(m5), m6(m6), m7(m7), m8(m8), m9(m9) {}

    Matrix3::Matrix3(const float numbers[9])
        : m1(numbers[0]), m2(numbers[1]), m3(numbers[2]), m4(numbers[3]), m5(numbers[4]), m6(numbers[5]), m7(numbers[6]), m8(numbers[7]), m9(numbers[8]) {}

    // helper function to round to a certain number of decimal places
    float Matrix3::RoundToMat3(float value, int decimalPlaces)
    {
        float scale = std::pow(10.0f, decimalPlaces);
        return std::round(value * scale) / scale;
    }

    // Matrix multiplication
    Matrix3 Matrix3::operator*(const Matrix3& rhs) const {
        return Matrix3(
            m1 * rhs.m1 + m4 * rhs.m2 + m7 * rhs.m3,
            m2 * rhs.m1 + m5 * rhs.m2 + m8 * rhs.m3,
            m3 * rhs.m1 + m6 * rhs.m2 + m9 * rhs.m3,

            m1 * rhs.m4 + m4 * rhs.m5 + m7 * rhs.m6,
            m2 * rhs.m4 + m5 * rhs.m5 + m8 * rhs.m6,
            m3 * rhs.m4 + m6 * rhs.m5 + m9 * rhs.m6,

            m1 * rhs.m7 + m4 * rhs.m8 + m7 * rhs.m9,
            m2 * rhs.m7 + m5 * rhs.m8 + m8 * rhs.m9,
            m3 * rhs.m7 + m6 * rhs.m8 + m9 * rhs.m9
        );
    }

    // Matrix-vector multiplication
    Vector3 Matrix3::operator*(const Vector3& rhs) const {
        return Vector3(
            m1 * rhs.x + m4 * rhs.y + m7 * rhs.z,
            m2 * rhs.x + m5 * rhs.y + m8 * rhs.z,
            m3 * rhs.x + m6 * rhs.y + m9 * rhs.z
        );
    }

    // Set methods
    void Matrix3::Set(const Matrix3& m) {
        m1 = m.m1; m2 = m.m2; m3 = m.m3;
        m4 = m.m4; m5 = m.m5; m6 = m.m6;
        m7 = m.m7; m8 = m.m8; m9 = m.m9;
    }

    void Matrix3::Set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9) {
        this->m1 = m1; this->m2 = m2; this->m3 = m3;
        this->m4 = m4; this->m5 = m5; this->m6 = m6;
        this->m7 = m7; this->m8 = m8; this->m9 = m9;
    }

    // Scaling
    void Matrix3::SetScaled(float x, float y, float z) {
        m1 = x; m2 = 0; m3 = 0;
        m4 = 0; m5 = y; m6 = 0;
        m7 = 0; m8 = 0; m9 = z;
    }

    void Matrix3::SetScaled(const Vector3& v) {
        SetScaled(v.x, v.y, v.z);
    }

    void Matrix3::Scale(float x, float y, float z) {
        Matrix3 m;
        m.SetScaled(x, y, z);
        Set(*this * m);
    }

    void Matrix3::Scale(const Vector3& v) {
        Scale(v.x, v.y, v.z);
    }

    // Rotation
    void Matrix3::SetRotateX(double radians) {
        double c = std::cos(radians);
        double s = std::sin(radians);

        Set(
            1.0f, 0, 0,
            0, RoundToMat3(c, 6), RoundToMat3(-s, 6),
            0, RoundToMat3(s, 6), RoundToMat3(c, 6)
        );
    }

    void Matrix3::SetRotateY(double radians) {
        double c = std::cos(radians);
        double s = std::sin(radians);

        Set(
            RoundToMat3(c, 6), 0, RoundToMat3(s, 6),
            0, 1.0f, 0,
            RoundToMat3(-s, 6), 0, RoundToMat3(c, 6)
        );
    }

    void Matrix3::SetRotateZ(double radians) {
        double c = std::cos(radians);
        double s = std::sin(radians);

        Set(
            RoundToMat3(c, 6), RoundToMat3(s, 6), 0,
            RoundToMat3(-s, 6), RoundToMat3(c, 6), 0,
            0, 0, 1.0f
        );
    }

    void Matrix3::RotateX(double radians) {
        Matrix3 m;
        m.SetRotateX(radians);
        Set(*this * m);
    }

    void Matrix3::RotateY(double radians) {
        Matrix3 m;
        m.SetRotateY(radians);
        Set(*this * m);
    }

    void Matrix3::RotateZ(double radians) {
        Matrix3 m;
        m.SetRotateZ(radians);
        Set(*this * m);
    }

    void Matrix3::SetRotated(float pitch, float yaw, float roll) {
        Matrix3 x, y, z;
        x.SetRotateX(static_cast<double>(pitch));
        y.SetRotateY(static_cast<double>(yaw));
        z.SetRotateZ(static_cast<double>(roll));

        Matrix3 result = z * y * x;

        // Consistent rounding applied to final results
        m1 = RoundToMat3(result.m1, 6); m2 = RoundToMat3(result.m2, 6); m3 = RoundToMat3(result.m3, 6);
        m4 = RoundToMat3(result.m4, 6); m5 = RoundToMat3(result.m5, 6); m6 = RoundToMat3(result.m6, 6);
        m7 = RoundToMat3(result.m7, 6); m8 = RoundToMat3(result.m8, 6); m9 = RoundToMat3(result.m9, 6);
    }

    // Translation
    void Matrix3::SetTranslation(float x, float y) {
        Set(
            1, 0, 0,
            0, 1, 0,
            x, y, 1
        );
    }

    void Matrix3::Translate(float x, float y) {
        Matrix3 m;
        m.SetTranslation(x, y);
        Set(*this * m);
    }

    void Matrix3::Translate(const Vector3& v) {
        Translate(v.x, v.y);
    }

    // ToString method
    std::string Matrix3::ToString() const {
        std::ostringstream oss;
        oss << "[" << m1 << ", " << m2 << ", " << m3 << "], "
            << "[" << m4 << ", " << m5 << ", " << m6 << "], "
            << "[" << m7 << ", " << m8 << ", " << m9 << "]";
        return oss.str();
    }

    // Static factory methods
    Matrix3 Matrix3::MakeIdentity() {
        return Matrix3::identity;
    }

    Matrix3 Matrix3::MakeTranslation(float x, float y) {
        Matrix3 m = Matrix3::identity;
        m.SetTranslation(x, y);
        return m;
    }

    Matrix3 Matrix3::MakeTranslation(const Vector3& v) {
        return MakeTranslation(v.x, v.y);
    }

    Matrix3 Matrix3::MakeTranslation(float x, float y, float z) {
        return Matrix3(
            1, 0, 0,
            0, 1, 0,
            x, y, z
        );
    }

    Matrix3 Matrix3::MakeRotateX(float radians) {
        Matrix3 m;
        m.SetRotateX(static_cast<double>(radians));
        return m;
    }

    Matrix3 Matrix3::MakeRotateY(float radians) {
        Matrix3 m;
        m.SetRotateY(radians);
        return m;
    }

    Matrix3 Matrix3::MakeRotateZ(float radians) {
        Matrix3 m;
        m.SetRotateZ(radians);
        return m;
    }

    Matrix3 Matrix3::MakeEuler(float pitch, float yaw, float roll) {
        Matrix3 m;
        m.SetRotated(pitch, yaw, roll);
        return m;
    }

    Matrix3 Matrix3::MakeEuler(const Vector3& euler) {
        return MakeEuler(euler.x, euler.y, euler.z);
    }

    Matrix3 Matrix3::MakeScale(float x, float y) {
        return Matrix3(x, 0, 0, 0, y, 0, 0, 0, 1);
    }

    Matrix3 Matrix3::MakeScale(float x, float y, float z) {
        return Matrix3(x, 0, 0, 0, y, 0, 0, 0, z);
    }

    Matrix3 Matrix3::MakeScale(const Vector3& scale) {
        return MakeScale(scale.x, scale.y, scale.z);
    }

    // Transpose method
    Matrix3 Matrix3::Transposed() const {
        return Matrix3(
            m1, m4, m7,
            m2, m5, m8,
            m3, m6, m9
        );
    }

    // Equality operator
    bool Matrix3::operator==(const Matrix3& rhs) const {
        return m1 == rhs.m1 && m2 == rhs.m2 && m3 == rhs.m3 &&
            m4 == rhs.m4 && m5 == rhs.m5 && m6 == rhs.m6 &&
            m7 == rhs.m7 && m8 == rhs.m8 && m9 == rhs.m9;
    }
}