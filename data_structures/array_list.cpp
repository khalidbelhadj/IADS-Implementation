#pragma once

#include "array.cpp"
#include "list.cpp"

#define INIT_CAPACITY 10

template <typename T>
class ArrayList : public List<T> {
private:
    Array<T> data;
    size_t capacity;
    size_t length;
    float ratio;

    void grow() {
        capacity = (int)(capacity * ratio);
        Array<T> new_data(capacity);

        for (int i = 0; i < data.len(); ++i) {
            new_data.set(i, data.get(i));
        }

        data = new_data;
    }

    void shrink() {
        capacity = (int)(capacity / ratio);
        Array<T> new_data(capacity);

        for (int i = 0; i < data.len(); ++i) {
            new_data.set(i, data.get(i));
        }

        data = new_data;
    }

public:
    ArrayList()
        : data(INIT_CAPACITY),
          capacity(INIT_CAPACITY),
          length(0),
          ratio(1.5) {}

    ArrayList(size_t l, T* array)
        : length(INIT_CAPACITY > l ? INIT_CAPACITY : l),
          capacity(l),
          data(length, array) {}

    size_t len() { return length; }

    T get(size_t index) {
        if (is_valid_index(index, length)) {
            return data.get(index);
        }
        return (T)NULL;
    }

    void set(size_t index, T value) {
        if (is_valid_index(index, length)) {
            data.set(index, value);
            return;
        }
    }

    void insert(size_t index, T value) {
        if ((index != 0 || length != 0) && !is_valid_index(index, length)) {
            return;
        }

        Array<T> tmp(length - index);

        for (int i = index; i < length; ++i) {
            tmp.set(i - index, data.get(i));
        }

        data.set(index, value);

        length += 1;

        if (length >= capacity) {
            grow();
        }

        for (int i = index + 1; i < length; ++i) {
            data.set(i, tmp.get(i - index - 1));
        }
    }

    T remove(size_t index) {
        if (!is_valid_index(index, length)) {
            return (T)NULL;
        }

        Array<T> tmp(length - index - 1);

        for (int i = index + 1; i < length; ++i) {
            tmp.set(i - index - 1, data.get(i));
        }

        T value = get(index);
        length -= 1;

        for (int i = index; i < length; ++i) {
            data.set(i, tmp.get(i - index));
        }

        if ((int)(ratio * length) < capacity &&
            (int)(ratio * length) > INIT_CAPACITY) {
            shrink();
        }

        return value;
    }

    void print() {
        std::cout << "[";
        for (size_t i = 0; i < length; ++i) {
            if (i == length - 1) {
                std::cout << data.get(i) << "";
            } else {
                std::cout << data.get(i) << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};
