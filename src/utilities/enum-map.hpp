#pragma once

template<typename Enum, typename T>
class EnumMap {
    private:
        T data[(int)Enum::COUNT];
    public:
        T& operator[](Enum e) {
            return data[(int)e];
        }
        const T& operator[](Enum e) const {
            return data[(int)e];
        }
        T* begin() {
            return data;
        }
        T* end() {
            return data + (int)Enum::COUNT;
        }
        const T* begin() const {
            return data;
        }
        const T* end() const {
            return data + (int)Enum::COUNT;
        }
};