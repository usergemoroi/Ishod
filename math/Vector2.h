#ifndef LIBX_VECTOR2_H
#define LIBX_VECTOR2_H

#include <cmath>

class Vector2 {
public:
    float x, y;
    
    // Constructors
    Vector2() : x(0.0f), y(0.0f) {}
    Vector2(float x, float y) : x(x), y(y) {}
    Vector2(float x) : x(x), y(x) {}
    
    // Operators
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }
    
    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }
    
    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }
    
    Vector2 operator/(float scalar) const {
        return Vector2(x / scalar, y / scalar);
    }
    
    Vector2& operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    
    Vector2& operator-=(const Vector2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    
    Vector2& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    
    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }
    
    bool operator!=(const Vector2& other) const {
        return !(*this == other);
    }
    
    // Methods
    float Length() const {
        return sqrt(x * x + y * y);
    }
    
    float LengthSquared() const {
        return x * x + y * y;
    }
    
    float Distance(const Vector2& other) const {
        return (*this - other).Length();
    }
    
    Vector2 Normalize() const {
        float len = Length();
        if (len > 0.0f) {
            return Vector2(x / len, y / len);
        }
        return Vector2();
    }
    
    Vector2 Clamp(float min, float max) const {
        return Vector2(
            x < min ? min : (x > max ? max : x),
            y < min ? min : (y > max ? max : y)
        );
    }
    
    Vector2 Clamp(const Vector2& min, const Vector2& max) const {
        return Vector2(
            x < min.x ? min.x : (x > max.x ? max.x : x),
            y < min.y ? min.y : (y > max.y ? max.y : y)
        );
    }
    
    static Vector2 Lerp(const Vector2& a, const Vector2& b, float t) {
        return Vector2(
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t
        );
    }
    
    static float Dot(const Vector2& a, const Vector2& b) {
        return a.x * b.x + a.y * b.y;
    }
    
    // Utility
    void Zero() {
        x = y = 0.0f;
    }
    
    bool IsZero() const {
        return x == 0.0f && y == 0.0f;
    }
    
    std::string ToString() const {
        return "Vector2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

#endif // LIBX_VECTOR2_H