#include <cmath>
#include <sstream>
#include <iomanip>
#include "MathHeaders/Matrix4.h"

namespace MathClasses
{
	const Matrix4 Matrix4::identity = Matrix4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	Matrix4::Matrix4()
		: m1(0), m2(0), m3(0), m4(0),
		m5(0), m6(0), m7(0), m8(0),
		m9(0), m10(0), m11(0), m12(0),
		m13(0), m14(0), m15(0), m16(0) {}

	Matrix4::Matrix4(float m1, float m2, float m3, float m4,
		float m5, float m6, float m7, float m8,
		float m9, float m10, float m11, float m12,
		float m13, float m14, float m15, float m16)
		: m1(m1), m2(m2), m3(m3), m4(m4),
		m5(m5), m6(m6), m7(m7), m8(m8),
		m9(m9), m10(m10), m11(m11), m12(m12),
		m13(m13), m14(m14), m15(m15), m16(m16) {}

	// Constructor that takes a pointer to an array of elements
	Matrix4::Matrix4(const float* elements)
	{
		m1 = elements[0];  m2 = elements[1];  m3 = elements[2];  m4 = elements[3];
		m5 = elements[4];  m6 = elements[5];  m7 = elements[6];  m8 = elements[7];
		m9 = elements[8];  m10 = elements[9]; m11 = elements[10]; m12 = elements[11];
		m13 = elements[12]; m14 = elements[13]; m15 = elements[14]; m16 = elements[15];
	}

	Matrix4 Matrix4::operator*(const Matrix4& rhs) const
	{
		return Matrix4(
			// Row 1
			rhs.m1 * m1 + rhs.m2 * m5 + rhs.m3 * m9 + rhs.m4 * m13,
			rhs.m1 * m2 + rhs.m2 * m6 + rhs.m3 * m10 + rhs.m4 * m14,
			rhs.m1 * m3 + rhs.m2 * m7 + rhs.m3 * m11 + rhs.m4 * m15,
			rhs.m1 * m4 + rhs.m2 * m8 + rhs.m3 * m12 + rhs.m4 * m16,

			// Row 2
			rhs.m5 * m1 + rhs.m6 * m5 + rhs.m7 * m9 + rhs.m8 * m13,
			rhs.m5 * m2 + rhs.m6 * m6 + rhs.m7 * m10 + rhs.m8 * m14,
			rhs.m5 * m3 + rhs.m6 * m7 + rhs.m7 * m11 + rhs.m8 * m15,
			rhs.m5 * m4 + rhs.m6 * m8 + rhs.m7 * m12 + rhs.m8 * m16,

			// Row 3
			rhs.m9 * m1 + rhs.m10 * m5 + rhs.m11 * m9 + rhs.m12 * m13,
			rhs.m9 * m2 + rhs.m10 * m6 + rhs.m11 * m10 + rhs.m12 * m14,
			rhs.m9 * m3 + rhs.m10 * m7 + rhs.m11 * m11 + rhs.m12 * m15,
			rhs.m9 * m4 + rhs.m10 * m8 + rhs.m11 * m12 + rhs.m12 * m16,

			// Row 4
			rhs.m13 * m1 + rhs.m14 * m5 + rhs.m15 * m9 + rhs.m16 * m13,
			rhs.m13 * m2 + rhs.m14 * m6 + rhs.m15 * m10 + rhs.m16 * m14,
			rhs.m13 * m3 + rhs.m14 * m7 + rhs.m15 * m11 + rhs.m16 * m15,
			rhs.m13 * m4 + rhs.m14 * m8 + rhs.m15 * m12 + rhs.m16 * m16
		);
	}

	Vector4 Matrix4::operator*(const Vector4& rhs) const
	{
		return Vector4(
			rhs.x * m1 + rhs.y * m5 + rhs.z * m9 + rhs.w * m13,
			rhs.x * m2 + rhs.y * m6 + rhs.z * m10 + rhs.w * m14,
			rhs.x * m3 + rhs.y * m7 + rhs.z * m11 + rhs.w * m15,
			rhs.x * m4 + rhs.y * m8 + rhs.z * m12 + rhs.w * m16
		);
	}

	bool Matrix4::operator==(const Matrix4& rhs) const
	{
		return m1 == rhs.m1 && m2 == rhs.m2 && m3 == rhs.m3 && m4 == rhs.m4 &&
			m5 == rhs.m5 && m6 == rhs.m6 && m7 == rhs.m7 && m8 == rhs.m8 &&
			m9 == rhs.m9 && m10 == rhs.m10 && m11 == rhs.m11 && m12 == rhs.m12 &&
			m13 == rhs.m13 && m14 == rhs.m14 && m15 == rhs.m15 && m16 == rhs.m16;
	}

	bool Matrix4::operator!=(const Matrix4& rhs) const
	{
		return !(*this == rhs);
	}

	void Matrix4::Set(const Matrix4& m)
	{
		m1 = m.m1; m2 = m.m2; m3 = m.m3; m4 = m.m4;
		m5 = m.m5; m6 = m.m6; m7 = m.m7; m8 = m.m8;
		m9 = m.m9; m10 = m.m10; m11 = m.m11; m12 = m.m12;
		m13 = m.m13; m14 = m.m14; m15 = m.m15; m16 = m.m16;
	}

	void Matrix4::Set(float m1, float m2, float m3, float m4,
		float m5, float m6, float m7, float m8,
		float m9, float m10, float m11, float m12,
		float m13, float m14, float m15, float m16)
	{
		this->m1 = m1; this->m2 = m2; this->m3 = m3; this->m4 = m4;
		this->m5 = m5; this->m6 = m6; this->m7 = m7; this->m8 = m8;
		this->m9 = m9; this->m10 = m10; this->m11 = m11; this->m12 = m12;
		this->m13 = m13; this->m14 = m14; this->m15 = m15; this->m16 = m16;
	}

	void Matrix4::SetScaled(float x, float y, float z, float w)
	{
		m1 = x;  m2 = 0;  m3 = 0;  m4 = 0;
		m5 = 0;  m6 = y;  m7 = 0;  m8 = 0;
		m9 = 0;  m10 = 0; m11 = z; m12 = 0;
		m13 = 0; m14 = 0; m15 = 0; m16 = w;
	}

	void Matrix4::SetScaled(const Vector4& v)
	{
		SetScaled(v.x, v.y, v.z, v.w);
	}

	void Matrix4::Scale(float x, float y, float z, float w)
	{
		Matrix4 m;
		m.SetScaled(x, y, z, w);
		*this = *this * m;
	}

	void Matrix4::Scale(const Vector4& v)
	{
		Scale(v.x, v.y, v.z, v.w);
	}

	void Matrix4::SetRotateX(double radians)
	{
		m1 = 1; m2 = 0;           m3 = 0;          m4 = 0;
		m5 = 0; m6 = cos(radians); m7 = sin(radians); m8 = 0;
		m9 = 0; m10 = -sin(radians); m11 = cos(radians); m12 = 0;
		m13 = 0; m14 = 0;           m15 = 0;          m16 = 1;
	}

	void Matrix4::SetRotateY(double radians)
	{
		m1 = cos(radians);  m2 = 0; m3 = -sin(radians); m4 = 0;
		m5 = 0;           m6 = 1; m7 = 0;           m8 = 0;
		m9 = sin(radians);  m10 = 0; m11 = cos(radians);  m12 = 0;
		m13 = 0;           m14 = 0; m15 = 0;           m16 = 1;
	}

	void Matrix4::SetRotateZ(double radians)
	{
		m1 = cos(radians); m2 = sin(radians); m3 = 0; m4 = 0;
		m5 = -sin(radians); m6 = cos(radians); m7 = 0; m8 = 0;
		m9 = 0;            m10 = 0;           m11 = 1; m12 = 0;
		m13 = 0;           m14 = 0;           m15 = 0; m16 = 1;
	}

	void Matrix4::RotateX(double radians)
	{
		Matrix4 m;
		m.SetRotateX(radians);
		*this = *this * m;
	}

	void Matrix4::RotateY(double radians)
	{
		Matrix4 m;
		m.SetRotateY(radians);
		*this = *this * m;
	}

	void Matrix4::RotateZ(double radians)
	{
		Matrix4 m;
		m.SetRotateZ(radians);
		*this = *this * m;
	}

	void Matrix4::SetRotated(float pitch, float yaw, float roll)
	{
		*this = MakeEuler(pitch, yaw, roll);
	}

	void Matrix4::SetTranslation(float x, float y, float z)
	{
		m1 = 1; m2 = 0; m3 = 0; m4 = 0;
		m5 = 0; m6 = 1; m7 = 0; m8 = 0;
		m9 = 0; m10 = 0; m11 = 1; m12 = 0;
		m13 = x; m14 = y; m15 = z; m16 = 1;
	}

	void Matrix4::Translate(float x, float y, float z)
	{
		Matrix4 m;
		m.SetTranslation(x, y, z);
		*this = *this * m;
	}

	void Matrix4::Translate(const Vector4& v)
	{
		Translate(v.x, v.y, v.z);
	}

	Matrix4 Matrix4::MakeIdentity()
	{
		return Matrix4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}

	Matrix4 Matrix4::MakeTranslation(float x, float y, float z)
	{
		return Matrix4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			x, y, z, 1
		);
	}

	Matrix4 Matrix4::MakeTranslation(const Vector3& v)
	{
		return MakeTranslation(v.x, v.y, v.z);
	}

	Matrix4 Matrix4::MakeRotateX(float radians)
	{
		return Matrix4(
			1, 0, 0, 0,
			0, cos(radians), -sin(radians), 0,
			0, sin(radians), cos(radians), 0,
			0, 0, 0, 1
		);
	}

	Matrix4 Matrix4::MakeRotateY(float radians)
	{
		return Matrix4(
			cos(radians), 0, sin(radians), 0,
			0, 1, 0, 0,
			-sin(radians), 0, cos(radians), 0,
			0, 0, 0, 1
		);
	}

	Matrix4 Matrix4::MakeRotateZ(float radians)
	{
		return Matrix4(
			cos(radians), sin(radians), 0, 0,
			-sin(radians), cos(radians), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}

	Matrix4 Matrix4::MakeEuler(float pitch, float yaw, float roll)
	{
		// Calculate the sine and cosine of the pitch, yaw, and roll angles
		float cp = cos(pitch);
		float sp = sin(pitch);
		float cy = cos(yaw);
		float sy = sin(yaw);
		float cr = cos(roll);
		float sr = sin(roll);

		// Compute the rotation matrix components
		float m00 = cy * cr;
		float m01 = cy * sr;
		float m02 = -sy;

		float m10 = sp * sy * cr - cp * sr;
		float m11 = sp * sy * sr + cp * cr;
		float m12 = sp * cy;

		float m20 = cp * sy * cr + sp * sr;
		float m21 = cp * sy * sr - sp * cr;
		float m22 = cp * cy;

		return Matrix4(
			m00, m01, -m02, 0.0f,
			m10, m11, -m12, 0.0f,
			-m20, -m21, m22, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}

	Matrix4 Matrix4::MakeEuler(const Vector3& euler)
	{
		return MakeEuler(euler.x, euler.y, euler.z);
	}

	Matrix4 Matrix4::MakeScale(float x, float y, float z)
	{
		return Matrix4(
			x, 0, 0, 0,
			0, y, 0, 0,
			0, 0, z, 0,
			0, 0, 0, 1
		);
	}

	Matrix4 Matrix4::MakeScale(const Vector3& v)
	{
		return MakeScale(v.x, v.y, v.z);
	}

	bool MathClasses::Matrix4::Equals(const Matrix4& other, float epsilon) const
	{
		return (fabs(m1 - other.m1) < epsilon &&
			fabs(m2 - other.m2) < epsilon &&
			fabs(m3 - other.m3) < epsilon &&
			fabs(m4 - other.m4) < epsilon &&
			fabs(m5 - other.m5) < epsilon &&
			fabs(m6 - other.m6) < epsilon &&
			fabs(m7 - other.m7) < epsilon &&
			fabs(m8 - other.m8) < epsilon &&
			fabs(m9 - other.m9) < epsilon &&
			fabs(m10 - other.m10) < epsilon &&
			fabs(m11 - other.m11) < epsilon &&
			fabs(m12 - other.m12) < epsilon &&
			fabs(m13 - other.m13) < epsilon &&
			fabs(m14 - other.m14) < epsilon &&
			fabs(m15 - other.m15) < epsilon &&
			fabs(m16 - other.m16) < epsilon);
	}

	std::string Matrix4::ToString() const
	{
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(2);
		oss << "[" << m1 << ", " << m2 << ", " << m3 << ", " << m4 << "]\n"
			<< "[" << m5 << ", " << m6 << ", " << m7 << ", " << m8 << "]\n"
			<< "[" << m9 << ", " << m10 << ", " << m11 << ", " << m12 << "]\n"
			<< "[" << m13 << ", " << m14 << ", " << m15 << ", " << m16 << "]";
		return oss.str();
	}

	std::ostream& operator<<(std::ostream& os, const Matrix4& m)
	{
		os << m.ToString();
		return os;
	}
}
