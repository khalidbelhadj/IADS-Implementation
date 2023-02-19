#include "linked_list.cpp"

template <typename T>
class Stack {
private:
    LinkedList<T> data;
    
public:
    Stack() : data() {}
    
    Stack(size_t length, T * array) : data(length, array) {}
    
    T pop() {
        if (data.len() > 0) {
            return data.remove(data.len() - 1);
        }
        return (T) NULL;
    }

    void push(T value) {
        data.append(value);
    }

    T peek() {
        return data.get(data.len());
    }

    bool is_empty() {
        return data.len() == 0;
    }

    void print() {
        data.print();
    }
};
