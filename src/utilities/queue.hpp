#pragma once

#include <debug.h>

template<typename T>
class Queue {
    private:
        int size;
        int num_elements;
        T* data;

    public:
        Queue(int size) {
            this->size = size;

            num_elements = 0;
            data = new T[size];
        };
        ~Queue() {
            dbg_printf("Destructing queue\n");
            delete [] data;
            dbg_printf("Destructed queue\n");
        }
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