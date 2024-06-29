#include <iostream>
using namespace std;
const int MAX_SIZE = 100; // Maximum size

int stack[MAX_SIZE];
int top = -1; 

void push(int value) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack is full. Cannot push." <<endl;
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        cout << "Stack is empty!" <<endl;
    }
    return stack[top--];
}

void display() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements:" <<endl;
    for (int i = top; i >= 0; --i) {
        cout << stack[i] << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "1. Push operation  "<<endl;
        cout << "2. Pop operation  "<<endl;
        cout << "3. Display "<<endl;
        cout << "4. Exit "<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    cout << "Popped value: " << value <<endl;
                }
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}