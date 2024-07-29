#include <iostream>
using namespace std;

#define SIZE 5  // Define the size of the queue

// Global variables
int queue[SIZE];
int front = 0;
int rear = -1;
int total = 0; // Number of elements in the queue

// Function to enqueue an element into the circular queue
void enqueue(int element) {
    if (total == SIZE) {  // Queue is full
        cout << "Queue is full" << endl;
        return;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = element;
    total++;
    cout << "Inserted " << element << endl;
}

// Function to dequeue an element from the circular queue
void dequeue() {
    if (total == 0) {  // Queue is empty
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Deleted " << queue[front] << endl;
    front = (front + 1) % SIZE;
    total--;
}

// Function to display the contents of the circular queue
void display() {
    if (total == 0) {  // Queue is empty
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue -> ";
    for (int i = 0; i < total; i++) {
        cout << queue[(front + i) % SIZE] << " ";
    }
    cout << endl;
}

int main() {
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
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
