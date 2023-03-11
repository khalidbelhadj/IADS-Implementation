#pragma once

#include "array.cpp"
#include "queue.cpp"

template <typename T>
class CircularQueue {
private:
    Array<T> data;
    size_t capacity;
    int head;
    int tail;

public:
    CircularQueue(size_t c) : data(c), capacity(c), head(0), tail(-1) {}

    T dequeue() {
        if (is_empty()) {
            return (T)NULL;
        }

        if (len() == 1) {
            tail = -1;
        }

        T value = data.get(head);
        data.set(head, (T)NULL);
        head = (head + 1) % capacity;

        return value;
    }

    void enqueue(T value) {
        if (is_full()) {
            std::cout << "Queue is at full for capacity " << capacity << " \n";
            return;
        }

        if (is_empty()) tail = 0;

        data.set(tail, value);
        tail = (tail + 1) % (capacity);
    }

    T peek() { return NULL; }

    bool is_empty() { return tail == -1; }

    bool is_full() { return tail == head; }

    size_t len() { return head >= tail ? capacity - head + tail : tail - head; }

    void print() {
        std::cout << "[";
        if (!is_empty()) {
            for (size_t i = 0; i < len(); ++i) {
                std::cout << data.get((head + i) % capacity);
                if (i != len() - 1) {
                    std::cout << ", ";
                }
            }
        }
        std::cout << "]" << std::endl;
    }
};
