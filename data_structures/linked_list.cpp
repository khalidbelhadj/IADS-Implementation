#include "list.cpp"

#define OUT_OF_BOUNDS(index, length) std::cout << "Index " << (int) index << " out of bounds for length " << length << std::endl

template <typename T>
struct Node {
    T value;
    Node * prev;
    Node * next;
};

template <typename T>
class LinkedList : public List<T> {
private:
    Node<T> * get_node(size_t index) {
        size_t current_index = 0;
        Node<T> * current = head;
        
        while (current != NULL && current_index != index) {
            current_index += 1;
            current = current->next;
        }

        return current;
    }
    
public:
    Node<T> * head;

    LinkedList() : head(NULL) {}
    
    LinkedList(size_t l, T * array) : head(NULL){
        for (int i = l - 1; i >= 0; --i) {
            insert(0, array[i]);
        }
    }
    
    size_t len() {
        Node<T> * current = head;
        size_t l = 0;
        while (current != NULL) {
            l += 1;
            current = current->next;
        }
        return l;
    }

    T get(size_t index) {
        Node<T> * current = get_node(index);
        
        if (current == NULL) {
            OUT_OF_BOUNDS(index, len());
            return (T) NULL;
        }
        return current->value;
    }

    void set(size_t index, T value) {
        Node<T> * node = get_node(index);

        if (node == NULL) {
            OUT_OF_BOUNDS(index, len());
            return;
        }

        node->value = value;
    }

    void insert(size_t index, T value) {
        Node<T> * current = get_node(index);
        Node<T> * new_current = new Node<T>();

        if (current == NULL) {
            if (index == 0 && len() == 0) {
                
                // List has no elements
                
                new_current->next = NULL;
                new_current->prev = NULL;
                new_current->value = value;
                
                head = new_current;

                return;
            }

            // Index out of bounds

            OUT_OF_BOUNDS(index, len());

            delete new_current;
            return;
        }
            
        new_current->next = current;
        new_current->prev = current->prev;
        new_current->value = value;

        if (current->prev != NULL) {
            current->prev->next = new_current;
        } else {
            head = new_current;
        }
        
        current->prev = new_current;
    }

    T remove(size_t index) {
        Node<T> * current = get_node(index);

        if (current == NULL) {

            // Index out of bounds or empty list

            OUT_OF_BOUNDS(index, len());
            return (T) NULL;
        }
        
        T value = current->value;

        if (current->prev == NULL && current->next == NULL) {
            head = NULL;
            delete current;
            return value;
        }
        
        // At most one is null
        
        if (current->prev == NULL) {
            
            // Only prev is null; first element
            
            current->next->prev = NULL;
            head = current->next;
            delete current;
            return value;
        }

        if (current->next == NULL) {

            // Only next is null; last element
            
            current->prev->next = NULL;
            delete current;
            return value;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;
        return value;
    }
    
    void print() {
        Node<T> * current = head;
        
        std::cout << "[";
        
        while (current != NULL) {
            std::cout << current->value;
            if (current->next != NULL) {
                std::cout << ", ";
            }
            current = current->next;
        }

        std::cout << "]\n";
        
        
    }
};
