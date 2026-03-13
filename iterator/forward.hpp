#include <iterator>

template <typename T, typename Node>
class iterator {
public:
    iterator(Node* ptr) : current(ptr) {}
    
    T& operator*() const {
        return current->data;
    }

    T* operator->() const {
        return &(current->data);
    }

    bool operator!=(const iterator& other) const {
        return current != other.current;
    }

    bool operator==(const iterator& other) const {
        return current == other.current;
    }

    iterator& operator++() {
        current = current->next;
        return *this;
    }

    iterator operator++(int) {
        iterator temp = *this;
        current = current->next;
        return temp;
    }

private:
    Node* current;
};