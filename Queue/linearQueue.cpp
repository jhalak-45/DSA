#include <iostream>
using namespace std;

#define SIZE 5  // Define the size of the queue

class LinearQueue {
private:
    int front, rear;
    int items[SIZE];

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if (rear == SIZE - 1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1 || front > rear) {
            return true;
        }
        return false;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full"<<endl;
            return;
        }
        if (front == -1) front = 0;
        items[++rear] = element;
        cout << "Inserted " << element << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        cout << "Deleted " << items[front++] << endl;
        if (front > rear) {
            front = rear = -1;  // Reset the queue if it's empty
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        cout << "Front -> " << front << endl;
        cout << "Items -> "<<endl;
        for (int i = front; i <= rear; i++)
            cout << items[i] << " "<<endl;
        cout << endl;
        cout << "Rear -> " << rear << endl;
    }
};

int main() {
    LinearQueue q;
    int choice, value;
    while (true) {
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: "<<endl;
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice"<<endl;
        }
    }
    return 0;
}
