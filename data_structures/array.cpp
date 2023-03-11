#pragma once

#include <stdlib.h>

#include <iostream>

bool is_valid_index(size_t index, size_t length) {
    if (index < 0 || index >= length) {
        std::cout << "Index " << (int)index << " out of bounds for length "
                  << length << std::endl;
        return false;
    }
    return true;
}

template <typename T>
class Array {
private:
    size_t length;
    T *data;

public:
    Array(size_t l) : length(l), data(new T[l]) {}

    ~Array() { delete[] data; }

    Array(size_t l, T *array) : length(l), data(new T[length]) {
        memcpy(data, array, sizeof(T) * length);
    }

    size_t len() { return length; }

    bool set(size_t index, T value) {
        if (is_valid_index(index, length)) {
            data[index] = value;
            return true;
        }
        return false;
    }

    T get(size_t index) {
        if (is_valid_index(index, length)) {
            return data[index];
        }
        return (T)NULL;
    }

    void print() {
        std::cout << "[";
        for (size_t i = 0; i < length; ++i) {
            std::cout << get(i);
            if (i != length - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};
