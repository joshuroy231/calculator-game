template <typename T>
class Vec2 {
    public:
        T x;
        T y;
        Vec2(T x, T y)
        : x(x)
        , y(y) {}
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