#pragma once

template<typename T>
class FixedVector {
    private:
        T* data;
        int size;
    public:
        FixedVector(int size) {
            data = new T[size];
            this->size = size;
        }
        ~FixedVector() {
            delete [] data;
        }
        T& operator[](int i) {
            return data[i];
        }
        const T& operator[](int i) const {
            return data[i];
        }
        int getSize() const {
            return size;
        }
        T* begin() {
            return data;
        }
        T* end() {
            return data + size;
        }
        const T* begin() const {
            return data;
        }
        const T* end() const {
            return data + size;
        }
};