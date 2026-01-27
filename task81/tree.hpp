#include <vector>
#include <iostream>
#include "queue.hpp"

template<typename T>
class Tree {
public:
    struct Node {
        T value;
        Node* left;
        Node* right;

        explicit Node(const T& val) : value(val), left(nullptr), right(nullptr) {}
        explicit Node(T&& val) : value(std::move(val)), left(nullptr), right(nullptr) {}
    }

    Node* root;

    static void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    explicit Tree() : root(nullptr) {}

    void insert(const T& value) {
        if (!root) {
            root = new Node(value);
            return;
        }

        Queue<Node*> q;
        q.enqueue(root);

        while (!q.empty()) {
            Node* current = q.dequeue();

            if (!current->left) {
                current->left = new Node(value);
                return;
            } else {
                q.enqueue(current->left);
            }

            if (!current->right) {
                current->right = new Node(value);
                return;
            } else {
                q.enqueue(current->right);
            }
        }
    }

    ~Tree() {
        destroy(root);
    }
};