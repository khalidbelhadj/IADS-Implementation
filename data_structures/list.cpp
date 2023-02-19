#include <stdlib.h>
#include <iostream>

template <typename T>
class List {
private:
    size_t length;
    
public:
    virtual size_t len() = 0;

    virtual T get(size_t index) = 0;

    virtual void set(size_t index, T value) = 0;
    
    virtual void insert(size_t index, T value) = 0;

    virtual T remove(size_t index) = 0;

    virtual void print() = 0;

    void concat(T value) {
        insert(0, value);
    }

    void append(T value) {

        size_t index = len() > 0 ? len() - 1 : 0;
        T last_value = len() > 0 ? get(index) : (T) NULL;

        insert(index, last_value);
        if (len() == 1) {
            set(0, value);
        } else {
            set(index + 1, value);
        }
    }

    bool is_empty() {
        return len() == 0;
    }
};
