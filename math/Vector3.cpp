#include "Vector3.h"
#include <sstream>

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {
    // Constructor with parameters
}

Vector3::Vector3(const Vector2& v, float z) : x(v.x), y(v.y), z(z) {
    // Constructor from Vector2 and z coordinate
}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/(float scalar) const {
    if (scalar != 0.0f) {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }
    return Vector3();
}

Vector3& Vector3::operator+=(const Vector3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3& Vector3::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

bool Vector3::operator==(const Vector3& other) const {
    const float epsilon = 0.0001f;
    return (fabs(x - other.x) < epsilon && 
            fabs(y - other.y) < epsilon && 
            fabs(z - other.z) < epsilon);
}

bool Vector3::operator!=(const Vector3& other) const {
    return !(*this == other);
}

Vector2 Vector3::ToVector2() const {
    return Vector2(x, y);
}

Vector2 Vector3::XY() const {
    return Vector2(x, y);
}

Vector2 Vector3::XZ() const {
    return Vector2(x, z);
}

Vector2 Vector3::YZ() const {
    return Vector2(y, z);
}

float Vector3::Length() const {
    return sqrtf(x * x + y * y + z * z);
}

float Vector3::LengthSquared() const {
    return x * x + y * y + z * z;
}

float Vector3::Distance(const Vector3& other) const {
    return (*this - other).Length();
}

Vector3 Vector3::Normalize() const {
    float len = Length();
    if (len > 0.0f) {
        return Vector3(x / len, y / len, z / len);
    }
    return Vector3();
}

Vector3 Vector3::Clamp(float min, float max) const {
    return Vector3(
        x < min ? min : (x > max ? max : x),
        y < min ? min : (y > max ? max : y),
        z < min ? min : (z > max ? max : z)
    );
}

float Vector3::Dot(const Vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::Cross(const Vector3& other) const {
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

Vector3 Vector3::RotateX(float angle) const {
    float cosA = cosf(angle);
    float sinA = sinf(angle);
    return Vector3(
        x,
        y * cosA - z * sinA,
        y * sinA + z * cosA
    );
}

Vector3 Vector3::RotateY(float angle) const {
    float cosA = cosf(angle);
    float sinA = sinf(angle);
    return Vector3(
        x * cosA + z * sinA,
        y,
        -x * sinA + z * cosA
    );
}

Vector3 Vector3::RotateZ(float angle) const {
    float cosA = cosf(angle);
    float sinA = sinf(angle);
    return Vector3(
        x * cosA - y * sinA,
        x * sinA + y * cosA,
        z
    );
}

Vector3 Vector3::Lerp(const Vector3& a, const Vector3& b, float t) {
    t = fmaxf(0.0f, fminf(1.0f, t)); // Clamp t between 0 and 1
    return Vector3(
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t,
        a.z + (b.z - a.z) * t
    );
}

Vector3 Vector3::Min(const Vector3& a, const Vector3& b) {
    return Vector3(
        fminf(a.x, b.x),
        fminf(a.y, b.y),
        fminf(a.z, b.z)
    );
}

Vector3 Vector3::Max(const Vector3& a, const Vector3& b) {
    return Vector3(
        fmaxf(a.x, b.x),
        fmaxf(a.y, b.y),
        fmaxf(a.z, b.z)
    );
}

void Vector3::Zero() {
    x = y = z = 0.0f;
}

bool Vector3::IsZero() const {
    const float epsilon = 0.0001f;
    return (fabs(x) < epsilon && fabs(y) < epsilon && fabs(z) < epsilon);
}

bool Vector3::IsValid() const {
    return (!isnan(x) && !isnan(y) && !isnan(z) && 
            !isinf(x) && !isinf(y) && !isinf(z));
}

std::string Vector3::ToString() const {
    std::ostringstream oss;
    oss << "Vector3(" << x << ", " << y << ", " << z << ")";
    return oss.str();
}