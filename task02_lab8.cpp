#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    int id;
    string name;
    int age;

public:
    Person(int id, const string& name, int age) : id(id), name(name), age(age) {}
    
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
    }
};

class Node {
public:
    Person data;
    Node* next;
    Node(const Person& person) : data(person), next(nullptr) {}
};

class Queue {
private:
    Node* front = nullptr;
    Node* rear = nullptr;

public:
    void add(const Person& person) {
        Node* newNode = new Node(person);
        if (!rear) front = newNode;
        else rear->next = newNode;
        rear = newNode;
    }

    void remove() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr; // If queue is now empty
        temp->data.display();
        delete temp;
    }

    bool isEmpty() const { return front == nullptr; }
};

int main() {
    Queue queue;
    int id, age;
    string name;

    while (true) {
        cout << "Enter ID (-1 to exit): ";
        cin >> id;
        if (id == -1) break;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;

        queue.add(Person(id, name, age));
    }

    cout << "Removing persons from queue:" << endl;
    while (!queue.isEmpty()) {
        queue.remove();
    }

    return 0;
}
