#pragma once

template<typename T>
class Queue {
    private:
        int size;
        int num_elements = 0;
        T* data;

    public:
        Queue(int size) {
            this->size = size;

            data = new T[size];
        };
        void push(T element) {
            if (num_elements == size) return;
            data[num_elements++] = element;
        }
        void flush() {
            num_elements = 0;
        }

        T* begin() {
            return data;
        }
        T* end() {
            return data + num_elements;
        }
};