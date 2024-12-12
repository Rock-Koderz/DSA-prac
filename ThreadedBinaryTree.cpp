// Implement In-order Threaded Binary Tree and traverse it in In-order and Pre-order.

#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    bool leftThread;
    bool rightThread;
};

class ThreadedBinaryTree {
private:
    node *root;

    node* leftMost(node* n) {
        if (n == nullptr) return nullptr;
        while (n->left != nullptr && !n->leftThread) {
            n = n->left;
        }
        return n;
    }

public:
    ThreadedBinaryTree() : root(nullptr) {}

    void insert(int key) {
        node* newNode = new node();
        newNode->data = key;
        newNode->left = newNode->right = nullptr;
        newNode->leftThread = newNode->rightThread = true;

        if (root == nullptr) {
            root = newNode;
            return;
        }

        node* current = root;
        node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (key < current->data) {
                if (!current->leftThread) {
                    current = current->left;
                } else {
                    break;
                }
            } else {
                if (!current->rightThread) {
                    current = current->right;
                } else {
                    break;
                }
            }
        }

        if (key < parent->data) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->leftThread = false;
            parent->left = newNode;
        } else {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->rightThread = false;
            parent->right = newNode;
        }
    }

    void inOrder() {
        node* current = leftMost(root);
        while (current != nullptr) {
            cout << current->data << " ";
            if (current->rightThread) {
                current = current->right;
            } else {
                current = leftMost(current->right);
            }
        }
        cout << endl;
    }

    void preOrder() {
        node* current = root;
        while (current != nullptr) {
            cout << current->data << " ";
            if (!current->leftThread) {
                current = current->left;
            } else if (!current->rightThread) {
                current = current->right;
            } else {
                while (current != nullptr && current->rightThread) {
                    current = current->right;
                }
                if (current != nullptr) {
                    current = current->right;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    ThreadedBinaryTree tbt;
    tbt.insert(20);
    tbt.insert(10);
    tbt.insert(30);
    tbt.insert(5);
    tbt.insert(16);
    tbt.insert(25);
    tbt.insert(35);

    cout << "In-order Traversal: ";
    tbt.inOrder();

    cout << "Pre-order Traversal: ";
    tbt.preOrder();

    return 0;
}