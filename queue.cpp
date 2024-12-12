// Implement Circular Queue using Circular Linked List. Perform following operations on it. 
// a) Insertion (Enqueue) 
// b) Deletion (Dequeue) 
// c) Display 

#include <iostream>

using namespace std;

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
};

// Circular Queue structure using circular linked list
struct CircularQueue {
    Node* front;
    Node* rear;
};

// Function to initialize the circular queue
void initQueue(CircularQueue& queue) {
    queue.front = queue.rear = nullptr;
}

// Function to check if the queue is empty
bool isEmpty(CircularQueue& queue) {
    return queue.front == nullptr;
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQueue& queue, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (isEmpty(queue)) {
        queue.front = queue.rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = queue.front;
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
}

// Function to dequeue an element from the circular queue
int dequeue(CircularQueue& queue) {
    if (isEmpty(queue)) {
        cout << "Queue underflow" << endl;
        return -1;
    }
    int value;
    if (queue.front == queue.rear) {
        value = queue.front->data;
        delete queue.front;
        queue.front = queue.rear = nullptr;
    } else {
        Node* temp = queue.front;
        value = temp->data;
        queue.front = queue.front->next;
        queue.rear->next = queue.front;
        delete temp;
    }
    return value;
}

// Function to display the elements of the circular queue
void display(CircularQueue& queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = queue.front;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != queue.front);
    cout << endl;
}

int main() {
    CircularQueue queue;
    initQueue(queue);

    int choice, value;
    while (true) {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    cout << "Dequeued value: " << value << endl;
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}