#pragma once

template<typename Enum, typename T>
class EnumMap {
    private:
        T data[(int)Enum::SIZE];
    public:
        T& operator[](Enum e) {
            return data[(int)e];
        }
        const T& operator[](Enum e) const {
            return data[(int)e];
        }
};