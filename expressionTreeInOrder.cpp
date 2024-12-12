// Construct an Expression Tree from postfix and prefix expression. Perform recursive and non- recursive In-order traversals.

#include <iostream>

using namespace std;

// Node structure for the expression tree
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Stack node structure for the linked list
struct StackNode {
    Node* treeNode;
    StackNode* next;
};

// Stack structure using linked list
struct Stack {
    StackNode* top;
};

// Function to initialize the stack
void initStack(Stack& stack) {
    stack.top = nullptr;
}

// Function to push an element onto the stack
void push(Stack& stack, Node* treeNode) {
    StackNode* newNode = new StackNode();
    newNode->treeNode = treeNode;
    newNode->next = stack.top;
    stack.top = newNode;
}

// Function to pop an element from the stack
Node* pop(Stack& stack) {
    if (stack.top == nullptr) {
        cout << "Stack underflow" << endl;
        return nullptr;
    }
    Node* treeNode = stack.top->treeNode;
    StackNode* temp = stack.top;
    stack.top = stack.top->next;
    delete temp;
    return treeNode;
}

// Function to check if the stack is empty
bool isEmpty(Stack& stack) {
    return stack.top == nullptr;
}

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to construct an expression tree from postfix expression
Node* constructTreeFromPostfix(const char* postfix) {
    Stack stack;
    initStack(stack);
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        Node* newNode = createNode(c);
        if (isalpha(c) || isdigit(c)) {
            push(stack, newNode);
        } else {
            newNode->right = pop(stack);
            newNode->left = pop(stack);
            push(stack, newNode);
        }
    }
    return pop(stack);
}

// Function to construct an expression tree from prefix expression
Node* constructTreeFromPrefix(const char* prefix) {
    Stack stack;
    initStack(stack);
    int n = 0;
    while (prefix[n] != '\0') n++;
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];
        Node* newNode = createNode(c);
        if (isalpha(c) || isdigit(c)) {
            push(stack, newNode);
        } else {
            newNode->left = pop(stack);
            newNode->right = pop(stack);
            push(stack, newNode);
        }
    }
    return pop(stack);
}

// Recursive in-order traversal
void recursiveInOrder(Node* root) {
    if (root != nullptr) {
        recursiveInOrder(root->left);
        cout << root->data << " ";
        recursiveInOrder(root->right);
    }
}

// Non-recursive in-order traversal
void nonRecursiveInOrder(Node* root) {
    Stack stack;
    initStack(stack);
    Node* current = root;
    while (current != nullptr || !isEmpty(stack)) {
        while (current != nullptr) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        cout << current->data << " ";
        current = current->right;
    }
}

int main() {
    const char* postfix = "ab+cde+**";
    const char* prefix = "*+abc*de";

    Node* rootPostfix = constructTreeFromPostfix(postfix);
    Node* rootPrefix = constructTreeFromPrefix(prefix);

    cout << "Recursive In-order traversal of tree constructed from postfix: ";
    recursiveInOrder(rootPostfix);
    cout << endl;

    cout << "Non-recursive In-order traversal of tree constructed from postfix: ";
    nonRecursiveInOrder(rootPostfix);
    cout << endl;

    cout << "Recursive In-order traversal of tree constructed from prefix: ";
    recursiveInOrder(rootPrefix);
    cout << endl;

    cout << "Non-recursive In-order traversal of tree constructed from prefix: ";
    nonRecursiveInOrder(rootPrefix);
    cout << endl;

    return 0;
}