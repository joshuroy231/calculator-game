#pragma once

enum Component {
    X,
    Y
};

template <typename T>
class Vec2 {
    public:
        T x = 0;
        T y = 0;
        Vec2() = default;
        Vec2(T x, T y)
        : x(x)
        , y(y) {}
        T getComponent(Component component) const {
            if (component == X) return this->x;
            else return this->y;
        }
        void setComponent(Component component, T value) {
            if (component == X) this->x = value;
            else this->y = value;
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