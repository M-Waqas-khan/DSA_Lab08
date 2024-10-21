#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class Queue {
    Node* front;
    Node* rear;
    int size;
    int maxSize;
public:
    Queue(int maxSize) {
        front = rear = nullptr;
        size = 0;
        this->maxSize = maxSize;
    }
    void enqueue(int value) {
        if (size == maxSize) {
            cout << "Queue overflow" << endl;
            return;
        }
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            size++;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        size++;
    }
    void dequeue() {
        if (size == 0) {
            cout << "Queue underflow" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        size--;
    }
    int getFront() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Queue q1(5);
    Queue q2(5);
    int choice, value;
    while (true) {
        cout << "1. Insert in Queue 1\n2. Remove from Queue 1\n3. Remove from Queue 2\n4. Display Queues\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            if (q1.getFront() != -1) {
                value = q1.getFront();
                q1.dequeue();
                q2.enqueue(value);
            }
            break;
        case 3:
            q2.dequeue();
            break;
        case 4:
            cout << "Queue 1: ";
            q1.display();
            cout << "Queue 2: ";
            q2.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
