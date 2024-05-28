#include "MathHeaders/Vector3.h"
#include <cmath>
#include <string>

namespace MathClasses {

    const float EPSILON = 1e-5f;
    // Constructors
    Vector3::Vector3() : x(0), y(0), z(0) {}

    Vector3::Vector3(float x3d, float y3d, float z3d) : x(x3d), y(y3d), z(z3d) {}

    // Addition
    Vector3 Vector3::operator+(const Vector3& rhs) const {
        return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    Vector3& Vector3::operator+=(const Vector3& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    // Subtraction
    Vector3 Vector3::operator-(const Vector3& rhs) const {
        return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    Vector3& Vector3::operator-=(const Vector3& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    // Vector scalar multiplication
    Vector3 Vector3::operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 operator*(float scalar, const Vector3& lhs) {
        return Vector3(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
    }

    Vector3& Vector3::operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    // Vector scalar division
    Vector3 Vector3::operator/(float scalar) const {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    Vector3& Vector3::operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    // Magnitude
    float Vector3::Magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Magnitude squared
    float Vector3::MagnitudeSqr() const {
        return x * x + y * y + z * z;
    }

    // Vector normalization
    void Vector3::Normalise() {
        float m = Magnitude();
        if (m > 0) {
            x /= m;
            y /= m;
            z /= m;
        }
    }

    Vector3 Vector3::Normalised() const {
        float m = Magnitude();
        if (m > 0) {
            return Vector3(x / m, y / m, z / m);
        }
        return Vector3();
    }

    // Distance
    float Vector3::Distance(const Vector3& other) const {
        float diffX = x - other.x;
        float diffY = y - other.y;
        float diffZ = z - other.z;
        return std::sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
    }

    // Dot product
    float Vector3::Dot(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Cross product
    Vector3 Vector3::Cross(const Vector3& other) const {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Equality operators
    bool Vector3::operator==(const Vector3& rhs) const {
        return (std::fabs(x - rhs.x) < EPSILON) &&
            (std::fabs(y - rhs.y) < EPSILON) &&
            (std::fabs(z - rhs.z) < EPSILON);
    }

    bool Vector3::operator!=(const Vector3& rhs) const {
        return !(*this == rhs);
    }

    //to string
    std::string Vector3::ToString() const {
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	}
}