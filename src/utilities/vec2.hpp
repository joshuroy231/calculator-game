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
        T getComponent(Component component) {
            if (component == X) return this->x;
            else return this->y;
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
};