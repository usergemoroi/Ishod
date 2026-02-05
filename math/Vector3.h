#ifndef LIBX_VECTOR3_H
#define LIBX_VECTOR3_H

#include <cmath>
#include "Vector2.h"

class Vector3 {
public:
    float x, y, z;
    
    // Constructors
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    Vector3(float x) : x(x), y(x), z(x) {}
    Vector3(const Vector2& v, float z) : x(v.x), y(v.y), z(z) {}
    
    // Operators
    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }
    
    Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }
    
    Vector3 operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }
    
    Vector3 operator/(float scalar) const {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }
    
    Vector3& operator+=(const Vector3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
    
    Vector3& operator-=(const Vector3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }
    
    Vector3& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }
    
    bool operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    
    bool operator!=(const Vector3& other) const {
        return !(*this == other);
    }
    
    // 2D conversions
    Vector2 ToVector2() const {
        return Vector2(x, y);
    }
    
    Vector2 XY() const {
        return Vector2(x, y);
    }
    
    Vector2 XZ() const {
        return Vector2(x, z);
    }
    
    Vector2 YZ() const {
        return Vector2(y, z);
    }
    
    // Methods
    float Length() const {
        return sqrt(x * x + y * y + z * z);
    }
    
    float LengthSquared() const {
        return x * x + y * y + z * z;
    }
    
    float Distance(const Vector3& other) const {
        return (*this - other).Length();
    }
    
    Vector3 Normalize() const {
        float len = Length();
        if (len > 0.0f) {
            return Vector3(x / len, y / len, z / len);
        }
        return Vector3();
    }
    
    Vector3 Clamp(float min, float max) const {
        return Vector3(
            x < min ? min : (x > max ? max : x),
            y < min ? min : (y > max ? max : y),
            z < min ? min : (z > max ? max : z)
        );
    }
    
    float Dot(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    
    Vector3 Cross(const Vector3& other) const {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }
    
    Vector3 RotateX(float angle) const {
        float cos = cosf(angle);
        float sin = sinf(angle);
        return Vector3(x, y * cos - z * sin, y * sin + z * cos);
    }
    
    Vector3 RotateY(float angle) const {
        float cos = cosf(angle);
        float sin = sinf(angle);
        return Vector3(x * cos + z * sin, y, -x * sin + z * cos);
    }
    
    Vector3 RotateZ(float angle) const {
        float cos = cosf(angle);
        float sin = sinf(angle);
        return Vector3(x * cos - y * sin, x * sin + y * cos, z);
    }
    
    static Vector3 Lerp(const Vector3& a, const Vector3& b, float t) {
        return Vector3(
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.z + (b.z - a.z) * t
        );
    }
    
    static Vector3 Min(const Vector3& a, const Vector3& b) {
        return Vector3(
            std::min(a.x, b.x),
            std::min(a.y, b.y),
            std::min(a.z, b.z)
        );
    }
    
    static Vector3 Max(const Vector3& a, const Vector3& b) {
        return Vector3(
            std::max(a.x, b.x),
            std::max(a.y, b.y),
            std::max(a.z, b.z)
        );
    }
    
    // Utility
    void Zero() {
        x = y = z = 0.0f;
    }
    
    bool IsZero() const {
        return x == 0.0f && y == 0.0f && z == 0.0f;
    }
    
    bool IsValid() const {
        return !isnan(x) && !isnan(y) && !isnan(z) && 
               !isinf(x) && !isinf(y) && !isinf(z);
    }
    
    std::string ToString() const {
        return "Vector3(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }
};

#endif // LIBX_VECTOR3_H