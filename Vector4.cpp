#include "MathHeaders/Vector4.h"
#include <cmath>
#include <string>

namespace MathClasses {

    const float EPSILON = 1e-5f;

    // Constructors
    Vector4::Vector4() : x(0), y(0), z(0), w(0) {}

    Vector4::Vector4(float x4d, float y4d, float z4d, float w4d) : x(x4d), y(y4d), z(z4d), w(w4d) {}

    // Addition
    Vector4 Vector4::operator+(const Vector4& rhs) const {
        return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
    }

    Vector4& Vector4::operator+=(const Vector4& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
        return *this;
    }

    // Subtraction
    Vector4 Vector4::operator-(const Vector4& rhs) const {
        return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
    }

    Vector4& Vector4::operator-=(const Vector4& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        w -= rhs.w;
        return *this;
    }

    // Vector scalar multiplication
    Vector4 Vector4::operator*(float scalar) const {
        return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    Vector4 operator*(float scalar, const Vector4& lhs) {
        return Vector4(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar, lhs.w * scalar);
    }

    Vector4& Vector4::operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    // Vector scalar division
    Vector4 Vector4::operator/(float scalar) const {
        return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
    }

    Vector4& Vector4::operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }

    // Magnitude
    float Vector4::Magnitude() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    // Magnitude squared
    float Vector4::MagnitudeSqr() const {
        return x * x + y * y + z * z + w * w;
    }

    // Vector normalization
    void Vector4::Normalise() {
        float m = Magnitude();
        if (m > 0) {
            x /= m;
            y /= m;
            z /= m;
            w /= m;
        }
    }

    Vector4 Vector4::Normalised() const {
        float m = Magnitude();
        if (m > 0) {
            return Vector4(x / m, y / m, z / m, w / m);
        }
        return Vector4();
    }

    // Distance
    float Vector4::Distance(const Vector4& other) const {
        float diffX = x - other.x;
        float diffY = y - other.y;
        float diffZ = z - other.z;
        float diffW = w - other.w;
        return std::sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ + diffW * diffW);
    }

    // Dot product
    float Vector4::Dot(const Vector4& other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    Vector4 Vector4::Cross(const Vector4& other) const {
        return Vector4(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x,
            0 // Set w component to 0 as specified by the test
        );
    }

    // Equality operators
    bool Vector4::operator==(const Vector4& rhs) const {
        return (std::fabs(x - rhs.x) < EPSILON) &&
            (std::fabs(y - rhs.y) < EPSILON) &&
            (std::fabs(z - rhs.z) < EPSILON) &&
            (std::fabs(w - rhs.w) < EPSILON);
    }

    bool Vector4::operator!=(const Vector4& rhs) const {
        return !(*this == rhs);
    }

    //to string
    std::string Vector4::ToString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")";
    }
}