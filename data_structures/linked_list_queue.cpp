#include "linked_list.cpp"
#include "queue.cpp"

template <typename T>
class LinkedListQueue : public Queue<T> {
private:
    LinkedList<T> data;
    
public:
    LinkedListQueue() : data() {}
    
    LinkedListQueue(size_t length, T * array) : data(length, array) {}
    
    T dequeue() {
        if (data.len() > 0) {
            return data.remove(0);
        }
        return (T) NULL;
    }

    void enqueue(T value) {
        data.append(value);
    }

    T peek() {
        return data.get(data.len());
    }

    bool is_empty() {
        return data.len() == 0;
    }

    size_t len() {
        return data.len();
    }

    void print() {
        data.print();
    }
};
