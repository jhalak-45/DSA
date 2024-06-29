#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int size;

public:
    Stack(int s) {
        arr = new int[s];
        size = s;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1; // Returning -1 to indicate underflow
        }
        return arr[top--];
    }


     bool isEmpty() {
        return top == -1;
    }

    bool isFull(){
        return top == size - 1;
    }

    void display(){
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return;
        }
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    Stack stack(size);

    int choice, value;

    while (true) {
        cout << "----------Menu:----------"<<endl;
        cout << "1. Push"<<endl;
        cout << "2. Pop"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            value = stack.pop();
            if (value != -1) {
                cout << "Popped value: " << value << endl;
            }
            break;
        case 3:
            cout << "Stack elements are: ";
            stack.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
