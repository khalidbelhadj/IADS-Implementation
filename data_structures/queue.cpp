#pragma once

#include <stdlib.h>

#include <iostream>

template <typename T>
class Queue {
public:
    virtual T dequeue() = 0;

    virtual void enqueue(T value) = 0;

    virtual T peek() = 0;

    virtual bool is_empty() = 0;

    virtual size_t len() = 0;

    virtual void print() = 0;
};
