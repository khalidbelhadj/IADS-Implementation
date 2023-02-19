#include <iostream>
#include "array.cpp"

// #define CIRC

#ifdef CIRC
#include "wrap_queue.cpp"
#else
#include "linked_list_queue.cpp"
#endif

int main() {
    Array<int> a(20);
    a.print();
    return 0; 
}


int main3() {
#ifdef CIRC
    CircularQueue<int> xs(4);
#else
    LinkedListQueue<int> xs;
#endif
    
    xs.enqueue(69);
    xs.print();
    
    xs.enqueue(420);
    xs.print();
    
    xs.enqueue(34);
    xs.print();
    
    xs.enqueue(45);
    xs.print();
    
    xs.dequeue();
    xs.print();
    
    xs.dequeue();
    xs.print();
    
    xs.dequeue();
    xs.print();
    
    xs.enqueue(898);
    xs.print();

    xs.dequeue();
    xs.print();
    
    xs.dequeue();
    xs.print();
    
    xs.dequeue();
    xs.print();
    return 0;
}
