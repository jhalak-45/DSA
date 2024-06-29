#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Nothing to pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped " << temp->data << endl;
        delete temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Nothing to dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        cout << "Dequeued " << temp->data << endl;
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    Queue queue;
    int choice, value;

    while (true) {
        cout<<"----------Stack Operations------------"<<endl;
        cout << "1. Push"<<endl;
        cout << "2. Pop"<<endl;
        cout << "3. Display"<<endl;
        cout<<"----------Queue Operations------------"<<endl;
        cout << "4. Enqueue"<<endl;
        cout << "5. Dequeue"<<endl;
        cout << "6. Display "<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 5:
                queue.dequeue();
                break;
            case 6:
                queue.display();
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
