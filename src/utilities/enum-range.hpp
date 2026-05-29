#pragma once

template<typename Enum>
class EnumRange {
    public:
        class Iterator {
            private:
                int it;
            public:
                Iterator(int it)
                : it(it) {}
                Enum operator*() const {
                    return (Enum)it;
                }
                Iterator& operator++() {
                    ++it;
                    return *this;
                }
                bool operator!=(const Iterator& other) const {
                    return (this->it != other.it);
                }

        };
        Iterator begin() {
            return Iterator(0);
        }
        Iterator end() {
            return Iterator((int)Enum::COUNT);
        }
};