#pragma once
#include <iostream>
#include <string>
#include <math.h>

class Vector3
{
public:
	static const Vector3 back;				// Shorthand for writing Vector3(0, 0, -1).
	static const Vector3 down;				// Shorthand for writing Vector3(0, -1, 0).
	static const Vector3 forward;			// Shorthand for writing Vector3(0, 0, 1).
	static const Vector3 left;				// Shorthand for writing Vector3(-1, 0, 0).
	static const Vector3 negativeInfinity;	// Shorthand for writing Vector3(FLT_MIN, FLT_MIN, FLT_MIN).
	static const Vector3 one;				// Shorthand for writing Vector3(1, 1, 1).
	static const Vector3 positiveInfinity;	// Shorthand for writing Vector3(FLT_MAX, FLT_MAX, FLT_MAX).
	static const Vector3 right;				// Shorthand for writing Vector3(1, 0, 0).
	static const Vector3 up;				// Shorthand for writing Vector3(0, 1, 0).
	static const Vector3 zero;				// Shorthand for writing Vector3(0, 0, 0).

	float x;	// X component of the vector.
	float y;	// Y component of the vector.
	float z;	// Z component of the vector.
	const float magnitude{ sqrtf(powf(x, 2.0f) + powf(y, 2.0f) + powf(z, 2.0f)) };	// Returns the length of this vector (Read Only).
	const float sqrMagnitude{ powf(x, 2.0f) + powf(y, 2.0f) + powf(z, 2.0f) };		// Returns the squared length of this vector (Read Only).
	const Vector3 GetNormalized() { return Vector3(x, y, z) / magnitude; }													// Returns this vector with a magnitude of 1 (Read Only).

	Vector3();						// Creates a new vector.
	Vector3(float);					// Creates a new vector with given x component.
	Vector3(float, float);			// Creates a new vector with given x, y components.
	Vector3(float, float, float);	// Creates a new vector with given x, y, z components.
	~Vector3();						// Destruct a vector.

	bool Equals(const Vector3&) const;	// Returns true if the given vector is exactly equal to this vector.
	void Set(float, float, float);		// Set x, y and z components of an existing Vector3.
	void Set(const Vector3&);			// Set x, y and z components of an existing Vector3.
	void Set(float);					// Set x, y and z components of an existing Vector3.
	std::string ToString() const;		// Returns a formatted string for this vector.
	std::string ToString(bool) const;	// Returns a formatted string for this vector.

	static float Angle(Vector3, Vector3);						// Calculates the angle between vectors from and.
	static Vector3 ClampMagnitude(Vector3, float);				// Returns a copy of vector with its magnitude clamped to maxLength.
	static Vector3 Cross(const Vector3&, const Vector3&);		// Cross Product of two vectors.
	static float Distance(Vector3, Vector3);					// Returns the distance between a and b.
	static float Dot(const Vector3&, const Vector3&);			// Dot Product of two vectors.
	static Vector3 Lerp(Vector3, Vector3, float);				// Linearly interpolates between two points.
	static Vector3 LerpUnclamped(Vector3, Vector3, float);		// Linearly interpolates between two vectors.
	static Vector3 Max(const Vector3&, const Vector3&);			// Returns a vector that is made from the largest components of two vectors.
	static Vector3 Min(const Vector3&, const Vector3&);			// Returns a vector that is made from the smallest components of two vectors.
	static Vector3 MoveTowards(Vector3, Vector3, float);		// Calculate a position between the points specified by current and target, moving no farther than the distance specified by maxDistanceDelta.
	static void Normalize(Vector3&);							// Makes this vector have a magnitude of 1.
	static void OrthoNormalize(Vector3&, Vector3&);				// Makes two givven vectors normalized and orthogonal to each other.
	static void OrthoNormalize(Vector3&, Vector3&, Vector3&);	// Makes three givven vectors normalized and orthogonal to each other.
	static Vector3 Project(Vector3, Vector3);					// Projects a vector onto another vector.
	static Vector3 ProjectOnPlane(Vector3, Vector3);			// Projects a vector onto a plane defined by a normal orthogonal to the plane.
	static Vector3 Reflect(Vector3, Vector3);					// Reflects a vector off the plane defined by a normal.
	static Vector3 RotateTowards(Vector3, Vector3, float, float);				// Rotates a vector current towards target.
	static void Scale(Vector3&, const Vector3&);								// Multiplies two vectors component-wise.
	static float SignedAngle(Vector3, Vector3, Vector3);					// Calculates the signed angle between vectors from and to in relation to axis.
	static Vector3 Slerp(const Vector3&, const Vector3&, float);				// Spherically interpolates between two vectors.
	static Vector3 SlerpUnclamped(const Vector3&, const Vector3&, float);		// Spherically interpolates between two vectors.
	static Vector3 SmoothDamp(const Vector3&, const Vector3&, Vector3&, float, float, float);	// Gradually changes a vector towards a desired goal over time.

	Vector3 operator=(Vector3); // Equates a vector to another.
	Vector3 operator+(Vector3);	// Adds two vectors.
	Vector3 operator-(Vector3); // Subtracts two vectors.
	Vector3 operator*(Vector3); // Multiplies two vectors component-wise.
	Vector3 operator/(Vector3);	// Divides two vectors component-wise.
	Vector3 operator+(float);	// Adds a vector by a number.
	Vector3 operator-(float);	// Subtracts a vector by a number.
	Vector3 operator*(float);	// Multiplies a vector by a number.
	Vector3 operator/(float);	// Divides a vector by a number.
	Vector3 operator-();		// Change the sign of the vector
	bool operator==(Vector3);	// Returns true if two vectors are approximately equal.
	bool operator!=(Vector3);	// Returns true if vectors are different.
};

//----------------Static Properties----------------

const Vector3 Vector3::back = Vector3(0.0f, 0.0f, -1.0f);
const Vector3 Vector3::down = Vector3(0.0f, -1.0f, 0.0f);
const Vector3 Vector3::forward = Vector3(0.0f, 0.0f, 1.0f);
const Vector3 Vector3::left = Vector3(-1.0f, 0.0f, 0.0f);
const Vector3 Vector3::negativeInfinity = Vector3(FLT_MIN, FLT_MIN, FLT_MIN);
const Vector3 Vector3::one = Vector3(1.0f, 1.0f, 1.0f);
const Vector3 Vector3::positiveInfinity = Vector3(FLT_MAX, FLT_MAX, FLT_MAX);
const Vector3 Vector3::right = Vector3(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::up = Vector3(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::zero = Vector3(0.0f, 0.0f, 0.0f);

//----------------Constructors----------------

Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
{
	std::cout << "Constructing Vector3 " << this << "..." << std::endl;
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(float x) : y(0.0f), z(0.0f)
{
	std::cout << "Constructing Vector3 " << this << "..." << std::endl;
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(float x, float y) : z(0.0f)
{
	std::cout << "Constructing Vector3 " << this << "..." << std::endl;
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(float x, float y, float z)
{
	std::cout << "Constructing Vector3 " << this << "..." << std::endl;
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
	std::cout << "Destructing Vector3 " << this << "..." << std::endl;
}

//----------------Public Methods----------------

void Vector3::Set(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::Set(const Vector3& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

void Vector3::Set(float n)
{
	this->x = this->y = this->z = n;
}

bool Vector3::Equals(const Vector3& v) const
{
	return Vector3(x, y, z) == v;
}

std::string Vector3::ToString() const
{
	return '(' + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ')';
}

std::string Vector3::ToString(bool isScraped) const
{
	if (isScraped)
	{
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	}
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
}

//----------------Static Methods----------------

float Vector3::Angle(Vector3 a, Vector3 b)
{
	return 2.0f * std::atan((a - b).magnitude / (a + b).magnitude);
}

Vector3 Vector3::ClampMagnitude(Vector3 v, float m)
{
	return v / std::fmaxf(v.magnitude, m) * m;
}

Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
{
	const float x = a.y * b.z - b.y * a.z;
	const float y = -(a.x * b.z - b.x * a.z);
	const float z = a.x * b.y - b.x * a.y;
	return Vector3(x, y, z);
}

float Vector3::Distance(Vector3 a, Vector3 b)
{
	return (a - b).magnitude;
}

float Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Vector3::Lerp(Vector3 a, Vector3 b, float t)
{
	return a + (b - a) * t;
}

Vector3 Vector3::LerpUnclamped(Vector3 a, Vector3 b, float t)
{
	return a * (1 - t) + b * t;
}

Vector3 Vector3::Max(const Vector3& a, const Vector3& b)
{
	return Vector3(std::fmaxf(a.x, b.x), std::fmaxf(a.y, b.y), std::fmaxf(a.z, b.z));
}

Vector3 Vector3::Min(const Vector3& a, const Vector3& b)
{
	return Vector3(std::fminf(a.x, b.x), std::fminf(a.y, b.y), std::fminf(a.z, b.z));
}

Vector3 Vector3::MoveTowards(Vector3 a, Vector3 b, float maxDistanceDelta)
{
	float t = maxDistanceDelta / Vector3::Distance(a, b);
	return a * (1 - t) + b * t;
}

void Vector3::Normalize(Vector3& v)
{
	v = v / v.magnitude;
}

void Vector3::OrthoNormalize(Vector3& a, Vector3& b)
{
	Vector3::Normalize(a);
	b.Set(a.y, a.z, a.x);
}

void Vector3::OrthoNormalize(Vector3& a, Vector3& b, Vector3& c)
{
	Vector3::Normalize(a);
	b.Set(a.y, a.z, a.x);
	c.Set(a.z, a.x, a.y);
}

Vector3 Vector3::Project(Vector3 a, Vector3 b)
{
	Vector3 c = b - a;
	float l = Vector3::Dot(c, -a) / c.magnitude;
	return a.MoveTowards(Vector3(), a, l);
}

Vector3 Vector3::ProjectOnPlane(Vector3 v, Vector3 plane)
{
	Vector3 a1;
	Vector3 a2;
	Vector3::OrthoNormalize(plane, a1, a2);
	Vector3 p = a1 * (a1 * v) + a2 * (a2 * v);
	p = p * (v.magnitude / p.magnitude);
	return p;
}

Vector3 Vector3::Reflect(Vector3 v, Vector3 plane)
{
	Vector3::Normalize(plane);
	return ((v * plane) * 2.0f) * plane - v;
}

Vector3 Vector3::RotateTowards(Vector3 a, Vector3 b, float maxRad, float maxMag)
{

}

float Vector3::SignedAngle(Vector3 a, Vector3 b, Vector3 axis)
{
	Vector3::Normalize(axis);
	return Vector3::Dot(Vector3::Cross(a, b), axis) / Vector3::Dot(a, b);
}

void Vector3::Scale(Vector3& v, const Vector3& c)
{
	v.x* c.x;
	v.y* c.y;
	v.z* c.z;
}

//----------------Operators----------------

Vector3 Vector3::operator=(Vector3 v)
{
	return v;
}

Vector3 Vector3::operator+(Vector3 v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(Vector3 v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(Vector3 v)
{
	return Vector3(x * v.x, y * v.y, z * v.z);
}

Vector3 Vector3::operator/(Vector3 v)
{
	return Vector3(x / v.x, y / v.y, z / v.z);
}

Vector3 Vector3::operator+(float n)
{
	return Vector3(x + n, y + n, z + n);
}

Vector3 Vector3::operator-(float n)
{
	return Vector3(x - n, y - n, z - n);
}

Vector3 Vector3::operator*(float n)
{
	return Vector3(x * n, y * n, z * n);
}

Vector3 Vector3::operator/(float n)
{
	return Vector3(x / n, y / n, z / n);
}

Vector3 Vector3::operator-()
{
	return Vector3(-x, -y, -z);
}

bool Vector3::operator==(Vector3 v)
{
	return (x == v.x && y == v.y && z == v.z);
}

bool Vector3::operator!=(Vector3 v)
{
	return !(x == v.x && y == v.y && z == v.z);
}