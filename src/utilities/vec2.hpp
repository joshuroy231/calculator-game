#pragma once

enum class Component {
    X,
    Y
};

template <typename T>
class Vec2 {
    public:
        T x;
        T y;
        Vec2() = default;
        Vec2(T x, T y)
        : x(x)
        , y(y) {}
        T& operator[](Component c) {
            return (c == Component::X) ? x : y;
        }
        const T& operator[](Component c) const {
            return (c == Component::X) ? x : y;
        }
        Vec2 operator+(const Vec2& other) const {
            return Vec2(
                this->x + other.x,
                this->y + other.y
            );
        }
        Vec2 operator-(const Vec2& other) const {
            return Vec2(
                this->x - other.x,
                this->y - other.y
            );
        }
        Vec2& operator+=(const Vec2& other) {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }
        Vec2& operator-=(const Vec2& other) {
            this->x -= other.x;
            this->y -= other.y;
            return *this;
        }
        bool operator==(const Vec2& other) const {
            return (this->x == other.x && this->y == other.y);
        }
        bool operator!=(const Vec2& other) const {
            return (this->x != other.x || this->y != other.y);
        }
        template<typename S>
        Vec2 operator*(const S other) const {
            return Vec2(
                this->x * other,
                this->y * other
            );
        }
        template<typename S>
        Vec2 operator/(const S other) const {
            return Vec2(
                this->x / other,
                this->y / other
            );
        }
};