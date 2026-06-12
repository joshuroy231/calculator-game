#pragma once

template<typename T>
class MatrixRow {
    private:
        T* data;
    public:
        MatrixRow(T* data)
        : data(data) {}
        T& operator[](int i) {
            return data[i];
        }
        const T& operator[](int i) const {
            return data[i];
        }
};

template<typename T>
class Matrix {
    private:
        int width;
        int height;
        T* data;
    public:
        Matrix(int width, int height) {
            this->width = width;
            this->height = height;
            data = new T[width*height];
        }
        ~Matrix() {
            delete [] data;
        }
        MatrixRow<T> operator[](int i) {
            return MatrixRow<T>(data + i*width);
        }
        const MatrixRow<T> operator[](int i) const {
            return MatrixRow<T>(data + i*width);
        }
};