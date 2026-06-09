#pragma once

#include <stdint.h>

class BitArrayProxy {
    private:
        uint8_t* data;
        int index;
    public:
        BitArrayProxy(uint8_t* data, int index)
        : data(data)
        , index(index) {}
        operator bool() const {
            return ((1 << (index % 8)) & data[index/8]);
        }
        BitArrayProxy& operator=(bool b) {
            if (b) {
                data[index/8] |= (1 << (index%8));
            }
            else {
                data[index/8] &= ~(1 << (index%8));
            }
            return *this;
        }
};

class BitArray {
    private:
        int size;
        uint8_t* data;
    public:
        BitArray(int size) {
            this->size = size;
            this->data = new uint8_t[size]();
        }
        ~BitArray() {
            delete [] data;
        }
        BitArrayProxy operator[](int index) {
            return BitArrayProxy(data, index);
        }

};