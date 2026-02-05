#include "Vector2.h"
#include <sstream>

Vector2::Vector2(float x, float y) : x(x), y(y) {
    // Constructor with parameters
}

Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar) const {
    if (scalar != 0.0f) {
        return Vector2(x / scalar, y / scalar);
    }
    return Vector2();
}

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2& Vector2::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

bool Vector2::operator==(const Vector2& other) const {
    const float epsilon = 0.0001f;
    return (fabs(x - other.x) < epsilon && fabs(y - other.y) < epsilon);
}

bool Vector2::operator!=(const Vector2& other) const {
    return !(*this == other);
}

float Vector2::Length() const {
    return sqrtf(x * x + y * y);
}

float Vector2::LengthSquared() const {
    return x * x + y * y;
}

float Vector2::Distance(const Vector2& other) const {
    return (*this - other).Length();
}

Vector2 Vector2::Normalize() const {
    float len = Length();
    if (len > 0.0f) {
        return Vector2(x / len, y / len);
    }
    return Vector2();
}

Vector2 Vector2::Clamp(float min, float max) const {
    return Vector2(
        x < min ? min : (x > max ? max : x),
        y < min ? min : (y > max ? max : y)
    );
}

Vector2 Vector2::Clamp(const Vector2& min, const Vector2& max) const {
    return Vector2(
        x < min.x ? min.x : (x > max.x ? max.x : x),
        y < min.y ? min.y : (y > max.y ? max.y : y)
    );
}

Vector2 Vector2::Lerp(const Vector2& a, const Vector2& b, float t) {
    t = fmaxf(0.0f, fminf(1.0f, t)); // Clamp t between 0 and 1
    return Vector2(
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t
    );
}

float Vector2::Dot(const Vector2& a, const Vector2& b) {
    return a.x * b.x + a.y * b.y;
}

void Vector2::Zero() {
    x = y = 0.0f;
}

bool Vector2::IsZero() const {
    const float epsilon = 0.0001f;
    return (fabs(x) < epsilon && fabs(y) < epsilon);
}

std::string Vector2::ToString() const {
    std::ostringstream oss;
    oss << "Vector2(" << x << ", " << y << ")";
    return oss.str();
}