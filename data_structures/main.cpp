#include <iostream>
#include "array.cpp"
#include <string>


#include "circular_queue.cpp"
#include "linked_list_queue.cpp"

int main() {
    CircularQueue<std::string> xs(4);

    char x[5];
    x[0] = 'a';
    x[1] = 'b';
    x[2] = 'c';
    char y[5];
    y[0] = 'd';
    y[1] = 'e';
    y[2] = 'f';

    xs.enqueue(x);
    xs.print();

    xs.dequeue();
    xs.print();
    
    xs.dequeue();
    xs.print();

    xs.dequeue();
    xs.print();
    
    xs.dequeue();
    xs.print();
    
    xs.dequeue();
    xs.print();
    
    return 0;
}
