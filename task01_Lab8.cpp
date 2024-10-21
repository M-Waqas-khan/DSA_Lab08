#include <iostream>
#include <string>
using namespace std;
class student {
    int reg_no;
    string st_name;
    float cgpa;
public:
    student() {}
    void input() {
        cout << "Enter Registration Number: ";
        cin >> reg_no;
        cout << "Enter Name: ";
        cin >> st_name;
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }
    void output() {
        cout << "Registration Number: " << reg_no << ", Name: " << st_name << ", CGPA: " << cgpa << endl;
    }
};
class Stack {
    student* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new student[size];
        capacity = size;
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(student s) {
        if (top == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = s;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        arr[top--].output();
    }
    bool isEmpty() {
        return top == -1;
    }
};
int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    Stack s(size);
    int choice;
    while (true) {
        cout << "1. Push student\n2. Pop student\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            student s1;
            s1.input();
            s.push(s1);
            break;
        }
        case 2:
            s.pop();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
